#include <iostream>
#include <vector>
#include "InBox1D.h"

using namespace std;

double* InBox1D::GetX() const
{
    double* xcopy = new double[2];
    xcopy[0]=x[0];
    xcopy[1]=x[1];
    return xcopy;
}

double* InBox1D::GetV() const
{
  double* vcopy = new double[2];
  vcopy[0]=v[0];
  vcopy[1]=v[1];
  return vcopy;
}

double InBox1D::GetALPHA() const
{
    return alpha;
}

void InBox1D::AdvanceX(double ts) //1º
{
    double x0_cpy = x[0], x1_cpy = x[1];

    x[0] += v[0]*ts;
    x[1] += v[1]*ts;

    hasreflected = false;
    collision = false;

    if((x[0]-x[1])*(x0_cpy-x1_cpy)<=0)
    {
    //  cout 
      if(v[1]!=v[0])
      {
        x[0] = (x0_cpy*v[1]-x1_cpy*v[0])/(v[1]-v[0]);
        x[1] = (x0_cpy*v[1]-x1_cpy*v[0])/(v[1]-v[0]);
      } else
      {
        x[0]=(x0_cpy+x1_cpy)/2.0;
        x[1]=x[0];
      }
      collision = true;
      Ncollisions++;
    }

    if(x[0]<=0)
    {
      Ncollisions++;
      x[0]=0;
      hasreflected = true;
    }
}
void InBox1D::AdvanceV(double ts)
{
    if (collision)
    {
      double aux = v[0];
      v[0]=(m[0]-m[1])/(m[0]+m[1])*v[0]+2*m[1]/(m[0]+m[1])*v[1];
      v[1]=(m[1]-m[0])/(m[1]+m[0])*v[1]+2*m[0]/(m[0]+m[1])*aux;
    }
    if (hasreflected)
    {
      v[0]*=1;
    }
    v[0] *= alpha;
    v[1] *= alpha;
}

void InBox1D::StepInTime(double dt)
{
    this->AdvanceX(dt);
    this->AdvanceV(dt);
}

InBox1D::InBox1D(double* x0, double* v0, double* m, double alpha)
{
    this->m = new double[2];
    this->m[0]=m[0];
    this->m[1]=m[1];
    x = new double[2];
    v = new double[2];
    x[0]=x0[0];
    x[1]=x0[1];
    v[0]=v0[0];
    v[1]=v0[1];
    this->alpha=alpha;
}

InBox1D::InBox1D(const InBox1D& obj)
{
    // x     = obj.x;
    // v     = obj.v;
    // WR    = obj.WR;
    // alpha = obj.alpha;
}
