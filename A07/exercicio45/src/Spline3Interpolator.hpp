#ifndef Spline3_HPP
#define Spline3_HPP
#include "EqSolver.hpp"
#include "DataPoints.hpp"
#include "TF1.h"
using namespace std;

class Spline3Interpolator : public DataPoints
{
  public:
    Spline3Interpolator(int N=0, double *x=NULL, double *y=NULL, TF1* fF0=NULL);
    ~Spline3Interpolator() {delete FInterpolator; delete F0; delete[] K;}
    double Interpolate(double x); //retorna o valor da funcao interpoladora na abcissa x
    void Draw(string title = "",string x_axis= "",string y_axix= "", Int_t npx = 500, int draw_points= 1); //draw everything (points and interpolation function)
    TF1* GetInterpolationFunction() {return FInterpolator;}
    double Derivative1(double xval);
    void SetFunction(TF1* fF) { delete F0; F0 = (TF1*)fF->Clone();}
    void PrintPlot(string filename = "Spline.eps",string title = "",string x_axis= "",string y_axis= "", Int_t npx = 500); // print results to file (optional)
  private:
    void SetCurvatureLines();
    double fInterpolator(double *fx, double *par) {return Interpolate(fx[0]);}
    double* K; // segundas derivadas
    TF1* FInterpolator; //interpolation function
    TF1* F0;  //eventual underlying function
};

#endif
