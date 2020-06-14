#include <iostream>
#include <string>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TApplication.h"
#include "TMath.h"
using namespace std;
#include "DataPoints.hpp"

int DataPoints::Nplots = 0;

DataPoints::DataPoints()
{
  N=0;
  x = NULL;
  y = NULL;
}

DataPoints::DataPoints(int n, double* arrx, double* arry)
{
  N=n;
  x = new double[n];
  y = new double[n];
  for (int i =0; i<n; i++)
  {
    x[i]=arrx[i];
    y[i]=arry[i];
  }
}

DataPoints::DataPoints(const DataPoints& dp_copy)
{
  N = dp_copy.N;
  x = new double[N];
  y = new double[N];
  for (int i =0; i<N; i++)
  {
    x[i]=dp_copy.x[i];
    y[i]=dp_copy.y[i];
  }
}

void DataPoints::Draw(const char* title,const char* x_axis, const char* y_axis)
{
  if	(Nplots	==	0)	//create	application
  {
    TApplication	*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);
  }

  TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);
  c1->SetGrid();

  TGraph* gr = new TGraph(N,x,y);
  gr->SetMarkerColor(4);
  gr->SetMarkerSize(1.5-TMath::ATan(N/2000));
  gr->SetMarkerStyle(8); //7
  gr->SetTitle(title);
  gr->GetXaxis()->SetTitle(x_axis);
  gr->GetYaxis()->SetTitle(y_axis);
  gr->Draw("AP");

  c1->Update();
  c1->Draw();
  gPad->WaitPrimitive();

  Nplots++;
  delete gr;
  delete c1;
}

void DataPoints::Print(const char* filename, const char* title,const char* x_axis, const char* y_axis)
{
  TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);
  c1->SetGrid();

  TGraph* gr = new TGraph(N,x,y);
  gr->SetMarkerColor(4); // azul
  gr->SetMarkerSize(1.5);
  gr->SetMarkerStyle(8); // bola
  gr->SetTitle(title);
  gr->GetXaxis()->SetTitle(x_axis);
  gr->GetYaxis()->SetTitle(y_axis);
  gr->Draw("AP"); // desenha apenas os pontos

  c1->Update();
  c1->Draw();
  c1->SaveAs(filename);

  Nplots++;
  delete gr;
  delete c1;
}


 DataPoints::~DataPoints()
 {
   delete[]x;
   delete[]y;
 }
