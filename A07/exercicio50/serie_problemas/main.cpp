#include <iostream>
#include <string>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TMath.h"
using namespace std;
#include "Spline3Interpolator.hpp"
#include "Derivator.hpp"

#define SEPARATOR "\n---------------\n"

int main()
{
  TF1* f1 = new TF1("f1","TMath::Cos(x)",-2,2);

  Derivator d1(f1);

  int n = 500;
  double* x = new double[n];
  double* y = new double[n];

  for(int i = 0; i<=n; i++)
  {
    x[i] = -2+i*4.0/n;
    if (i==0)  { y[i] = d1.Deriv_1(x[i],4.0/n,1);}
    else if (i<n) {y[i] = d1.Deriv_1(x[i],4.0/n,0);}
    else { y[i] = d1.Deriv_1(x[i],4.0/n,2);}
  }
  Spline3Interpolator spline(n+1,x,y);
  Func1D d1_func(spline.GetInterpolationFunction());
  d1_func.Draw();

  cout << SEPARATOR;
  cout << "cos'(0) = " << d1.Deriv_1(0,0.001,0) << endl;
  cout << "cos'(0) = " << d1.Deriv_1(0,0.001,1) << endl;
  cout << "cos'(0) = " << d1.Deriv_1(0,0.001,2) << SEPARATOR;
  cout << "cos''(0) = " << d1.Deriv_2(0,0.001,0) << endl;
  cout << "cos''(0) = " << d1.Deriv_2(0,0.001,1) << endl;
  cout << "cos''(0) = " << d1.Deriv_2(0,0.001,2) << SEPARATOR;
  cout << "cos'''(0) = " << d1.Deriv_3(0,0.001,0) << endl;
  cout << "cos'''(0) = " << d1.Deriv_3(0,0.001,1) << endl;
  cout << "cos'''(0) = " << d1.Deriv_3(0,0.001,2) << SEPARATOR;
  cout << "cos''''(0) = " << d1.Deriv_4(0,0.001,0) << endl;
  cout << "cos''''(0) = " << d1.Deriv_4(0,0.001,1) << endl;
  cout << "cos''''(0) = " << d1.Deriv_4(0,0.001,2) << SEPARATOR;

  delete f1;
  return 0;
}
