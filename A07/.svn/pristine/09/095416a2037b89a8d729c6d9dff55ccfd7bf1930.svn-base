#include <iostream>
#include "TF1.h"
#include "Derivator.hpp"
#include "Vec.hpp"

using namespace std;

double find_root(TF1* func, double x0, double a, double b, double err=0, int type=0)
{
    if (func->Eval(a)*func->Eval(b) > 0)
    {
        cout << "Err-- Root is not guaranteed\n";
        exit(EXIT_FAILURE);
    }
    if (type > 3 or type < 0)
    {
        cout << "Err-- Type has to be in range 3\n";
        exit(EXIT_FAILURE);
    }
    if (a > b)
    {
        double* save = new double;
        *save = a;
        a = b;
        b = *save;
        delete save;
    }
    double root = x0;
    switch(type)
    {
        case 0: //Método da bissecção
        {
            double dist = b - a;
            int k = 0;
            root = (b + a)/2;
            while((dist)/(pow(2,k)) > err)
            {
                if (func->Eval(root)==0)
                {break;}
                if(func->Eval(root)*func->Eval(a)>0)
                {a = root;}
                else
                {b = root;}
                root = (b + a)/2;
                k++;
            }
            break;
        }
        case 1: //Método Regula falsi
        {
            double* save = new double;
            *save = root;
            while(1)
           {
               root = a - (func->Eval(a))/((func->Eval(b) - func->Eval(a))/(b-a));
               
               if(abs(*save-root)<err)//critérios de paragem
               {break;}
               if (func->Eval(root)==0)
               {break;}
               
               *save = root;
               if(func->Eval(root)*func->Eval(a)>0)
               {a = root;}
               else
               {b = root;}
           }
            delete save;
            break;
        }
        case 2://Método Newton-Raphson
        {
            Derivator derp(func);
            double* save = new double;
            *save = root;
            while(1)
            {
                root = root - func->Eval(root)/derp.Deriv_1(root, 0.001);
                if(abs(*save-root)<err)//critérios de paragem
                {break;}
                if (func->Eval(root)==0)
                {break;}
                
                *save = root;
            }
            delete save;
            break;
        }
        case 3: //método da Secante
        {
            Derivator derp(func);
            Vec* save = new Vec;
            save->push_back(a);
            root = b;
            while(1)
            {
                root = root - func->Eval(root)*((root - save[0][0])/(func->Eval(root)-func->Eval(save[0][0])));
                
                if(abs(save[0][0]-root)<err or save->Size() == 10)//critérios de paragem
                {break;}
                if (func->Eval(root)==0)
                {break;}
                save->push_front(root);
            }
            delete save;
            break;
        }
    }
    return root;
}

int main()
{
    
    //TESTE DO MÉTODO
//    TF1* func   = new TF1("func", "x*x - 1", 0, 2);
//    double root = find_root(func, 1, 0, 2, 0.001, 0);
//    cout << "dis Root be like, I'm equal to: " << root << endl;
//
//    root = find_root(func, 1, 0, 2, 0.001, 1);
//    cout << "dis Root be like, I'm equal to: " << root << endl;
//
//    root = find_root(func, 1, 0, 2, 0.001, 2);
//    cout << "dis Root be like, I'm equal to: " << root << endl;
//
//    root = find_root(func, 1, 1, 2, 0.001, 3);
//    cout << "dis Root be like, I'm equal to: " << root << endl;
//    return 0;
    double omega = 2.7 * pow(10, -6);
    double G = 6.674*pow(10, -11);
    double Mterra = 5.972*pow(10, 24);
    double R = 384402*pow(10, 3);
    double Mlua = 7.348*pow(10, 22);
    
    TF1* func = new TF1("oi", "[0]*[1]/(x*x) -[4]*[4]*x - [0]*[2]/(([3] - x)*([3] - x))");
    
    func->SetParameter(0, G);
    func->SetParameter(1, Mterra);
    func->SetParameter(2, Mlua);
    func->SetParameter(3, R);
    func->SetParameter(4, omega);
    
    double root = find_root(func, 0, 10E+12, 0.2, 3);
    cout << root << endl;
    return 0;
}
