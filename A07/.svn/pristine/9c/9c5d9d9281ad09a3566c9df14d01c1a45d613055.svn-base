#include "ODEpoint.hpp"
#include "ODEsolver.hpp"
#include "TFormula.h"
#include "TApplication.h"
#include "TGraph2D.h"
#include "TCanvas.h"
#include "TF1.h"
#include <iostream>
#include <string>
#define SEPARATOR "\n------------\n"

using namespace std;

//EXERCÍCIO 66
int main()
{
    double t0 = 0, t1=30;
    int n = 10E+4;

    double h = (t1-t0)/(double)n;

    TApplication	*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);

    TCanvas* c = new TCanvas("c1", "Título");

    TFormula func1("f1", "10*(y-x)");
    TFormula func2("f2", "x*(28-z)-y");
    TFormula func3("f3", "x*y-8.0*z/3.0");

    vector<TFormula> vec;
    vec.push_back(func1);
    vec.push_back(func2);
    vec.push_back(func3);
    ODEsolver eq(vec);

    vector<double> init;
    init.push_back(1);
    init.push_back(1);
    init.push_back(1);

    ODEpoint  oi(t0, init);

    vector<ODEpoint> sol = eq.RK4solver(oi, t0, t1, h);

    double* t  = new double[sol.size()];
    double* x = new double[sol.size()];
    double* y = new double[sol.size()];
    double* z = new double[sol.size()];

    for(int i = 0; i < sol.size(); i++)
    {
        t[i]  = sol[i].Get_Time();
        x[i] = sol[i].Get_Var_ptr()[0];
        y[i] = sol[i].Get_Var_ptr()[1];
        z[i] = sol[i].Get_Var_ptr()[2];
    }

    TGraph2D *g = new TGraph2D(n, x, y, z);
    g->SetMarkerSize(0.5);
    g->SetMarkerColor(8);
    g->Draw();

    c->BuildLegend();
    c->Update();
    gPad->WaitPrimitive();
    c->SaveAs("lorentz_attractor.eps");

    return 0;
}
