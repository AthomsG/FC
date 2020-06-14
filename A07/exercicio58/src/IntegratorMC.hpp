#ifndef INTEGRATORMC_HPP
#define INTEGRATORMC_HPP
#include "Integrator.hpp"
#include "TRandom3.h"
#include "TFormula.h"

class IntegratorMC : public Integrator
{
  public:
    IntegratorMC(TF1* f=NULL, int M=1, double x0=0, double x1=0);
    IntegratorMC(TFormula* fF, int M, double* _xmin, double* _xmax);
    IntegratorMC(const IntegratorMC&); //cpy constructor
    ~IntegratorMC() {;}
    void UniformRandom(int N, double& result, double& error);
    void ImportanceSampling(int N, TF1* p, TF1* xofy, double& result, double& err);
    void AcceptanceRejection(int N, double fMax,double& result, double& error);
  private:
    int Ndim;
    double* xmin;
    double* xmax;
    TRandom3 rgen;
    TFormula* fF;
};

#endif
