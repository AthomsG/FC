#include <iostream>
#include "exercicio_19.hpp"

using namespace std;

void print(int** mx, int m, int n) //CHECKED
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mx[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n = 3;
    int** mx = matrix(n, n);

    int* vecc = new int[3];

    vecc[0] =  2;
    vecc[1] =  3;
    vecc[2] = -2;
    
    int** vecd = new int*[2];
    
    for (int i = 0; i < 2; i++)
    {
        vecd[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            cout << "Qual o valor do vetor na linha " << i << " colun " << j << endl;
            cin  >> vecd[i][j];
        }
    }

    double trace = Trace(mx, n);
    int i = 1;
    
    cout << "O traço da matriz é = " << trace << "\n";
    
    
    cout << "O produto do vetor com a sua matriz é: " << vectmatrix(vecc, mx, n, n)[0] << " " << vectmatrix(vecc, mx, n, n)[1] << " " << vectmatrix(vecc, mx, n, n)[2];
    
    cout << "O produto pedido na alínea c) é: " << print(bvectmatrix(vecd, mx, 3, 3, 2), 2, 3);
    
    for (int i = 0; i < n; i++)
    {
        delete[] mx[i];
    }
    delete[] mx;
    delete[] vecc;

    return 1;
}
