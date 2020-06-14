#include "ODEsolver.hpp"
//#include derivator
#include <vector>
#include <string>
#include "TGraph.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TFormula.h"
#define SEPARATOR  "\n---------------\n"

using namespace std;

int main()
{
    double t0      = 0;
    double t1      = 80.1083;
    double steps   = 100000;
    double height  = 8000;
    double dt      = (t1-t0)/steps;
    
    //------------------------Creates Window--------------------------
    TApplication    *    MyRootApp;
    MyRootApp    =    new    TApplication("click    twice",    NULL,    NULL);
    MyRootApp->SetReturnFromRun(true);
    
    TCanvas* c = new TCanvas("c1", "Título");
    //----------------------------------------------------------------
    
    vector<double> c_init;
    c_init.push_back(0);
    ODEpoint init(0, c_init);
    
    TFormula eq_mov("Equação do Movimento", "x[0]*x[0]*(0.08)/(100) - 9.8");
    ODEsolver calculate(eq_mov);
    
    vector<ODEpoint> plot = calculate.RK4solver(init, t0, t1, dt);
    
    double* graph_x = new double[steps];
    double* graph_y = new double[steps];
    
    double* pos_y   = new double[steps];
    pos_y[0]        = height;
    
    for (int i = 0; i < steps; i++)
    {
        graph_x[i] = i*(t1-t0)/steps;
        graph_y[i] = plot[i].Get_Var_vec()[0];
    }
    //Determines Position
    for (int i = 1; i < steps; i++)
    {
        if (pos_y[i-1] < 0.1 and pos_y[i-1] > 0)
        {
            cout << "Ouch! Bati no chão!!. Demorei " << graph_x[i] << "segundos e bati com velocidade " << graph_y[i] << " m/s\n";
        }
        pos_y[i] = pos_y[i-1] + (graph_y[i]*dt);
    }
    
    TGraph speed(steps, graph_x, graph_y);
    speed.Draw();
    
    //----------------------------------------------------------------
    c->Update();
    gPad->WaitPrimitive();
    c->SaveAs("speed.pdf");
    //----------------------------------------------------------------
    
    TGraph pos(steps, graph_x, pos_y);
    pos.Draw();
    
//    //----------------------------------------------------------------
//    c->Update();
//    gPad->WaitPrimitive();
//    c->SaveAs("position.pdf");
//    //----------------------------------------------------------------
    
    delete[] graph_x;
    delete[] graph_y;
    delete[] pos_y;
    
    return 0;
}

