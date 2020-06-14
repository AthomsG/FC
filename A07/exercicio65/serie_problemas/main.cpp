#include "ODEpoint.hpp"
#include "ODEsolver.hpp"
#include "TFormula.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TF1.h"
#include <iostream>
#include <string>

#define SEPARATOR "\n------------\n"

using namespace std;

/*int main()
{
   vector<TFormula> var;
   TFormula func1("1", "x");
   TFormula func2("2", "y");
   TFormula func3("3", "z");
   TFormula func4("4", "t");

   var.push_back(func1);
   var.push_back(func2);
   var.push_back(func3);
   var.push_back(func4);

   double* oi_vec = new double[4] {0, 1, 0, 0};

   ODEpoint oi(0, oi_vec, 4);
   ODEsolver eq(var);
   cout << "var size = " << var.size() << endl;
   cout << "dim = " << oi.GetNdim() << endl;

   vector<ODEpoint> sol1 = eq.Heun(oi, 1, 2.1, 0.005);
   vector<ODEpoint> sol_euler = eq.Eulersolver(oi, 1, 2.1, 0.005);
   vector<ODEpoint> sol3 = eq.RK2solver(oi, 1, 2.1, 0.005);
   vector<ODEpoint> sol4 = eq.RK4solver(oi, 1, 2.1, 0.005);


   sol_euler[sol_euler.size()-1].Print();
   cout << SEPARATOR;
   sol1[sol1.size()-1].Print();
   cout << SEPARATOR;
   sol3[sol1.size()-1].Print();
   cout << SEPARATOR;
   sol4[sol1.size()-1].Print();


   return 0;
}*/

//EXERCÍCIO 65
int main()
{
    TApplication	*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);

    TCanvas* c = new TCanvas("c1", "Título");

    TFormula func1("exercicio 65_1", "0.5*x - ");

    vector<TFormula> vec;
    vec.push_back(func1);
    ODEsolver eq(vec);

    vector<double> init;
    init.push_back(0.2);
    ODEpoint  oi(0.4, init);

    vector<ODEpoint> sol_euler = eq.Eulersolver(oi, 0.4, 2, 0.1);
    vector<ODEpoint> sol_rk2 = eq.RK2solver(oi, 0.4, 2, 0.1);
    vector<ODEpoint> sol_rk4 = eq.RK4solver(oi, 0.4, 2, 0.1);

    cout << SEPARATOR;
    cout << "Euler\n";
    sol_euler[sol_euler.size()-1].Print();
    cout << SEPARATOR;
    cout << "RK2\n";
    sol_rk2[sol_rk2.size()-1].Print();
    cout << SEPARATOR;
    cout << "RK4\n";
    sol_rk4[sol_rk4.size()-1].Print();
    cout << SEPARATOR;

    double* y2 = new double[sol_euler.size()];
    double* y3 = new double[sol_rk2.size()];
    double* y4 = new double[sol_rk4.size()];
    double* x  = new double[sol_rk4.size()];

    for(int i = 0; i < sol_euler.size(); i++)
    {
        x[i]  = 0.4 + i*((1.6)/sol_euler.size());
        y2[i] = *sol_euler[i].Get_Var_ptr();
        y3[i] = *sol_rk2[i].Get_Var_ptr();
        y4[i] = *sol_rk4[i].Get_Var_ptr();
    }

    TGraph* g2 = new TGraph(sol_euler.size(), x, y2);
    g2->SetNameTitle("Euler","Euler");
    TGraph* g3 = new TGraph(sol_rk2.size(), x, y3);
    g3->SetNameTitle("RK2","RK2");
    TGraph* g4 = new TGraph(sol_rk4.size(), x, y4);
    g4->SetNameTitle("RK4","RK4");

    g2->SetLineColor(0);

    g3->SetMarkerColor(2);
    g3->SetMarkerStyle(2);

    g2->SetMarkerColor(4);
    g2->SetMarkerStyle(2);

    g4->SetMarkerColor(6);
    g4->SetMarkerStyle(2);

    g2->Draw("AP");
    g3->Draw("PSAME");
    g4->Draw("PSAME");

    TF1* sol = new TF1("f1","-2.6*exp(0.5*x-0.2)+2*x+2",0,2);
    sol->SetTitle("Solution");
    sol->SetLineColor(3);

    sol->Draw("SAME");

    c->BuildLegend();
    c->Update();
    gPad->WaitPrimitive();
    c->SaveAs("ex_65.eps");

    return 0;
}

//int main()
//{
//    TFormula func("1", "x + y");
//    double* vals = new double[2] {1, 7};
//    double* t = new double {20};
//    cout << func.EvalPar(vals, t);
//}
