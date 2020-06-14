#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"
#include "FCmatrixBanded.hpp"

FCmatrixBanded::FCmatrixBanded() : FCmatrix() {;}

FCmatrixBanded::FCmatrixBanded(int fm, double value, string classname)
{
    Vec main_diag(fm,value);
    Vec secn_diags(fm-1,value);

    M.push_back(secn_diags);
    M.push_back(main_diag);
    M.push_back(secn_diags);

    this->classname = classname;
}

FCmatrixBanded::FCmatrixBanded(double** fM, int fm, string classname)
{
  Vec aux(fm-1,fM[0]);
  M.push_back(aux);
  aux.SetEntries(fm,fM[1]);
  M.push_back(aux);
  aux.SetEntries(fm-1,fM[2]);
  M.push_back(aux);

  this->classname = classname;
}

FCmatrixBanded::FCmatrixBanded(double* fM, int fm, string classname)
{ //tamanho de fM = fm + fm-1 + fm-1 = 3*fm - 2

    Vec aux_princ(fm);
    Vec aux_sec(fm-1);

    for(int i =0; i<fm-1; i++) {aux_sec[i]=fM[i];}
    M.push_back(aux_sec);
    for(int i =0; i<fm; i++) {aux_princ[i]=fM[i+fm-1];}
    M.push_back(aux_princ);
    for(int i =0; i<fm-1; i++) {aux_sec[i]=fM[i+2*fm-1];}
    M.push_back(aux_sec);

    this->classname = classname;
}

FCmatrixBanded::FCmatrixBanded(vector<Vec> v,string classname)
{
  Vec aux;

  aux = v[0];
  M.push_back(aux);
  aux = v[1];
  M.push_back(aux);
  aux = v[2];
  M.push_back(aux);

  this->classname = classname;
}

FCmatrixBanded::FCmatrixBanded(Vec _lower, Vec _main, Vec _upper,string classname)
{
  M.push_back(_lower);
  M.push_back(_main);
  M.push_back(_upper);

  this->classname = classname;
}

FCmatrixBanded::FCmatrixBanded(const FCmatrixBanded& mb) // copy constructor
{
  Vec aux(mb.M[0]);
  M.push_back(aux);
  aux = mb.M[1];
  M.push_back(aux);
  aux = mb.M[2];
  M.push_back(aux);

  classname = mb.classname;
}

FCmatrixBanded::FCmatrixBanded(const FCmatrixFull& raiz, string classname)
{
    if (raiz.Get_nRows() != raiz.Get_nCols())
    {
        cout << "Err-- Conversão FCmatrixFull - FCmatrixBanded\nMatriz precisa ser quadrada.\n\n";
        exit(EXIT_FAILURE);

    }
    int diag_size = raiz.Get_nRows();

    Vec main_diag(diag_size);
    Vec upper_diag(diag_size - 1);
    Vec lower_diag(diag_size - 1);

    main_diag[0] = raiz[0][0];
    for (int i = 0; i < diag_size - 1; i++)
    {
        main_diag [i+1] = raiz[i+1][i+1];
        upper_diag[i]   = raiz[i][i+1];
        lower_diag[i]   = raiz[i+1][i];
    }
    M.push_back(lower_diag);
    M.push_back(main_diag);
    M.push_back(upper_diag);

    this->classname = classname;
}

Vec& FCmatrixBanded::operator[](int i)
{
  return M[i];
}

Vec FCmatrixBanded::operator[](int i) const
{
  return M[i];
}

FCmatrixBanded FCmatrixBanded::operator=(const FCmatrix & mb)
{
  M.clear();
  Vec aux(mb.GetM()[0]);
  M.push_back(aux);
  aux.SetEntries(mb.GetM()[1]);
  M.push_back(aux);
  aux.SetEntries(mb.GetM()[2]);
  M.push_back(aux);

  classname = mb.GetName();
}

FCmatrixBanded FCmatrixBanded::operator+(const FCmatrix & mb) const
{
  int size = GetSize();
  if(size!=mb.Get_nCols() || size!=mb.Get_nRows())
  {
    cout << "Error-- matrizes de dimensoes diferentes\n\n";
    exit(EXIT_FAILURE);
  }
  FCmatrixBanded result(*this);
  for(int i =0; i<size-1;i++)
  {
    result.M[0][i]+=mb.GetM()[0][i]; // inferior
    result.M[1][i]+=mb.GetM()[1][i]; // diagonal principal
    result.M[2][i]+=mb.GetM()[2][i]; // superior
  }
  result.M[1][size-1]+=mb.GetM()[1][size-1];

  return result;
}

FCmatrixBanded FCmatrixBanded::operator-(const FCmatrix & mb) const
{
  int size = GetSize();
  if(size!=mb.Get_nCols() || size!=mb.Get_nRows())
  {
    cout << "Error-- matrizes de dimensoes diferentes\n\n";
    exit(EXIT_FAILURE);
  }
  FCmatrixBanded result(*this);
  for(int i =0; i<size-1;i++)
  {
    result.M[0][i]-=mb.GetM()[0][i]; // inferior
    result.M[1][i]-=mb.GetM()[1][i]; // diagonal principal
    result.M[2][i]-=mb.GetM()[2][i]; // superior
  }
  result.M[1][size-1]-=mb.GetM()[1][size-1];

  return result;
}

FCmatrixBanded FCmatrixBanded::operator*(double lambda) const
{
  int size = GetSize();
  FCmatrixBanded result(*this);
  for(int i =0; i<size-1;i++)
  {
    result.M[0][i]*=lambda; // inferior
    result.M[1][i]*=lambda; // diagonal principal
    result.M[2][i]*=lambda; // superior
  }
  result.M[1][size-1]*=lambda;

  return result;
}

Vec FCmatrixBanded::operator*(const Vec & v) const
{
  int size = GetSize();
  if (size!=v.Size())
  {
    cout << "Erro-- matriz e vector nao tem dimensoes compativeis.\n";
    exit(EXIT_FAILURE);
  }
  Vec result(size);
  result[0] = M[1][0]*v[0]+M[2][0]*v[1];
  for(int i = 1; i < size-1; i++)
  {
    result[i]=M[0][i-1]*v[i-1]+M[1][i]*v[i]+M[2][i]*v[i+1];
  }
  result[size-1] =  M[0][size-2]*v[size-2]+M[1][size-1]*v[size-1];

  return result;
}


void FCmatrixBanded::SetEntries(const vector<Vec>& v)
{
  M.clear();
  Vec aux;
  aux=v[0];
  M.push_back(aux);
  aux=v[1];
  M.push_back(aux);
  aux=v[2];
  M.push_back(aux);
}

void FCmatrixBanded::SetEntries(int fm,double value)
{
  M.clear();
  Vec aux(fm-1,value);
  M.push_back(aux);
  aux.SetEntries(fm, value);
  M.push_back(aux);
  aux.SetEntries(fm-1, value);
  M.push_back(aux);
}

double FCmatrixBanded::Determinant() const  //recursive continuant method
{
  int size = GetSize()+1;
  double* f = new double[size];
  double result;

  f[0] = 1;
  f[1] = M[1][0];
  for(int i =2; i<size; i++)
  {
    f[i]=M[1][i-1]*f[i-1]-M[0][i-2]*M[2][i-2]*f[i-2];
  }
  result = f[size-1];

  delete[] f;
  return result;
}

FCmatrixFull FCmatrixBanded::GetFull() const
{
  int n = M[1].Size(); // M[1] = diagonal principal
  FCmatrixFull m(n,n);

  for(int i =0; i<n; i++)
  {
    for(int j = 0 ; j<n; j++)
    {
      if      (i==j+1)  { m[i][j]=M[0][j];} // diagonal inferior
      else if (i==j)    { m[i][j]=M[1][i];} // diagonal principal
      else if (i==j-1)  { m[i][j]=M[2][i];} // diagonal superior
    }
  }
  return m;
}

void FCmatrixBanded::Print() const
{
  GetFull().Print();
}

FCmatrixBanded operator*(const double lambda, const FCmatrixBanded& mb)
{
  FCmatrixBanded result(mb);
  return result*lambda;
}




//QAZAXAPO1111
