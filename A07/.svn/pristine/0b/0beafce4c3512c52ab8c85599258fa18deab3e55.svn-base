#include <iostream>
#include <cstdlib>
#include <math.h>
#include <ctime>
#include "TF1.h"
#include "TH1F.h"
#include "TCanvas.h"
#include "TFrame.h"
#include "TGraph.h"
#include "TApplication.h"
using namespace std;
#include "boltzmann.hpp"
#include "DataPoints.hpp"
#include "Spline3Interpolator.hpp"

void do_log(int** matrix, int N)
{
  int max = GetMax(matrix,N);
  int* counts = new int[max+1];

  for(int i=0; i<N; i++) //inicializa com 1's
  {
    for(int j=0; j<N; j++)
    {
      counts[matrix[i][j]]++;
    }
  }

  TCanvas * c1 = new TCanvas("c1","c1",200,10,600,400);
  c1->SetFillColor(0);
  c1->SetGrid();

  TPad *pad1 = new TPad("pad1","1st pad", 0.0,0.0,1.0,1.0,0);

  const Int_t n = max+1;
  Double_t x[n], y[n];
  for (Int_t i=0;i<n;i++)
  {
    x[i] = i;
    if(counts[i]!=0)
    {
      y[i] = log(counts[i]);
    } else
    {
      y[i]=0;
    }
  }

  TGraph* gr = new TGraph(n,x,y);
  gr->SetTitle("Boltzmann");
  gr->Draw();
  c1->Update();
  c1->GetFrame()->SetFillColor(0);
  c1->GetFrame()->SetBorderSize(8);
  c1->Modified();
  c1->SaveAs("Interpolation.eps");

  delete[] counts;
  delete gr;
  delete pad1;
  delete c1;
}

void Interpolate(int** matrix,int N)
{
  int max = GetMax(matrix,N);

  double* x= new double[max+1];
  double* y= new double[max+1];

  for(int i=0; i<max+1; i++) {x[i]=i; y[i]=0;}

  for(int i=0; i<N; i++)
  {
    for(int j=0; j<N; j++)
    {
      y[matrix[i][j]]++;
    }
  }
  double sum =0;
  for(int i=0; i<max+1; i++)
  {
    cout << "y[" << i << "] = " << y[i] << endl;
    y[i]/=N*N;
    sum+=y[i];
  }
  TF1 * F0= new TF1("exp","0.5*exp(-0.7*x)",0,max);
  Spline3Interpolator spline(max+1,x,y,F0);
  spline.Draw("Boltzmann Distribution","#Quanta","Probability",1000,0);

  delete[] x;
  delete[] y;
}

int GetMax(int** matrix,int N)
{
  int max = matrix[0][0];

  for(int i=0; i<N; i++) //inicializa com 1's
  {
    for(int j=0; j<N; j++)
    {
      if(matrix[i][j]>max) { max = matrix[i][j];}
    }
  }
  return max;
}

void Print(int** matrix,int N)
{
  for(int i=0; i<N; i++) //inicializa com 1's
  {
    for(int j=0; j<N; j++)
    {
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

void Randomize(int** matrix, int N)
{
  int rand1_row=0, rand1_col=0;

  do{ //nao posso tirar um quanta a uma posiç~ao com zero quantas
  rand1_row = (int)(rand()/(double)RAND_MAX*N);
  rand1_col = (int)(rand()/(double)RAND_MAX*N);
} while ( matrix[rand1_row][rand1_col]==0);

  int rand2_row = (int)(rand()/(double)RAND_MAX*N);
  int rand2_col = (int)(rand()/(double)RAND_MAX*N);

  matrix[rand1_row][rand1_col]--;
  matrix[rand2_row][rand2_col]++;
}
