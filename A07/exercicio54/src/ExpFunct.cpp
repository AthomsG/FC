#include "FCrand.hpp"
#include "ExpFunct.hpp"
#include "TMath.h"
#include <iostream>
using namespace std;

double* exp_funct(double ga, int N, double xmin, double xmax)
{
  FCrand rand;

  float* x = rand.GetRandom(N);
  double* y = new double[N];

  for(int i =0; i<N; i++)
  {
    y[i] = - TMath::Log(1-(1-TMath::Exp(-ga*xmax))*(double)x[i])/ga;
  }

  delete[] x;
  return y;
}
