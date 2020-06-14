#include "exercicio_19.hpp"
#include <iostream>

using namespace std;

int** matrix(int m, int n) //PODE SER OTIMIZADO
{
    int** matriz = new int*[m];
    
    for (int i = 0; i < m; i++)
    {
        matriz[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << "Qual o valor da linha " << i << " coluna " << j << "?\n";
            cin  >> matriz[i][j];
        }
    }
    return matriz;
}


double Trace(int** mx, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += mx[i][i];
    }
    return sum;
}


int* vectmatrix(int* vec, int** mx, int m, int n) //produto de um vetor por uma matriz quadrada
{
    int* res = new int[m];
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i] += vec[i] * mx[i][j];
        }
    }
    
    return res;
}

int** bvectmatrix(int* vec, int** mx, int m, int n, int vl)
{
    int** res = new int*[vl];
    for (int i = 0; i < vl; i++)
    {
        res[i] = new int[n];
    }
    
    for (int i = 0; i < vl; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i] += vec[i] * mx[i][j];
        }
    }
    
    return res;
}


int* Mrow(int i, int** mx, int m, int n)
{
    int* linha = new int[n];
    
    for (int j = 0; j < n; j++)
    {
        linha[j] = mx[i][j];
    }
    
    return linha;
}
