#include <iostream>
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"

using namespace std;

/*
 MÉTODO DE RUNGE-KUTTA(2)
 k1 = h f(xn, yn)
 k2 = h f(xn + h/2, yn + K1/2)
 yn+1 = yn + k2 + O(h3)
*/

int main()
{
    TCanvas* canvas = new TCanvas();
    TF1* func = new TF1("func", "2+(x^3)/3", 0, 4);
    
    double t0 = 0.4;
    double tf = 1.8;
    double h  = 0.1;
    
    double y0   = 0.2; //condição inicial
    double steps = (tf - t0)/h;
    
    double* y_values = new double[steps]; //array que guarda as iteradas
    y_values[0] = y0;
    double* x_values = new double[steps]; //array que guarda os valores de t
    x_values[0] = t0;
    
    //Implementação do Método Runge-Kutta ordem 2
    double K1;
    double K2;
    for (int i = 1; i < steps; i++)
    {
        x_values[i] = t0 + i*h;
        K1 = h*(0.5*y_values[i-1] - x_values[i-1] + 1);
        K2 = h*(0.5*(y_values[i-1] + K1/2) - (x_values[i-1] + h/2) + 1);
        y_values[i] = y_values[i-1] + K2;
    }

    TGraph* graph = new TGraph(steps, x_values, y_values);
    graph->SetSize(3);
    
    graph->Draw("AP");
    
    canvas->Update();
    canvas->SaveAs("RK2.pdf");
    return 1;
}
