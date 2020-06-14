#include <iostream>

using namespace std;

double fact(int* w)
{
    double  res  = 1;
    
    while(*w > 1)
    {
        res = *w * res;
        *w  = *w - 1;
    }
    return res;
}

int main()
{
    int var;
    
    cout << "introduza um número: \n";
    cin  >> var;
    cout << "factorial = " << fact(&var) << "\n";
    
    return 1;
}
