#include <iostream>
#include "Derivator.hpp"
using namespace std;

Derivator::Derivator(TF1* ff) : Func1D(ff){}

Derivator::Derivator(const Derivator& cpy) : Func1D(cpy.F)
{}

double Derivator::Deriv_1(double x, double h, int type) // erro de ordem h^2
{
    double res;
    switch(type)
    {
        case 0: // central differences
        {
            res = (F->Eval(x + h) - F->Eval(x - h))/(2*h);
            break;
        }
        case 1: // forward differences
        {
            res = (4*F->Eval(x + h)-F->Eval(x + 2*h) - 3 * F->Eval(x))/(2*h);
            break;
        }
        case 2: // backwards differences
        {
            res = (F->Eval(x - 2*h) - 4*F->Eval(x - h) + 3 * F->Eval(x))/(2*h);
            break;
        }
    }
    return res;
}

double Derivator::Deriv_2(double x, double h, int type) // erro de ordem h^3
{
    double res;
    switch(type)
    {
        case 0: // central differences
        {
            res = (-4*F->Eval(x)+F->Eval(x+h)+F->Eval(x-h)+F->Eval(x+2*h)+F->Eval(x-2*h))/(5*h*h);//(F->Eval(x+h)-2*F->Eval(x)+F->Eval(x-h))/(h*h);
            break;
        }
        case 1: // forward differences
        {
            res = (35*F->Eval(x)-104*F->Eval(x+h)+114*F->Eval(x+2*h)-56*F->Eval(x+3*h)+11*F->Eval(x+4*h))/(12.*h*h);//(F->Eval(x)-2*F->Eval(x+h)+F->Eval(x+2*h))/(h*h);
            break;
        }
            case 2: // backwards differences
        {
            res = (+35*F->Eval(x)-104*F->Eval(x-h)+114*F->Eval(x-2*h)-56*F->Eval(x-3*h)+11*F->Eval(x-4*h))/(12.*h*h);//(F->Eval(x) -2*F->Eval(x-h) +F->Eval(x-2*h))/(h*h);
            break;
        }
    }
    return res;
}

double Derivator::Deriv_3(double x, double h, int type) // erro de ordem h^2
{
    double res;
    switch(type)
    {
        case 0: // central
        {
            res = (2*F->Eval(x-h)-F->Eval(x-2*h)-2*F->Eval(x+h)+F->Eval(x+2*h))/(2*h*h*h); // erro de ordem h^4: (-13*F->Eval(x+h)+13*F->Eval(x-h)+8*F->Eval(x+2*h)-8*F->Eval(x-2*h)-F->Eval(x+3*h)+F->Eval(x-3*h))/(8*h*h*h);
            break;
        }
        case 1: // forwards
        {
            res = (-5*F->Eval(x)+18*F->Eval(x+h)-24*F->Eval(x+2*h)+14*F->Eval(x+3*h)-3*F->Eval(x+4*h))/(2*h*h*h);//-(F->Eval(x)-3*F->Eval(x+h)+3*F->Eval(x+2*h)-F->Eval(x+3*h))/(h*h*h);
            break;
        }
        case 2: // backwards
        {
            res = (5*F->Eval(x)-18*F->Eval(x-h)+24*F->Eval(x-2*h)-14*F->Eval(x-3*h)+3*F->Eval(x-4*h))/(2*h*h*h);
            break;
        }
    }
    return res;
}

double Derivator::Deriv_4(double x, double h, int type) // erro de ordem h^3
{
    double res;
    switch(type)
    {
        case 0: // central differences
        {
            res = (-44*F->Eval(x)+21*F->Eval(x+h)+21*F->Eval(x-h)+6*F->Eval(x+2*h)+6*F->Eval(x-2*h)-5*F->Eval(x+3*h)-5*F->Eval(x-3*h))/(-24*h*h*h*h); //-- AINDA NÃO FOI IMPLEMENTADA --
            break;
        }
        case 1: // forward differences
        {
            res = (3*F->Eval(x)-14*F->Eval(x+h)+26*F->Eval(x+2*h)-24*F->Eval(x+3*h)+11*F->Eval(x+4*h)-2*F->Eval(x+5*h))/(h*h*h*h);//(1147*F->Eval(x)-4602*F->Eval(x+h)+6375*F->Eval(x+2*h)-2420*F->Eval(x+3*h)-2175*F->Eval(x+4*h)+2238*F->Eval(x+5*h)-563*F->Eval(x+6*h))/(570*h*h*h*h);//-(F->Eval(x+h) - F->Eval(x) - Deriv_1(x, h, type) - Deriv_2(x, h, type) - Deriv_3(x, h, type))/3;
            break;
        }
        case 2: // backwards differences
        {
            res = (3*F->Eval(x)-14*F->Eval(x-h)+26*F->Eval(x-2*h)-24*F->Eval(x-3*h)+11*F->Eval(x-4*h)-2*F->Eval(x-5*h))/(h*h*h*h);
            break;
        }
    }
    return res;
}
