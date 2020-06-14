#include <iostream>
#include <string>
#include <cmath>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
using namespace std;
#include "LagrangeInterpolator.hpp"
#include "NewtonInterpolator.hpp"
#include "NevilleInterpolator.hpp"
#include "Spline3Interpolator.hpp"

int main()
{
  int size = 5;
  double* x = new double[size]{1,2,3,4,5};
  double* y = new double[size]{0,1,0,1,0};

  DataPoints data(size,x,y);
  data.Draw("DataPoints","x","y");
  data.PrintPlot("datapoints","Pontos Experimentais","x","y");

  LagrangeInterpolator li(size,x,y);
  li.Draw("LagrangeInterpolator","X","Y",1000);
  li.PrintPlot("lagrange_interpolater","Interpolacao","x","y",1000);
  cout << "\nLagrange: f(0) = " << li.GetInterpolationFunction()->Eval(0) << endl;

  NewtonInterpolator ni(size,x,y);
  ni.Draw("NewtonInterpolator","X","Y",1000);
  ni.PrintPlot("newton_interpolater","Interpolacao","x","y",1000);
  cout << "\nNewton : f(0) = " << ni.GetInterpolationFunction()->Eval(0) << endl;

  NevilleInterpolator nvi(size,x,y);
  nvi.Draw("NevilleInterpolator","X","Y",1000);
  nvi.PrintPlot("Neville_interpolater","Interpolacao","x","y",1000);
  cout << "\nNeville : f(0) = " << nvi.GetInterpolationFunction()->Eval(0) << endl;

  Spline3Interpolator spline(size,x,y);
  spline.Draw("Spline3Interpolator","X","Y",1000,0);
  nvi.PrintPlot("Spline3_interpolater","Interpolacao","x","y",1000);
  cout << "\nCubic Spline : f(0) = " << nvi.GetInterpolationFunction()->Eval(0) << endl;

  delete[] x;
  delete[] y;
  return 0;
}
