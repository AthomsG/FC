#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
// #include "Vec.hpp"
// #include "FCmatrix.hpp"
// #include "FCmatrixFull.hpp" //ja nao e preciso incluir pq a bended inclui todos
#include "FCmatrixBanded.hpp"

#define SEPARATOR "\n\n-----------\n\n"

//este ficheiro serve para testar e fazer debugging aos metodos implementados
// nas classes FCmatrix e derivadas

int main()
{
  double** A = new double*[3];
  for(int i =0; i<3; i++) { A[i]=new double[4]; }
  A[0][0]= 8; A[0][1]= -2; A[0][2]= 1; A[0][3]= 4;
  A[1][0]= 3; A[1][1]= 1; A[1][2]= -1.5; A[1][3]= 5;
  A[2][0]= 0.5; A[2][1]= 0; A[2][2]= 3; A[2][3]= 3;

  FCmatrixFull MA(A,3,4);
  MA.Print();
//valgrind --num-callers=30 --suppressions=$ROOTSYS/etc/valgrind-root.supp root.exe -l -b -q myscript.C
  cout << SEPARATOR;

  FCmatrixFull MA_copy(MA);
  MA_copy.Print();

  cout << SEPARATOR;

  MA_copy=MA_copy*1.5;
  MA_copy.Print();

  cout << SEPARATOR;

  MA_copy=(2/3.0)*MA_copy;
  MA_copy.Print();

  cout << SEPARATOR;

  double* B = new double[18];
  B[0]= -5; B[1]= -2; B[2]= 4.4; B[3]= 1; B[4]= 12; B[5]= -19;
  B[6]= 7; B[7]= 0.006; B[8]= 17.7; B[9]= 61; B[10]= 0; B[11]= -8;
  B[12]= -58; B[13]= 14; B[14]= 4.5; B[15]= 13; B[16]= 166; B[17]= 0;

  FCmatrixFull MB(B,3,6);
  MB.Print();

  cout << SEPARATOR;

  vector<Vec> C;
  Vec c1(6,121);
  C.push_back(c1);
  Vec c2(6,7.7);
  C.push_back(c2);
  Vec c3(6,-12);
  C.push_back(c3);

  FCmatrixFull MC(C);
  MC=MC+MB;
  MC.Print();

  cout << SEPARATOR;

  double* D = new double[18];
  for (int i =0; i<18; i++) {D[i]=100;}

  FCmatrixFull MD(D,3,6);
  MC=MC-MD;
  MC.Print();

  cout << SEPARATOR;

  cout << "Nr linhas = " << MC.Get_nRows() << endl;
  cout << "Nr colunas = " << MC.Get_nCols() << endl;

  cout << SEPARATOR;

  //produto interno das duas primeiras linhas de MC
  cout << MC.GetM()[0].Dot(MC.GetM()[1]) << endl;

  cout << SEPARATOR;

  double* E = new double[18];
  for (int i =0; i<18; i++) {D[i]=3+i;}

  FCmatrixFull ME(D,6,3);
  ME=MC*ME;
  ME.Print();

  cout << SEPARATOR;

  cout << "Nr linhas = " << ME.Get_nRows() << endl;
  cout << "Nr colunas = " << ME.Get_nCols() << endl;

  cout << SEPARATOR;

  ME.GetCol(0).Print();
  ME.GetCol(1).Print();
  ME.GetCol(2).Print();

  cout << SEPARATOR;

  cout << "Matriz ME: \n\n";
  ME.GetRow(0).Print();
  ME.GetRow(1).Print();
  ME.GetRow(2).Print();

  cout << SEPARATOR;

  cout << "Maximo de cada linha de ME: \n";
  cout << ME.GetRow(0)[ME.GetRowMax(0)] << endl;
  cout << ME.GetRow(1)[ME.GetRowMax(1)] << endl;
  cout << ME.GetRow(2)[ME.GetRowMax(2)] << endl;

  cout << SEPARATOR;

  cout << "Em cada coluna j, elemento na linha i>=j que e o mais elevado na sua linha (relativamente): \n";
  cout << ME.GetCol(0)[ME.GetColMax(0)] << endl;
  cout << ME.GetCol(1)[ME.GetColMax(1)] << endl;
  cout << ME.GetCol(2)[ME.GetColMax(2)] << endl;

  cout << SEPARATOR;

  ME.swapRows(0,1);
  ME.Print();

  cout << SEPARATOR;

  FCmatrixFull dummy(5,5,-1);
  dummy.Print();

  cout << "\nDeterminante = " << dummy.Determinant() << " (verifica-se)"<< endl;

  cout << SEPARATOR;

  dummy[0][0]=2.6;
  dummy[1][1]=7.4;
  dummy[2][2]=-6.1;
  dummy[3][3]=9.9;
  dummy[4][4]= 11.8;
  for(int i =0; i<5; i++) {dummy[i].Print();}

  cout << "\nDeterminante = " << dummy.Determinant() << " (verifica-se)"<< endl;

  cout << SEPARATOR;

    FCmatrixFull MG(5*dummy*2);
    MG.Print();

  cout << SEPARATOR;

  FCmatrixFull test(3,3);
  test[0][0]=-1; test[0][1]=1; test[0][2]=12;
  test[1][0] = 0; test[1][1]=7; test[1][2]=4;
  test[2][0]=4; test[2][1]=5; test[2][2]=3;

  test.Print();

  cout << "\nDeterminante = " << test.Determinant() << " (verifica-se)"<<endl;

  cout << SEPARATOR;

  int size_f = 8;
  double** F = new double*[size_f];
  for(int i=0; i<size_f; i++)
  {
    F[i] = new double[size_f];
    for(int j=0; j<size_f; j++)
    {
      F[i][j]=i+j;
    }
  }
  test.SetEntries(F,size_f,size_f);
  test.Print();

  cout << "\nDeterminante = " << test.Determinant() <<endl;

  cout << SEPARATOR;

  double** H = new double*[4];
  for(int i =0; i<4; i++) { H[i]=new double[4]; }
  H[0][0]= 8; H[0][1]= -2; H[0][2]= 1; H[0][3]= 4;
  H[1][0]= 3; H[1][1]= 1; H[1][2]= -1.5; H[1][3]= 5;
  H[2][0]= 0.5; H[2][1]= 0; H[2][2]= 3; H[2][3]= 3;
  H[3][0]= 8; H[3][1]= 4; H[3][2]= -2; H[3][3]= 6;

  FCmatrixFull MH(H,4,4);
  MH.Print();
  cout << endl << MH.GetColMax(0);
  cout << endl << MH.GetColMax(1);
  cout << endl << MH.GetColMax(2);

  cout << SEPARATOR;

  FCmatrixBanded MB1(5,2);
  MB1.Print();

  cout << SEPARATOR;

  double** entries = new double*[3];
  entries[0] = new double[5];
  entries[1] = new double[6];
  entries[2] = new double[5];

  for(int i=0; i<5; i++)
  {
    entries[0][i]= i*i+2;
    entries[1][i]=30-3*i;
    entries[2][i]= 101%(i+5);
  }
  entries[1][5] = 12;

  FCmatrixBanded MB2(entries,6);
  MB2.Print();

  cout << SEPARATOR;

  double* entries2 = new double[13]; // 13 = 3*5-2 (matriz de dim 5)
  for(int i =0; i<13; i++) {entries2[i]=(5+i)%(2+i)*2+i;}

  FCmatrixBanded MB3(entries2, 5);
  MB3.Print();

  cout << SEPARATOR;

  FCmatrixBanded MB3_copy(MB3);
  MB3_copy.Print();

  cout << SEPARATOR;

  MB3_copy = MB2+MB2;
  MB3_copy.Print();

  cout << SEPARATOR;

  MB3_copy = 10*MB3_copy*10;
  MB3_copy.Print();

  cout << SEPARATOR;

  MB3_copy[0][0]=12;
  MB3_copy[1][0]=120;
  MB3_copy[2][0]=1201.3;

  MB3_copy[0].Print();
  MB3_copy[1].Print();
  MB3_copy[2].Print();

  cout << SEPARATOR;

  vector<Vec> v1;
  Vec vec1(5,2);
  v1.push_back(vec1);
  vec1.SetEntries(6,3);
  v1.push_back(vec1);
  vec1.SetEntries(5,-4.2);
  v1.push_back(vec1);

  FCmatrixBanded MB4(v1);
  MB4.Print();

  cout << SEPARATOR;

  FCmatrixBanded MB5;
  MB5.SetEntries(v1);
  MB5.Print();

  cout << SEPARATOR;

  MB5.SetEntries(7,2);
  MB5.Print();

  cout << "\ndimensoes = " << MB5.Get_nCols() << " x " << MB5.Get_nRows();
  cout << "\ndeterminante = " << MB5.Determinant();
  cout << "\nLinha 3: \n";
  MB5.GetRow(2).Print();
  cout << "Coluna 2: \n";
  MB5.GetCol(1).Print();

  cout << SEPARATOR;

  Vec v5(7,-1);
  v5=MB5*v5;
  v5.Print();

  cout << SEPARATOR;

    cout << "oi linda, sou a tua matriz não transposta:\n";
    MA.Print();

    MA.Transpose();
   cout << "oi linda, sou a tua matriz transposta:\n";
    MA.Print();

    MA.Transpose();
    Vec oi(4, 2);

    //(MA*oi).Print();

    Vec oi2(3, 2);
    (oi2*MA).Print();

  for(int i=0; i< 3; i++ ) {delete[] A[i];}
  delete[] A;
  delete[] B;
  delete[] D;
  delete[] E;
  for(int i=0; i< size_f; i++ ) {delete[] F[i];}
  delete[] F;
  for(int i=0; i< 4; i++ ) {delete[] H[i];}
  delete[] H;
  for(int i =0; i<3; i++) { delete[] entries[i];}
  delete[] entries;
  delete[] entries2;

  return 0;
}
