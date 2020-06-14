#include <iostream>
#include <math.h>
#include <TGraph.h>
#include <TCanvas.h>
using namespace std;
#include "discretization_and_round.hpp"

float f1(float x)
{
  return exp(2.0*x);
}

float f1d(float x)
{
  return 2.0*exp(2.0*x);
}
