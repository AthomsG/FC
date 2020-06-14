#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double volume(float r)
{
    return 3.14 * pow(r, 3)*4/3;
}

int main()
{
    float r;
    
    cout << "Qual o raio da esfera? \n";
    cin  >> r;
    
    cout << volume(r) << "\n";
    
    return 1;
}
