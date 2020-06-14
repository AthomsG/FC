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
    int size = 5000;

    double* x = new double[size];
    double* y = new double[size];

    int maxrg = 5;
    TF1* f = new TF1("f","cos(3*x)", 0., maxrg);

    for (int i = 0; i<size; i++)
    {
        x[i] = double(i)*double(maxrg)/double(size);
        y[i] = f->Eval(x[i]);
    }

   Spline3Interpolator spline(size,x,y);
   spline.Draw("Spline3Interpolator","X","Y", 1000, 0);
   spline.PrintPlot("Spline3Interpolator","titulo","X","Y", 1000);

   return 0;
}
