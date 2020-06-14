#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#include "atom.hpp"

void print(vector<ATOM> veccy_boy)
{
    for (int i = 0; i < veccy_boy.size(); i++)
    {
        print(veccy_boy[i]);
    }
}

void print(ATOM atm)
{
    cout << "Elemento: " << atm.name << endl;
    cout << "Numero Atomico: " << atm.Z << endl;
    cout << "Numero de Massa: " << atm.A << endl << endl;
}

vector<ATOM> vperiodic()
{
    vector<ATOM> veccy_boy;

    ATOM n1, n2, n3, n4;

    n1.name = "Hidrogénio";
    n2.name = "Hélio";
    n3.name = "Lítio";
    n4.name = "Berílio";

    n1.A    = 1.008;
    n2.A    = 4.0026;
    n3.A    = 6.94;
    n4.A    = 9.0122;

    n1.Z    = 1;
    n2.Z    = 2;
    n3.Z    = 3;
    n4.Z    = 4;

    veccy_boy.push_back(n1);
    veccy_boy.push_back(n2);
    veccy_boy.push_back(n3);
    veccy_boy.push_back(n4);

    return veccy_boy;
}
