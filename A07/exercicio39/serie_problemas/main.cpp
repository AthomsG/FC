#include <iostream>
#include <math.h>
#include <TGraph.h>
#include <TAxis.h>
#include <TFrame.h>
#include <TMath.h>
#include <TCanvas.h>
#include <TF1.h>
using namespace std;
#include "discretization_and_round.hpp"

int main()
{
    float x0=3;
    float h=5*pow(10,-7);
    float aux=0;

    // 200000 = 10^(-1) / (5*10^(-7));
    float* erros = new float[200000];

    float func= f1(x0), func_d=f1d(x0);
    for (int i =0; i<200000; i++)
    {
      aux+=h;
      erros[i]=(f1(x0+aux)-func)/aux-func_d;
    }

    TCanvas * c1 = new TCanvas("c1","c1",200,10,600,400);
    c1->Divide(2, 1);
    c1->SetFillColor(0);
    c1->SetGrid();

    TPad *pad1 = new TPad("pad1","1st pad", 0.0,0.0,1.0,1.0,0);

    const Int_t n = 200000;
    Double_t x[100], y[100];
    for (Int_t i=0;i<100;i++)
    {
      x[i] = h*(i+1);
      y[i] = erros[i];
    }
    Double_t x1[n-100], y1[n-100];
    for (Int_t i=0;i<n-100;i++)
    {
      x1[i] = h*(i+1);
      y1[i] = erros[i+100];
    }

    TGraph* gr = new TGraph(100,x,y);
    gr->SetTitle("erros de round-off");
    TGraph* gr1 = new TGraph(n-100,x1,y1);
    gr1->SetTitle("erros de discretizacao");
    c1->cd(1);
    gr->Draw();
    c1->cd(2);
    gr1->Draw();
    c1->Update();
    c1->GetFrame()->SetFillColor(0);
    c1->GetFrame()->SetBorderSize(8);
    c1->Modified();
    c1->SaveAs("Erros.eps");

    return 0;
}
