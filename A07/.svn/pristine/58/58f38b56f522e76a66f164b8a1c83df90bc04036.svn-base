#ifndef NEWTON_HPP
#define NEWTON_HPP
#include "DataPoints.hpp"
#include "TF1.h"
using namespace std;

class NewtonInterpolator : public DataPoints
{
  public:
    NewtonInterpolator(int N=0, double *x=NULL, double *y=NULL, TF1* fF0=NULL);
    ~NewtonInterpolator() {delete FInterpolator; delete F0;}
    double DiffTable(int, int);
    double Interpolate(double x); //retorna o valor da funcao interpoladora na abcissa x
    TF1* GetInterpolationFunction() {return FInterpolator;}
    void SetFunction(TF1* fF) { delete F0; F0 = (TF1*)fF->Clone();}
    void Draw(string title= "",string x = "",string y = "", Int_t npx = 500); //draw everything (points and interpolation function)
    void PrintPlot(string filename = "Newton.eps",string title= "",string x= "",string y= "", Int_t npx = 500); // print results to file (optional)
  private:
    double fInterpolator(double *fx, double *par) {return Interpolate(fx[0]);}
    TF1* FInterpolator; //interpolation function
    TF1* F0;  //eventual underlying function
};

#endif
