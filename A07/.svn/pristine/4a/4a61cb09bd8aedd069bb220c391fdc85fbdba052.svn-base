#include <vector>
#include <string>
#include <iostream>

using namespace std;
//
// #include "Vec.hpp"
// #include "FCmatrix.hpp"
// #include "FCmatrixFull.hpp"
// #include "FCmatrixBanded.hpp" // eqsolver inclui todos estes
#include "EqSolver.hpp"

#define SEPARATOR "\n\n-----------------\n\n"

int main()
{
    cout << SEPARATOR;

//    double** A = new double*[3];
//    for(int i=0; i<4 ; i++) { A[i] = new double[3]; }
//
//    A[0][0]=1;  A[0][1]=1; A[0][2]=-1;
//    A[1][0]=1; A[1][1]=-2;  A[1][2]=3;
//    A[2][0]=2;  A[2][1]=3; A[2][2]=1;
//
//
//    FCmatrixFull M1(A,3,3);
//    M1.Print();

    double** A = new double*[4];
    for(int i=0; i<4 ; i++) { A[i] = new double[4]; }

    A[0][0]=2;  A[0][1]=4; A[0][2]=0;  A[0][3]=0;
    A[1][0]=-1; A[1][1]=10;  A[1][2]=2; A[1][3]=0;
    A[2][0]=0;  A[2][1]=2; A[2][2]=20;  A[2][3]=5;
    A[3][0]=0;  A[3][1]=0;  A[3][2]=-3; A[3][3]=5;

    FCmatrixFull M1(A,4,4);
    M1.Print();

    FCmatrixBanded bandida(M1);
    cout << "\nWith corresponding Banded:\n\n";
    bandida.Print();

    cout << "\nDeterminante = " << M1.Determinant();

    cout << SEPARATOR;

//    Vec b1(2,2);
//    b1.push_back(2);
//    b1.push_front(2);
    Vec b1;
    b1.push_back(4);
    b1.push_back(-6);
    b1.push_back(7);
    b1.push_back(1);
    b1.Print();

    cout << SEPARATOR;

    EqSolver s1(M1,b1);

    cout << "Using Gauss Elimination: --\n\n";
    s1.GaussEliminationSolver().Print();

    cout << SEPARATOR;

    cout << "Using Thomas Algorithmn: --\n\n";
    s1.TridiagonalSolver().Print();

    cout << SEPARATOR;

    cout << "Using DooLittle decomposition: --\n\n";
    s1.LUdecompositionSolver_Doolittle().Print();

    cout << SEPARATOR;

    double* mb1_values = new double[10]{1,4,5,
                                        -1,2,-1,2,
                                        7,8,9};
    FCmatrixBanded MB1(mb1_values,4);
    EqSolver eq1(MB1,b1);
    eq1.PrintM();
    eq1.TridiagonalSolver().Print();

    cout << "--FIM DO CÓDIGO--";

    for (int i = 0; i < 4; i++)
    {
        delete[] A[i];
    }
    delete[] A;
    delete[] mb1_values;

    FCmatrixFull m(3,3,1);
    m[0][1]= 112.5; m[0][2]= 0; m[1][1]=-3.25;
    m[1][2]=3.25; m[2][1]=0; m[2][2]=-112.5;

    Vec b(3);
    b[0]=32737.5;
    b[2]=-31387.5;

    EqSolver eq(m,b);
    b=eq.GaussEliminationSolver();

    b.Print();

    cout << SEPARATOR;

    FCmatrixFull mj(3,3);
    mj[0][0] = 3.1; mj[0][1] = 2; mj[0][2] = 1;
    mj[1][0] = 1; mj[1][1] = 2.1; mj[1][2] = 1;
    mj[2][0] = 2; mj[2][1] = 2; mj[2][2] = 9;

    Vec bj(3);
    bj[0] = 1; bj[1] = 2; bj[2] = -1;

    EqSolver eqj(mj,bj);
    eqj.GaussEliminationSolver().Print();
    eqj.LUdecompositionSolver_Doolittle().Print();
    eqj.JacobiSolver().Print();
 ///////////////////////////////////////////////////////////////////////////
  /*  double** entries = new double*[100];
    for(int i =0; i<100; i++)
    {
      entries[i] = new double[100];
      for(int j=0; j<100; j++)
      {
        entries[i][j]=0;
      }
    }
    FCmatrixFull(entries,100,100);

    cout << SEPARATOR;*/

    return 0;
}
