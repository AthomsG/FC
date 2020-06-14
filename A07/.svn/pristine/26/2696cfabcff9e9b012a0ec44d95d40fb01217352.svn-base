#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"
#include "FCmatrixBanded.hpp"

#include "EqSolver.hpp"

#define SEPARATOR "\n\n-----------------\n\n"

EqSolver::EqSolver()
{}

EqSolver::EqSolver(const FCmatrixFull& matriz, const Vec& vetor)
{
    b = vetor;
    M = matriz;
}

EqSolver::EqSolver(const FCmatrixBanded& matriz, const Vec& vetor)
{
    b = vetor;
    M = matriz.GetFull();
}

void EqSolver::SetConstants(const Vec& vetor)
{
    b = vetor;
}

void EqSolver::SetMatrix(const FCmatrixFull& matriz)
{
    M = matriz;
}

FCmatrixFull EqSolver::GaussElimination(FCmatrixFull& matriz, Vec& vetor) //checked
{
    //check if system is not undetermined...
   if (matriz.Determinant() == 0)
    {
        cout << "Erro-- a matriz tem determinante igual a zero\n";
        exit(EXIT_FAILURE);
    }

    int size = matriz.Get_nRows();
    int drow = 0;
    double coef = 0;
    FCmatrixFull L(size,size);
    //Elimination Stage - PARTIAL PIVOTING
    for (int i = 0; i < size - 1; i++)
    {
        drow = matriz.GetColMax(i);
        matriz.swapRows(i, drow);
        vetor.Swap(i, drow);

        for (int j = i+1; j < size; j++)
        {
            coef       = matriz[j][i]/matriz[i][i];
            L[j][i]    = coef;
            matriz[j] -= matriz[i]*coef;
            vetor[j]  -= vetor[i]*coef;
        }
    }
    return L;
}

Vec EqSolver::GaussEliminationSolver()//checked
{
    FCmatrixFull matriz = this->M;
    Vec res = this->b;
    this->GaussElimination(matriz, res);

    int row_size = matriz.Get_nRows();

    double coef;
    //Back Substitution Stage
    for (int i = row_size - 1; i >= 1; i--)
    {
        for (int j = i-1; j >= 0; j--)
        {
            coef = matriz[j][i]/matriz[i][i];
            matriz[j] -= matriz[i]*coef;
            res[j] -= res[i]*coef;
        }
    }
    for (int i = 0; i < row_size; i++)
    {
        res[i] /= matriz[i][i];
    }
    return res;
}

Vec EqSolver::LUdecompositionSolver_Doolittle()
{
    FCmatrixFull* matriz = new FCmatrixFull(M);
    Vec vetor = this->b;
    matriz = this->LUdecomposition_Doolittle(*matriz, vetor);

    int size = matriz->Get_nRows();

    //upper
    vetor[size - 1] /= matriz[0][size - 1][size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < size; j++)
        {
            vetor[i] -= vetor[j]*matriz[0][i][j];
        }
        vetor[i] /= matriz[0][i][i];
    }
    delete matriz;
    return vetor;
}

FCmatrixFull* EqSolver::LUdecomposition_Doolittle(FCmatrixFull& matriz, Vec& vetor) //checked
{
    /*int size = matriz.Get_nCols();
    FCmatrixFull* Z = new FCmatrixFull(matriz);
    *Z = *Z + GaussElimination(*Z, vetor);
    //checks if determinant != 0
    return Z;*/
    matriz = matriz + GaussElimination(matriz, vetor);
    return &matriz;
}

Vec EqSolver::JacobiSolver(double tol)
{
    if(b.Size() != M[0].Size()) { cout << "Error-- matriz n quadrada\n"; exit(EXIT_FAILURE);}
  //	linear	system	of	m	unknowns
		int	m = b.Size();
		Vec	x(m);	//full	of	0
		Vec x_last(m);	//stores	last	iteration
		bool	btol	=	false;
		int	it	=	0.;

    //check if matrix is diagonally dominant
    double aux;
    for(int i=0; i<m;i++)
    {
      aux = 0;
      for(int j = 0; j<m; j++)
      {
        if (i!=j) {aux+=fabs(M[i][j]);}
      }
      if (fabs(M[i][i])<=aux) {cout << "Error-- matriz nao e estritamente diagonal dominante\n"; exit(EXIT_FAILURE);}
    }

		while	(!btol	&&	(it	<	1000))
    {
				x_last=	x;
        btol = true;
				for	(int i=0;	i<m;	i++)
        {
						x[i]	=	0.;
						for	(int	j=0;	j<m;	j++)
								if	(i	!=	j)	x[i]	+=	-M[i][j]*x_last[j];
						x[i]	+=	b[i];
						x[i]	/=	M[i][i];
            if	(fabs(x[i]-x_last[i])	>=	tol)	btol	=	false;
				}
				it++;
		}
		return	x;
}


Vec EqSolver::TridiagonalSolver() //checked
{
    if(M.Get_nCols()==1)
    {
        Vec result(1);
        result[0]= b[0]/M[0][0];
        return result;
    }

    FCmatrixBanded res(this->M);
    int n = M.Get_nRows() - 1;
    Vec d = this->b;

    res[0].push_front(0);
    res[2].push_back(0);

    //Thomas Algorithm, made by Thomas!
    res[2][0] /= res[1][0];
    d[0] /= res[1][0];
    for (int i = 1; i < n; i++) {
        res[2][i] /= res[1][i] - res[0][i]*res[2][i-1];
        d[i] = (d[i] - res[0][i]*d[i-1]) / (res[1][i] - res[0][i]*res[2][i-1]);
    }

    d[n] = (d[n] - res[0][n]*d[n-1]) / (res[1][n] - res[0][n]*res[2][n-1]);

    for (int i = n-1; i >= 0; i--) {
        d[i] -= res[2][i]*d[i+1];
    }
    return d;
}
