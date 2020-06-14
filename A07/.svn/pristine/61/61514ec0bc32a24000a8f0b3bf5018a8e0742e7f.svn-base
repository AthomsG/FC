#include "ODEsolver.hpp"
#include <vector>
#include <string>
#define SEPARATOR  "\n---------------\n"
//FUNCTION, Time. Dont forgetti time!!! o tempo é representado na equação por [0].

ODEsolver::ODEsolver(vector<TFormula> Form)
{
    F = Form;
}

ODEsolver::ODEsolver(TFormula Form)
{
    F.push_back(Form);
}

ODEsolver::ODEsolver(const ODEsolver& cpy)
{
  this->F=cpy.F;
}

void ODEsolver::SetODEfunc(vector<TFormula> Form)
{
    F = Form;
}

//-------------------------------Euler----------------------------------//

ODEpoint ODEsolver::EULER_iterator (const ODEpoint& current, double step)
{
    vector<double> var = current.Get_Var_vec();
    double *x = current.Get_Var_ptr();
    double *t = new double(current.Get_Time());
    for (int i = 0; i < current.GetNdim(); i++)//Método de Euler
    {
        var[i] += step*F[i].EvalPar(x, t);
    }
    ODEpoint next(current.Get_Time() + step, var);
    delete[] x;
    delete t;
    return next;
}

vector<ODEpoint> ODEsolver::Eulersolver(const ODEpoint& P0, double xmin, double xmax, double h_step)
{
    vector<ODEpoint> res;
    res.push_back(P0);
    int iter = (xmax - xmin)/h_step;
    for (int i = 1; i <= iter; i++)
    {
        res.push_back(this->EULER_iterator(res[i-1], h_step));
    }
    return res;
}

//-------------------------------HEUN----------------------------------//

ODEpoint ODEsolver::Heun_iterator (const ODEpoint& current, double step)
{
    vector<double> var = current.Get_Var_vec();
    double *x = current.Get_Var_ptr();
    double *y = (this->EULER_iterator(current, step)).Get_Var_ptr();
    double *t = new double(current.Get_Time());

    for (int i = 0; i < current.GetNdim(); i++)
    {
        var[i] += (step/2)*(F[i].EvalPar(x, t));
        *t     += step;
        var[i] += (step/2)*F[i].EvalPar(y, t);
        *t     -= step;
    }
    ODEpoint next(*t + step, var);
    delete[] x;
    delete[] y;
    delete t;
    return next;
}

vector<ODEpoint> ODEsolver::Heun(const ODEpoint& P0, double xmin, double xmax, double h_step)
{
    vector<ODEpoint> res;
    res.push_back(P0);
    int iter = (xmax - xmin)/h_step;
    for (int i = 1; i <= iter; i++)
    {
        res.push_back(this->Heun_iterator(res[i-1], h_step));
    }
    return res;
}

//----------------------------Runge-Kutta2------------------------------//

ODEpoint ODEsolver::RK2_iterator (const ODEpoint& current, double step)
{
    vector<double> var = current.Get_Var_vec();
    double K1, K2;
    double *x = current.Get_Var_ptr();
    double *t = new double(current.Get_Time());

    for (int i = 0; i < current.GetNdim(); i++)//Runge Kutta de Ordem 2
    {
        K1 = step*F[i].EvalPar(x, t);
        *t += step/2;
        this->Add(x, K1/2);
        K2 = step*F[i].EvalPar(x, t);
        this->Add(x,-K1/2);
        *t -= step/2;
        var[i] += K2;
    }
    ODEpoint next(*t + step, var);
    delete[] x;
    delete t;
    return next;
}

vector<ODEpoint> ODEsolver::RK2solver(const ODEpoint& P0, double xmin, double xmax, double h_step)
{
    vector<ODEpoint> res;
    res.push_back(P0);
    int iter = (xmax - xmin)/h_step;
    for (int i = 1; i <= iter; i++)
    {
        res.push_back(this->RK2_iterator(res[i-1], h_step));
    }
    return res;
}

//----------------------------Runge-Kutta4------------------------------//

ODEpoint ODEsolver::RK4_iterator (const ODEpoint& current, double step)
{
    vector<double> var = current.Get_Var_vec();

    double K1, K2, K3, K4;
    double *x = current.Get_Var_ptr();
    double **ps = new double*[current.GetNdim()];

    for (int i = 0; i < current.GetNdim(); i++) //Runge Kutta de Ordem 2
    {
        ps[i]=new double[F[i].GetNpar()+1];
        for(Int_t j = 0; j<F[i].GetNpar(); j++) {
          ps[i][j]=F[i].GetParameter(j);
        }
        ps[i][F[i].GetNpar()]=current.GetNdim();
        K1 = step*F[i].EvalPar(x,ps[i]);
        Add(x, K1/2);
        ps[i][F[i].GetNpar()]+=step/2.0;
        K2 = step*F[i].EvalPar(x,ps[i]);
        Add(x,K2/2-K1/2);
        K3 = step*F[i].EvalPar(x,ps[i]);
        Add(x,K3-K2/2);
        ps[i][F[i].GetNpar()]+=step/2.0;
        K4 = step*F[i].EvalPar(x,ps[i]);
        Add(x,-K3);
        var[i] += (K1 + 2*(K2 + K3) + K4)/6.0;
    }
    ODEpoint next(current.Get_Time()+step, var);
    delete[] x;
    for(int i = 0 ; i< current.GetNdim(); i++)
    {
      delete[] ps[i];
    }
    delete[] ps;
    return next;
}

// ODEpoint ODEsolver::RK4_iterator (const ODEpoint& current, double step)
// {
//     vector<double> var = current.Get_Var_vec();
//
//     double K1, K2, K3, K4;
//     double *x = current.Get_Var_ptr();
//
//     for (int i = 0; i < current.GetNdim(); i++) //Runge Kutta de Ordem 2
//     {
//         F[i].SetParameter(0,current.Get_Time());
//         K1 = step*F[i].EvalPar(x);
//         Add(x, K1/2);
//         F[i].SetParameter(0,current.Get_Time()+step/2.0);
//         K2 = step*F[i].EvalPar(x);
//         Add(x,K2/2-K1/2);
//         K3 = step*F[i].EvalPar(x);
//         Add(x,K3-K2/2);
//         F[i].SetParameter(0,current.Get_Time()+step);
//         K4 = step*F[i].EvalPar(x);
//         Add(x,-K3);
//         var[i] += (K1 + 2*(K2 + K3) + K4)/6.0;
//     }
//     ODEpoint next(current.Get_Time()+step, var);
//     delete[] x;
//     return next;
// }

vector<ODEpoint> ODEsolver::RK4solver(const ODEpoint& P0, double xmin, double xmax, double h_step)
{
    vector<ODEpoint> res;
    //res.push_back(P0);
    int iter = (xmax - xmin)/h_step;
    res.push_back(this->RK4_iterator(P0, h_step));

    for (int i = 1; i < iter; i++)
    {
        res.push_back(this->RK4_iterator(res[i-1], h_step));
    }
    return res;
}
//----------------------Runge-Kutta4-Xmas-Special-----------------------//


//----------------------------Métodos-Extra-----------------------------//

void ODEsolver::Add(double* x, double k)
{
    for (int i = 0; i < F.size(); i++)
    {
        x[i] += k;
    }
}
