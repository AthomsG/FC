#include <iostream>
#include <string>
#include <cmath>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
using namespace std;
#include "DataPoints.hpp"
#include "LagrangeInterpolator.hpp"
#include "NewtonInterpolator.hpp"
#include "NevilleInterpolator.hpp"
#include "Spline3Interpolator.hpp"

int main()
{
  int size = 5;
  double* x = new double[size];//{-1.2,0.3,1.1};
  double* y = new double[size];//{-5.76,-5.61,-3.69};
  for(int i =0; i<size; i++) {x[i]=i; y[i]= cos(1/(1.1+cos(i)))+sin(i*i);}

  TF1* f0 = new TF1("f0","TMath::Cos(TMath::Cos(x))",0,4);

  DataPoints data(size,x,y);
  data.Draw("DataPoints","x","y");
  data.PrintPlot();
  data.Print();

  LagrangeInterpolator li(size,x,y);
  li.Draw("LagrangeInterpolator","X","Y",1000);
  li.PrintPlot();
  cout << "\nLagrange: f(0) = " << li.GetInterpolationFunction()->Eval(0) << endl;

  NewtonInterpolator ni(size,x,y);
  ni.Draw("NewtonInterpolator","X","Y",1000);
  ni.PrintPlot();
  cout << "\nNewton : f(0) = " << ni.GetInterpolationFunction()->Eval(0) << endl;

  NevilleInterpolator nvi(size,x,y);
  nvi.Draw("NevilleInterpolator","X","Y",1000);
  nvi.PrintPlot();
  cout << "\nNeville : f(0) = " << nvi.GetInterpolationFunction()->Eval(0) << endl;

  Spline3Interpolator spline(size,x,y);
  spline.SetFunction(spline.GetInterpolationFunction());
  spline.Draw("Spline3Interpolator","X","Y",1000,1);
  spline.PrintPlot();
  cout << "\nCubic Spline : f(0) = " << spline.GetInterpolationFunction()->Eval(0) << endl;
  cout << "\nf'(1) = " << spline.Derivative1(0.75);
  delete[] x;
  delete[] y;
  return 0;
}
