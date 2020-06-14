
#include <vector>
#include <string>
#include "TF1.h"
#include "Derivator.hpp"
#define SEPARATOR  "\n---------------\n"

using namespace std;

//No problema em causa, pretende-se encontrar o mínimo do potencial, ponto este onde a respectiva derivada é nula. Como tal, procura-se este mínimo da função, em passos de pow(1, -12) obtidos através da classe Derivator.

int main()
{
    double step = pow(1, -13);
    TF1* potencial = new TF1("potencial", "pow(1.744, -16)*exp(-x/pow(0.33, -10)) - pow(1.6, -19)/(4*3.14*x*pow(8.85, -12))", 0, 1);
    
    Derivator min(potencial);
    double deriv_value = min.Deriv_1(step);
    
    for (int i = 2; deriv_value > 0.0000001; i++)
    {
        deriv_value = min.Deriv_1(i*step);
    }
    cout << "r = " << deriv_value << endl;
    return 1;
}

