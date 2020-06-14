#include <iostream>
#include "TF1.h"
#include "TGraph.h"
#include "TCanvas.h"

using namespace std;

//double** Euler()
//{
//    double t0 = 0;
//    double tf = 4;
//    double h  = 0.1;
//
//    double y0   = 2.0; //condição inicial
//    double steps = (tf - t0)/h;
//
//    double* y_values = new double[steps]; //array que guarda as iteradas
//    y_values[0] = y0;
//    double* x_values = new double[steps]; //array que guarda os valores de t
//    x_values[0] = t0;
//    for (int i = 0; i < steps-1; i++)
//    {
//        y_values[i+1] = y_values[i] + h*(h*h*i*i);
//        x_values[i+1] = i*h;
//    }
//    double** res = new double*[2];
//    res[0] = new double[steps];
//    res[0] = x_values;
//
//    res[1] = new double[steps];
//    res[1] = y_values;
//
//    return res;
//}

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
    
    for (int i = 0; i < steps-1; i++)
    {
        x_values[i+1] = (i+1)*h;
        y_values[i+1] = y_values[i] + h*h*h*(i*i + (i+h)*(i+h))/2;
    }

    TGraph* graph = new TGraph(steps, x_values, y_values);
    func->SetTitle("HUNDE");
    func->Draw();
    graph->Draw("PSAME");
    
    canvas->Update();
    canvas->SaveAs("HUNDE.pdf");
    return 1;
}

//Este método é mais preciso que o de Euler
