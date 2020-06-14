#include <iostream>
#include <string>
#include "TMath.h"
#include "TF1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TLegend.h"
using namespace std;
#include "ExpFunct.hpp"

int main()
{
  TApplication	*	MyRootApp;
  MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
  MyRootApp->SetReturnFromRun(true);

  TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);

  // METODO DO ROOT ------------------------------------

  TF1* f1 = new TF1("f1","[0]*TMath::Exp(-[0]*x)",0,100);
  f1->SetParameter(0,0.1);

  TH1D* h1 = new TH1D("h1","Exp Distribution",100,0,100);
  h1->SetStats(0);

  for(int i =0; i<10000; i++)
  {
    h1->AddBinContent(f1->GetRandom());
  }
  h1->Draw();
  // METODO IMPLEMEMENTADO POR NOS ----------------------

  double* values = exp_funct(0.1,10000,0,100);
  // 10000 valores entre 0 e 100 gerados pela pdf ga*e^(-ga*x) com ga = 0.1

  TH1D* h2 = new TH1D("h2","Exp Distribution",100,0,100);
  for(int i =0; i<10000; i++)
  {
    h2->AddBinContent(values[i]);
  }
  h2->SetLineColor(kRed);
  h2->Draw("same");

  //Desenhar no root ------------------------------------

  TLegend *legend = new TLegend(0.6,0.65,0.88,0.85);
  legend->SetTextFont(72);
  legend->SetTextSize(0.04);
  legend->AddEntry(h1,"Metodo TF1","l");
  legend->AddEntry(h2,"Metodo Criado","l");
  legend->Draw();

  c1->Update();
  c1->Draw();
  c1->SaveAs("ExpHistogram.eps");
  gPad->WaitPrimitive();

  //delete MyRootApp; //da erro
  delete c1;
  delete f1;
  delete h1;
  delete h2;
  delete legend;

  return 0;
}
