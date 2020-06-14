#ifndef INTEGRATOR_HPP
#define INTEGRATOR_HPP
#include "Func1D.hpp"
#include "TF1.h"

class Integrator: public Func1D
{
  public:
    Integrator(double xbeg=0, double xend=0, TF1* func=NULL)  :
    x0(xbeg), x1(xend), Func1D(func) {;}
    Integrator(const Integrator&);
    ~Integrator() {;}
    void SetBoundaries(double x_0,double x_1);
    void TrapezoidalRule(int n, double& result, double& error);
    void SimpsonRule(int n, double& result, double& error);
  protected:
    double x0;
    double x1;
};

#endif
