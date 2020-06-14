#include <iostream>
#include <math.h>

using namespace std;

long converter(int w)
{
    long res = 0;
    for (int count = 0; w > 0; count++){
        if (w % 2 != 0){
            res += pow(10, count);
            w --;
        }
        w /= 2;
    }
    return res;
}

int main()
{
    int n;

    cout << "Introduza um número em base decimal: ";
    cin  >> n;

    cout << "Conversao para binario: " << converter(n) << endl;

    return 0;
}
