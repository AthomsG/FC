#include "ODEpoint.hpp"
#include <iostream>
//CHECKED
using namespace std;

ODEpoint::ODEpoint()
{
    t = 0;
    Ndim = 0;
}

ODEpoint::~ODEpoint() {;}

ODEpoint::ODEpoint(double tval, double* funct, int Ndimf)
{
    t    = tval;
    Ndim = Ndimf;
    for (int i = 0; i < Ndim; i++)
    {
        var.push_back(funct[i]);
    }
}
ODEpoint::ODEpoint(double tval, vector<double> funct)
{
    t = tval;
    var = funct;
    Ndim = funct.size();
}
ODEpoint::ODEpoint(const ODEpoint& cpy)
{
    Ndim = cpy.Ndim;
    var  = cpy.var;
    t    = cpy.t;
}
vector<double> ODEpoint::Get_Var_vec() const
{
  vector<double> cpy = var;
  return cpy;
}

double* ODEpoint::Get_Var_ptr() const
{
    double* vec = new double[var.size()];
    for (int i = 0; i < var.size(); i++)
    {
        vec[i] = var[i];
    }
    return vec; //sdds
}

double* ODEpoint::Get_VarTime() const
{
    double* vec = new double[var.size()+1];
    for (int i = 0; i < var.size(); i++)
    {
        vec[i] = var[i];
    }
    vec[var.size()]=t;
    return vec;
}

int ODEpoint::GetNdim() const
{
    return Ndim;
}

double ODEpoint::Get_Time() const
{
    return t;
}

void ODEpoint::Print() const
{
    for (int i = 0; i < Ndim; i++)
    {
        cout << "var[" << i << "] = " << var[i] << endl;
    }
}

//OPERATORS
ODEpoint& ODEpoint::operator=(const ODEpoint& P)
{
    t = P.t;
    var = P.var;
    Ndim = P.Ndim;
    return *this;
}
