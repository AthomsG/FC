#include <iostream>
#include "TMath.h"
#include "TF1.h"
#include <ctime>
using namespace std;
#include "DataPoints.hpp"
#include "FCrand.hpp"

int main()
{
  TF1* f1 = new TF1("f1","cos(x)",0.2*TMath::Pi(),0.5*TMath::Pi());

  int N=100000;
  FCrand fr;
  float* rand;// = fr.GetRandom(N,0.2*TMath::Pi(),0.5*TMath::Pi());
  double* xx = new double[5000];
  double* yy = new double[5000];
  double* err = new double[5000];
  double f =0, ff = 0, integral =0;

  int _time = time(NULL);
  for(int j = 0; j<=99980; j=j+20)
  {
    integral = 0;
    err[j/20]=0;
    f = 0;
    ff = 0;
    N = 20+j;
    rand=fr.GetRandom(N,0.2*TMath::Pi(),0.5*TMath::Pi());
    for(int i =0; i<N; i++)
    {
      f+=f1->Eval(rand[i]);
      ff+=pow(f1->Eval(rand[i]),2);
    }
    integral=f*0.3*TMath::Pi()/N;
    err[j/20]=ff/N-pow(f/N,2);
    err[j/20]=sqrt(err[j/20]/N);
    err[j/20]*=0.3*TMath::Pi();
    xx[j/20]=N;
    yy[j/20]=integral;
    fr.SetSeed(j*1234);
  }
  cout << "Tempo de execuçao = " << time(NULL)- _time << " s" << endl;

  DataPoints dp1(5000,xx,yy);
  dp1.PrintPlot("Integral_cos.eps","Uniform Sampling","N","integral");

  DataPoints dp2(5000,xx,err);
  dp2.PrintPlot("IntegralError_cos.eps","Uniform Sampling Error","N","error");

  delete[] rand;
  delete[] xx;
  delete[] yy;
  delete[] err;

  return 0;
}
