#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int save, num, lst, frst, mddl, cnt = 1;
    
    cout << "Introduza um número: \n";
    cin  >> num;
    
    save = num;
    lst  = num%10;
    num /= 10;
    
    while (num >= 10)
    {
        num /= 10;
        cnt ++;
    }
    
    frst = num;
    
    cout << "primeiro dígito    = " << frst << "\n";
    cout << "último dígito      = " << lst  << "\n";
    cout << "número introduzido = " << save << "\n";
    cout << "dígitos trocados   = " << lst  * pow(10, cnt) + frst + save - frst * pow(10, cnt) - lst << "\n";
    
    return 1;
}
