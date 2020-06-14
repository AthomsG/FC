#include <iostream>
#include <vector>
#include "TMath.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"
#include "TLegend.h"
#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"
#include "FCmatrixBanded.hpp"
#include "EqSolver.hpp"
#include "FCtools.hpp"
#include "DataPoints.hpp"
#include "Spline3Interpolator.hpp"
// #include "Vertex.hpp"
// #include "Polygon2D.hpp"
using namespace std;

#define SEPARATOR "\n---------------------------\n"

int main()
{
  int choice = 0;
  cout << SEPARATOR << "Exercicio 1,2 ou 3? ";
  cin >> choice;
  switch(choice)
  {
    case 1:
    {/*
        vector<Vertex> v;
        Vertex v1(0.,0.);
        v.push_back(v1);
        v1.SetCoordinates(4.,5.);
        v.push_back(v1);
        v1.SetCoordinates(7.,3.);
        v.push_back(v1);

        Polygon2D Triangle(v);

        // imprimir os vértices do polígono
        Triangle.Print();

        // calcular a distância entre os vértices 2 e 3
        double d = Triangle.GetDistance(2,3);
        cout << "distância entre vértices 2 e 3: " << d << endl;

        // calcular o perímetro
        double a = Triangle.GetPerimeter();
        cout << "perímetro: " << a << endl;*/
        break;
    }
    case 2:
    {
      // alinea A  ------------------------------------------------------
      TApplication	*	MyRootApp;
      MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
      MyRootApp->SetReturnFromRun(true);

      TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);

      TF1* f1 = new TF1("f1","[0]*TMath::Power(x,-2.8)/(1+[1]*TMath::Power(x,-1.22)+[2]*TMath::Power(x,-2.54))",0,200);
      f1->SetParameters(21.1,5.85,1.18);
      f1->SetNpx(1000 );
      f1->SetLineColor(4);
      f1->SetLineWidth(2);
      f1->SetTitle("Proton Flux as a function of Energy");
      f1->GetXaxis()->SetTitle("Energy");
      f1->GetYaxis()->SetTitle("Flux (log scale)");
      f1->Draw();

      gPad->SetLogy();
      c1->Update();
      c1->SaveAs("FluxoProtoes.pdf");

      // alinea B  ------------------------------------------------------
      Vec disc(400);
      for(int i=0; i<400; i++)
      {
        disc[i]=f1->Eval(0.1+0.05*i);
      }
      disc.Print();

      // alinea C  ------------------------------------------------------

      FCtools from_file;
      vector<Vec> m1 = from_file.ReadFile2Vec("matrix.dat");
      FCmatrixFull M(m1);

      double* x = new double[400];
      double* y = new double[400];

      for(int i =0; i<400; i++)
      {
          x[i]=0.1+0.5*i;
          y[i]=0;
          for(int j=0; j<400; j++)
          {
            y[i]+=M[j][i]*disc[j]*0.05;
          }
      }
      c1->Clear();
      c1->Divide(2,1);
      TLegend* legend=new TLegend(0.6,0.65,0.88,0.85);
      legend->SetTextFont(72);
      legend->SetTextSize(0.04);

      c1->cd(1); // ------------------------------
      f1->Draw();
      Spline3Interpolator spline(400,x,y);
      TF1* f2 = (TF1*)spline.GetInterpolationFunction()->Clone();
      f2->Draw("SAME");
      gPad->SetLogy();
      legend->AddEntry(f1,"Real","l");
      legend->AddEntry(f2,"Measured","l");
      legend->Draw();

      c1->cd(2); // ------------------------------
      double* y2 = new double[400];
      for(int i =0; i<400; i++)
      {
          y2[i]=f1->Eval(x[i])-y[i];
      }
      Spline3Interpolator spline2(400,x,y);
      TF1* fdif = (TF1*)spline2.GetInterpolationFunction()->Clone();
      fdif->SetTitle("Difference between real and measured proton flux");
      fdif->GetXaxis()->SetTitle("Energy");
      fdif->GetYaxis()->SetTitle("Flux");
      fdif->SetNpx(1000);
      fdif->Draw();

      c1->Update();
      gPad->WaitPrimitive();
      c1->SaveAs("FluxoProtoesMedido.pdf");

      // alinea D  ------------------------------------------------------

      /*c1->Clear();
      Vec v2(400,y2);
      EqSolver eq1(M,v2);
      Vec recflux = eq1.GaussEliminationSolver();
      //cout << SEPARATOR;
      //recflux.Print();

      Spline3Interpolator spline3(400,x,recflux.GetEntries());
      TF1* frec = (TF1*)spline3.GetInterpolationFunction()->Clone();
      frec->SetTitle("Difference between real and measured proton flux");
      frec->GetXaxis()->SetTitle("Energy");
      frec->GetYaxis()->SetTitle("Flux");
      frec->SetNpx(1000);
      frec->Draw();

      c1->Update();
    //  c1->Draw();
      //gPad->WaitPrimitive();*/

      delete c1;
      delete f1;
      delete[] x;
      delete[] y;
      delete legend;
      delete f2;
      delete[] y2;
      delete fdif;
      break;
    }
    case 3:
    {
      FCmatrixFull M1(4,4,0);
      M1[0][1]= 1; M1[0][2]= 2; M1[0][3]= 1;
      M1[1][0]= 1; M1[1][1]= 2; M1[1][2]= 1;
      M1[2][0]= 0.02; M1[2][1]= 0.01;
      M1[3][2]= 100; M1[3][3]= 200;

      Vec b1;
      b1.push_back(0.02);
      b1.push_back(1);
      b1.push_back(4);
      b1.push_back(800);

      EqSolver eq1(M1,b1);

      cout << "Vetor soluçao: " << endl;
      eq1.GaussEliminationSolver().Print();
      break;
    }
  }

  return 0;
}
