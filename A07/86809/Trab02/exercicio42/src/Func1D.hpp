#ifndef FUNC1D_HPP
#define FUNC1D_HPP
#include <string>
#include "TF1.h"
using namespace std;

class Func1D
{
  public:
    Func1D() {;}
    Func1D(TF1* ff);
    virtual ~Func1D();
    void SetFunc(TF1*);
    TF1* GetFunc() const;
    void Draw(string filename = "Func1D.eps",string title = "Func1D",string x_axis = "", string y_axis = "", Int_t npx = 500);
    double Evaluate(double x);
  protected:
    TF1* F;
    static int Nplots;
};

#endif
