#include "ODEpoint.hpp"
#include "ODEsolver.hpp"
#include "TFormula.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TMath.h"
#include "TF1.h"
#include "TAxis.h"
#include <iostream>
#include <string>
#define SEPARATOR "\n------------\n"

using namespace std;

//EXERCÍCIO 66
int main()
{
    double t0 = 0, t1=2*TMath::Pi();
    int n = 600;

    double h = (t1-t0)/(double)n;

    TApplication	*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);

    TCanvas* c = new TCanvas("c1", "Título");

    TFormula func1("f1", "y");
    TFormula func2("f2", "-z*sin(x)"); //[0] esta reservado para o tempo...
    TFormula func3("f3","0");

    vector<TFormula> vec;
    vec.push_back(func1);
    vec.push_back(func2);
    vec.push_back(func3);
    ODEsolver eq(vec);

    vector<double> init;
    init.push_back(2);
    init.push_back(0);
    init.push_back(5);

    ODEpoint  oi(t0, init);

    vector<ODEpoint> sol = eq.RK4solver(oi, t0, t1, h);

    double* t  = new double[sol.size()];
    double* theta = new double[sol.size()];
    double* omega = new double[sol.size()];

    for(int i = 0; i < sol.size(); i++)
    {
        t[i]  = sol[i].Get_Time();
        theta[i] = sol[i].Get_Var_ptr()[0];
        omega[i] = sol[i].Get_Var_ptr()[1];
    }

    TGraph *g = new TGraph(n, t, theta);
    g->SetTitle("Pendulum");
    g->GetXaxis()->SetTitle("t(s)");
    g->GetYaxis()->SetTitle("#theta (rad)");
    g->SetMarkerStyle(7);
    g->SetMarkerColor(9);
    g->Draw("AP");
    
    
    c->Update();
    gPad->WaitPrimitive();
    c->SaveAs("pendulum.eps");

    return 0;
}
