#include "Integrator.hpp"
#include "Derivator.hpp"
#include "TF1.h"
using namespace std;

Integrator::Integrator(const Integrator& cpy) : Func1D(cpy.F)
{
  x0 = cpy.x0;
  x1 = cpy.x1;
}

void Integrator::SetBoundaries(double x_0,double x_1)
{
  x0=x_0;
  x1=x_1;
}

void Integrator::TrapezoidalRule(int n, double& result, double& error)
{
  result = 0;
  error = 0;
  double h = (x1-x0)/(double)n; //step
  double avg_2d = 0; // average 2nd derivative
  cout << " \n\n\nh = " << h << endl ;
  Derivator d(F);

  for(int i = 0; i< n; i++)
  {
    result+= Evaluate(x0+i*h)+Evaluate(x0+(i+1)*h);
    if(i<2) {avg_2d += d.Deriv_2(x0+i*h,h,1);} //forward porque e o limite esquerdo
    else if (i<n-1) {avg_2d += d.Deriv_2(x0+i*h,h,0);}//central porque nao inclui os extremos
    else {avg_2d += d.Deriv_2(x0+i*h,h,2);}
  }
  result*= h/2.0;

  avg_2d += d.Deriv_2(x1,h,2); // backwards porque e o limite direito
  avg_2d /=(double)(n+1);
  error = -h*h/12.0*(x1-x0)*avg_2d;
}

void Integrator::SimpsonRule(int n, double& result, double& error)
{
  result = 0;
  error = 0;
  double h = (x1-x0)/(double)n; //step
  double avg_4d = 0; // average 4th derivative
  // n + 1 points
  Derivator d;
  d.SetFunc(F);

  for(int i = 0; i< n-1; i=i+2)
  {
    if(i<n-3 || (n+1)%2!=0)
    {
      result+= Evaluate(x0+i*h)+4*Evaluate(x0+(i+1)*h)+Evaluate(x0+(i+2)*h);
      if(i<3) {avg_4d += d.Deriv_4(x0+i*h,h,1)+d.Deriv_4(x0+(i+1)*h,h,1);} //forward porque ´e o limite esquerdo
      else if (i<n-3){avg_4d += d.Deriv_4(x0+i*h,h,1)+d.Deriv_4(x0+(i+1)*h,h,0);} //central porque nao inclui os extremos
      else {avg_4d += d.Deriv_4(x0+i*h,h,1)+d.Deriv_4(x0+(i+1)*h,h,2);}
    }
  }
  result*= h/3.0;
  if ((n+1)%2==0)
  {
    result+= 3*h/8.0*(Evaluate(x0+(n-3)*h)+3*Evaluate(x0+(n-2)*h)+
            3*Evaluate(x0+(n-1)*h)+Evaluate(x0+(n)*h));
    avg_4d += d.Deriv_4(x0+(n-3)*h,h,0)+d.Deriv_4(x0+(n-2)*h,h,2);
  }

  avg_4d += d.Deriv_4(x1-h,h,2) + d.Deriv_4(x1,h,2); // backwards porque ´e o limite direito
  avg_4d /=(double)(n+1);
  error = -h*h*h*h/180.0*(x1-x0)*avg_4d;
}
