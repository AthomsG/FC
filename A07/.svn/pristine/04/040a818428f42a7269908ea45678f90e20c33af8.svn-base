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
    for(int i =0; i<m; i++)
    {
      res[i]=0;
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res[i] += vec[j] * mx[i][j];
        }
    }
    return res;
}

int* Mrow(int i, int** mx, int m, int n) // i=1 -> primeira linha (0 na memoria)
{
    int* linha = new int[n];

    for (int j = 0; j < n; j++)
    {
        linha[j] = mx[i-1][j];
    }

    return linha;
}

void print_row(int i, int** mx, int m, int n)
{
    int*linha = Mrow(i,mx,m,n);
    for (int j=0; j<n;j++)
    {
      cout << linha[j] << " ";
    }
    cout << endl;
    delete linha;
}

int** matrix_prod(int** mx1, int** mx2, int m1, int n1, int m2, int n2)
{
    //Verifica se produto é possível
    if (n1 != m2)
    {
        cout << "O produto entre estas 2 matrizes é impossível!";
        return NULL;
    }

    int **res = new int*[m1];
    for (int i = 0; i < m1; i++)
    {
        res[i] = new int[n2];
    }

    //O vetor res é automaticamente inicializado a 0's

    for (int i = 0; i < m1; i++)
    {
        for (int k = 0; k < n2; k++)
        {
            for (int j = 0; j < n2; j++)
            {
                res[i][k] += mx1[i][j] * mx2[j][k];
            }
        }
    }
    return res;
}


void print(int** mx, int m, int n) // CHECKED;
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
