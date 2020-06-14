#include <iostream>
#include <math.h>

using namespace std;


void primeFactors(int n)
{
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n =/ 2;
    }
    
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {

        while (n % i == 0)
        {
            cout << i << " ";
            n = n/i;
        }
    }
    if (n > 2)
        cout << n << " ";
}


int main()
{
    int n;
    
    cout << "Introduza um número inteiro" << "\n";
    cin  >> n;
    
    primeFactors(n);
    cout << "\n";
    return 0;
}

