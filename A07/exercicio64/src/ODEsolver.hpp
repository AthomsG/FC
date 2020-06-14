#ifndef ODE_SOLVER
#define ODE_SOLVER

#include "ODEpoint.hpp"
#include "TFormula.h"
#include <iostream>

using namespace std;

class ODEsolver{
  public:
    ODEsolver(vector<TFormula> Form);
    ODEsolver(TFormula Form);
    ~ODEsolver(){;};
    vector <ODEpoint> Eulersolver(const ODEpoint& P0, double xmin, double xmax, double h_step);
    vector<ODEpoint>  RK2solver(const ODEpoint& P0, double xmin, double xmax, double h_step);
    vector <ODEpoint> RK4solver(const ODEpoint& P0, double xmin, double xmax, double h_step);
    vector <ODEpoint> RK4_AdapStep(const ODEpoint& P0, double xmin, double xmax, double h_step);
    vector<ODEpoint>  Heun(const ODEpoint& P0, double xmin, double xmax, double h_step);
    void SetODEfunc(vector<TFormula> Form);
  private:
    ODEpoint Heun_iterator (const ODEpoint&, double step);
    ODEpoint EULER_iterator (const ODEpoint&, double step);
    ODEpoint RK2_iterator (const ODEpoint&, double step);
    ODEpoint RK4_AS_iterator(const ODEpoint&, double step, vector<vector<double> >&K);
    ODEpoint RK4_iterator(const ODEpoint&, double step);
    vector<TFormula> F;
    void Add(double* x, double k);
    //criar membro vector<ODEpoints> solution e criar método Draw();
};

#endif
