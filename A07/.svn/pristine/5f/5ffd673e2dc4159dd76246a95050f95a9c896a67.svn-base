#include <iostream>
#include <string>
#include <cmath>
#include "TF1.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"
using namespace std;
#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"
#include "FCmatrixBanded.hpp"
#include "EqSolver.hpp"
#include "DataPoints.hpp"
#include "Spline3Interpolator.hpp"

Spline3Interpolator::Spline3Interpolator(int N, double *x, double *y, TF1* fF0) : DataPoints(N,x,y)
{
  FInterpolator = new TF1("FInterpolator", this, &Spline3Interpolator::fInterpolator, x[0]-0.001 ,x[N-1]+0.001, 0);
  if (fF0!=NULL){
      F0 = (TF1*)fF0->Clone();
    } else{
      F0 = NULL;
    }
  K = new double[N];
  SetCurvatureLines();
}

double Spline3Interpolator::Interpolate(double xval) //retorna o valor da funcao interpoladora na abcissa x
{
  double result = 0;
  for(int i = 0;i<N-1;i++)
  {
    if (xval>=x[i] && xval<=x[i+1])
    {
      result= (K[i]/6.0)*((pow(xval-x[i+1],3)/(x[i]-x[i+1]))-((xval-x[i+1])*(x[i]-x[i+1])))-
      (K[i+1]/6.0)*(((pow(xval-x[i],3)/(x[i]-x[i+1]))-((xval-x[i])*(x[i]-x[i+1]))))+
      (y[i]*(xval-x[i+1])-y[i+1]*(xval-x[i]))/(x[i]-x[i+1]); // result = y = f(x)
    }
  }
  return result;
}

void Spline3Interpolator::Draw(const char* title,const char* x_axis, const char* y_axis, Int_t npx, int option)
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
  TGraph* gr = NULL;
  if(option)
  {
    gr = new TGraph(N,x,y);
    gr->SetMarkerColor(4);
    gr->SetMarkerSize(1.5);
    gr->SetMarkerStyle(8);
    gr->Draw("PSAME"); //DRAW points on top of curve
  }

  c1->Update();
  gPad->WaitPrimitive();

  delete c1;
  delete gr;
  Nplots++;
}

void Spline3Interpolator::Print(const char* filename,const char* title,const char* x_axis, const char* y_axis, Int_t npx)
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

void Spline3Interpolator::SetCurvatureLines()
{
  Vec _lower(N-3);
  Vec _main(N-2);
  Vec _upper(N-3);
  _main[0]=2*(x[0]-x[2]);
  for(int i=0; i<N-3;i++)
  {
      _lower[i]=x[i+1]-x[i+2];
      _main[i+1]=2*(x[i+1]-x[i+3]);
      _upper[i]=x[i+2]-x[i+3];
  }
	FCmatrixBanded Tri_mat(_lower,_main,_upper);

  Vec tri_b(N-2);
  for(int i =0; i<N-2; i++)
  {
    tri_b[i]=6*( (y[i]-y[i+1])/(x[i]-x[i+1]) - (y[i+1]-y[i+2])/(x[i+1]-x[i+2]) );
  }
  // refazer abaixo, constrcutor no eqsolver pa banded!!!
  //FCmatrixFull _tofull = Tri_mat.GetFull();
  EqSolver banded(Tri_mat,tri_b);
  Vec aux = banded.TridiagonalSolver();
  K[0]=0;
  for(int i=1; i<N-1;i++)
  {
    K[i]=aux[i-1];
  }
  //cout << "K[1] = " << K[1] << endl;
  K[N-1]=0;
}
