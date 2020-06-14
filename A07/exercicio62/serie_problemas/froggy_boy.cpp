#include <iostream>
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"

using namespace std;

int main()
{
    TCanvas* canvas = new TCanvas();
    TF1* func = new TF1("func", "2+(x^3)/3", 0, 4);
    
    double t0 = 0;
    double tf = 4;
    double h  = 0.1;
    
    double y0   = 2.0; //condição inicial
    double steps = (tf - t0)/h;
    
    double* y_values = new double[steps]; //array que guarda as iteradas
    y_values[0] = y0;
    double* x_values = new double[steps]; //array que guarda os valores de t
    x_values[0] = t0;
    x_values[1] = t0+h;
    //Calculada a 1ª iterada através do método de Heun
    y_values[1] = y_values[0] + h*h*h*h*h/2;
    for (int i = 2; i < steps; i++) //Método Leap Frog
    {
        x_values[i] = t0 + i*h;
        y_values[i] = y_values[i-2] + 2*h*(x_values[i-1]*x_values[i-1]);
    }

    TGraph* graph = new TGraph(steps, x_values, y_values);
    func->SetTitle("Leap-Frog");
    func->Draw();
    graph->Draw("PSAME");
    
    canvas->Update();
    canvas->SaveAs("Leap-Frog.pdf");
    return 1;
}

//Este método é mais preciso que o de Euler
