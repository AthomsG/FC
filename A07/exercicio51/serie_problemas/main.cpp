#include <iostream>
#include <string>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
using namespace std;
#include "TMath.h"
#include "Spline3Interpolator.hpp"
#include "Derivator.hpp"
#include "Integrator.hpp"

int main()
{
  TF1* f1 = new TF1("f1","TMath::Cos(x)",0,5);

  Derivator aa;
  Integrator bb; // testes para default constructors

  Derivator d1(f1);

  cout << "cos'(0) = " << d1.Deriv_1(0,0.0001,1) << endl;
  cout << "cos''(0) = " << d1.Deriv_2(0,0.0001,1) << endl;
  cout << "cos'''(0) = " << d1.Deriv_3(0,0.001,1) << endl;
  cout << "cos''''(0) = " << d1.Deriv_4(0,0.001,1) << endl;

  Integrator test(0,1,f1);
  double result=0., error=0.;

  test.TrapezoidalRule(1000,result,error);
  cout << "Trapezoidal: " << setprecision(10) << result << " with error " << error << endl;

  test.SimpsonRule(1000,result,error);
  cout << "Simpson: " << setprecision(10) <<  result << " with error " << error << endl;

  /*double* N1 = new double[18]{.123,.170,.232,.312,.490,.563,.654,.750,.863,1.193,1.428,1.687,1.979,2.308,3.079,4.236,6.189,8.851};
  double* O1 = new double[18]{.132,.181,.247,.330,.513,.588,.684,.783,.900,1.246,1.493,1.765,2.073,2.418,3.227,4.444,6.487,9.277};
  double* AR1 = new double[19];
  double* E = new double[19]{0,0.050,0.080,.128,.201,.400,.500,.640,.800,1,1.6,2,2.401,2.8,3.2,4,5,6.4,8};

  AR1[0]=0;
  for(int i =1 ; i<19; i++)
  {
    AR1[i] = 0.79*N1[i-1]+0.21*O1[i-1];
    //cout << "AR1[" << i <<"] = " << AR1[i] << endl;
  }

  Spline3Interpolator spline1(19,AR1,E);
  spline1.Draw(" ","E (MeV)","#Delta x (mg/cm^2)",1000,1);

  //cout << "Alcance (1.14)AAA = " << spline1.GetInterpolationFunction()->Eval(0.72425);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(2.107);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(3.071);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(4.034);

  // cout << "Alcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(3.53335);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(2.56985);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(1.60655);
  // cout << "\nAlcance (1.14) = " << spline1.GetInterpolationFunction()->Eval(0.64335);

  cout << "\n--------------\n";

  double* N2 = new double[18]{.564,.684,.817,.956,1.303,1.442,1.604,1.734,1.816,1.776,1.640,1.458,1.292,1.152,0.949,0.792,0.655,0.556};
  double* O2 = new double[18]{.530,.644,.777,.930,1.262,1.389,1.546,1.665,1.748,1.688,1.561,1.385,1.227,1.098,.900,.756,.626,.530};
  double* AR2 = new double[18]{};

  AR2[0]=0;
  for(int i =1 ; i<19; i++)
  {
    AR2[i] = 0.79*N2[i-1]+0.21*O2[i-1];
    //cout << "AR2[" << i <<"] = " << AR2[i] << endl;
  }

  Spline3Interpolator spline2(19,E,AR2);
  spline2.Draw(" ","E (MeV)","dE/dx(MeV/mg/cm^2)",1000,1);

  cout << "dE/dx = " << spline2.GetInterpolationFunction()->Eval(5.305);
  cout << "\ndE/dx = " << spline2.GetInterpolationFunction()->Eval(4.38117);
  cout << "\ndE/dx = " << spline2.GetInterpolationFunction()->Eval(3.45930);
  cout << "\ndE/dx = " << spline2.GetInterpolationFunction()->Eval(2.25785);
  cout << "\ndE/dx = " << spline2.GetInterpolationFunction()->Eval(0.61323);
  cout << endl;

  int n = 100;
  double d=4.034;
  double dx=d/n;
  double Ee = 5.305;
  double* res = new double[100]; // 100 -> 505100
  double* hollla = new double[100];
  int count=0;

  for(int j=0; j< 100; j++)
  {
    Ee = 5.305;
    n=100*(j+1);
    dx=d/n;
    for(int i = 0; i<=n; i++)
    {
        Ee=Ee-dx*spline2.GetInterpolationFunction()->Eval(Ee);
    }
    cout << "\n\n" << 5.305-Ee << endl;
    res[count]=5.305-Ee;
    hollla[count]=n;
    count++;
  }
  cout << "count = " << count;

  DataPoints dp (count,hollla,res);
  dp.Draw();*/

  return 0;
}
