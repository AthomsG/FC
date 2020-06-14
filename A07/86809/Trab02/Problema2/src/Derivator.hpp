#ifndef Derivator_hpp
#define Derivator_hpp
#include "Func1D.hpp"

using namespace std;

class Derivator: public Func1D
{
  public:
    Derivator(TF1 *f = NULL);
    Derivator(const Derivator&);
    ~Derivator() {;}
    double Deriv_1(double x, double h=.001, int type=0);
    double Deriv_2(double x, double h=.001, int type=0);
    double Deriv_3(double x, double h=.001, int type=0);
    double Deriv_4(double x, double h=.001, int type=0);
};

#endif

// type
// = 0 : central
// = 1 : forward
// = 2 : backward
