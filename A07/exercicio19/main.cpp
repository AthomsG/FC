#include <iostream>
#include "exercicio_19.hpp"

using namespace std;

int main()
{
    int n = 3;
    int** mx = matrix(n, n);
    cout << "--- Matriz 1 ---\n";
    print(mx, n, n);
    cout << "----------------\nTraço = " << Trace(mx,n) << endl;

    cout << "Linha 1 = ";
    print_row(1,mx,n,n);
    cout << "Linha 2 = ";
    print_row(2,mx,n,n);
    cout << "Linha 3 = ";
    print_row(3,mx,n,n);

    int * vec = new int[3];

    vec[0]=2;
    vec[1]=3;
    vec[2]=-2;

    vec = vectmatrix(vec,mx,n,n);
    cout << "--- Produto da matriz 1 com o vector (2,3,-22) --- \n";
    cout << vec[0] << " " << vec[1] << " " << vec[2] << endl;

    int** res = matrix(2,3);
    res= matrix_prod(res, mx, 2, 3, n, n);

    print(res, 2, 3);

    for (int i = 0; i < n; i++)
    {
        delete[] mx[i];
    }
    delete res[0];
    delete res[1];
    delete res;
    delete mx;
    delete vec;

    return 1;
}
