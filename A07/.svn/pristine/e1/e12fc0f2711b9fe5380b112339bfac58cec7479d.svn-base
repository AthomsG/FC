#include <iostream>
#include <string>
#include "TF1.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"
using namespace std;
#include "DataPoints.hpp"
#include "NevilleInterpolator.hpp"

NevilleInterpolator::NevilleInterpolator(int N, double *x, double *y, TF1* fF0) : DataPoints(N,x,y)
{
  FInterpolator = new TF1("FInterpolator", this, &NevilleInterpolator::fInterpolator, x[0]-0.001 ,x[N-1]+0.001, 0);
  F0 = fF0;
}

double NevilleInterpolator::Interpolate(double xval) //retorna o valor da funcao interpoladora na abcissa x
{
  double*	yaux	=	new	double[N];
  for	(int	i=0;	i<N;	i++)
  {
    yaux[i]	=	y[i];	//	auxiliar	vector
  }
  for	(int	k=1;	k<N;	k++)
  {
    for	(int	i=0;	i<N-k;	i++)
    {
      yaux[i]	=	(	(xval-x[i+k])*yaux[i]	-	(xval-x[i])*yaux[i+1])	/	(x[i]-x[i+k]);
    }
  }
  //Last	value	calculated	is	yp[0]	when	k=N-1	and	i=0.....
  double	A	=	yaux[0];
  delete	[]	yaux;
  return	A;
}

void NevilleInterpolator::Draw(const char* title,const char* x_axis, const char* y_axis, Int_t npx)
{
  if(Nplots == 0)
  {
    TApplication*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);
  }

  TCanvas* c1 = new TCanvas("c1","new canvas",700,500);
  c1->SetFillColor(10); // white
  c1->SetGrid();

  FInterpolator->SetNpx(npx);
  FInterpolator->SetLineColor(kBlack);
  FInterpolator->SetLineWidth(2);
  FInterpolator->SetTitle(title);
  FInterpolator->GetXaxis()->SetTitle(x_axis);
  FInterpolator->GetYaxis()->SetTitle(y_axis);
  FInterpolator->Draw(); //DRAW

  if (F0!=NULL) {
      F0->SetLineStyle(2);
      F0->SetNpx(npx);
      F0->SetLineColor(kRed);
      F0->SetLineWidth(2);
      F0->Draw("SAME");
    }

  TGraph* gr = new TGraph(N,x,y);
  gr->SetMarkerColor(4);
  gr->SetMarkerSize(1.5);
  gr->SetMarkerStyle(8);
  gr->Draw("PSAME"); //DRAW points on top of curve

  c1->Update();
  gPad->WaitPrimitive();

  delete c1;
  delete gr;
  Nplots++;
}

void NevilleInterpolator::Print(const char* filename,const char* title,const char* x_axis, const char* y_axis, Int_t npx)
{
  TCanvas* c1 = new TCanvas("c1","new canvas");
  c1->SetFillColor(10); // white
  c1->SetGrid();

  FInterpolator->SetNpx(npx);
  FInterpolator->SetLineColor(kBlack);
  FInterpolator->SetLineWidth(2);
  FInterpolator->SetTitle(title);
  FInterpolator->GetXaxis()->SetTitle(x_axis);
  FInterpolator->GetYaxis()->SetTitle(y_axis);
  FInterpolator->Draw(); //DRAW

  if (F0!=NULL) {
      F0->SetLineStyle(2);
      F0->SetNpx(npx);
      F0->SetLineColor(kRed);
      F0->SetLineWidth(2);
      F0->Draw("SAME");
    }

  TGraph* gr = new TGraph(N,x,y);
  gr->SetMarkerColor(4);
  gr->SetMarkerSize(1.5);
  gr->SetMarkerStyle(8);
  gr->Draw("P"); //DRAW

  c1->Update();
  c1->Draw();
  c1->SaveAs(filename);

  delete c1;
  delete gr;
}
