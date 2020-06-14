#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"

FCmatrixFull::FCmatrixFull() : FCmatrix() {;}

FCmatrixFull::FCmatrixFull( int fm,int fn,double value,string classname) : FCmatrix(fm,fn,value)
{
  this->classname = classname;
}

FCmatrixFull::FCmatrixFull( double** fM, int fm,int fn,string classname) : FCmatrix(fM,fm,fn)
{
  this->classname = classname;
}

FCmatrixFull::FCmatrixFull(double* fM, int fm, int fn,string classname) : FCmatrix(fM,fm,fn)
{
  this->classname = classname;
}

FCmatrixFull::FCmatrixFull(vector<Vec> v,string classname) : FCmatrix(v)
{
  this->classname = classname;
}
// copy constructor

FCmatrixFull::FCmatrixFull(const FCmatrixFull& fcopy)
{
  classname=fcopy.classname;
  Vec aux;
  for (int i =0; i<fcopy.M.size(); i++)
  {
    aux.SetEntries(fcopy.M[i]);
    M.push_back(aux);
  }
}

FCmatrixFull FCmatrixFull::operator=(const FCmatrix &externo)
{
    M.clear();
    for (int i = 0; i < (externo.GetM()).size(); i++)
    {
        M[i] = externo.GetM()[i];
    }
    classname = externo.GetName();
}

FCmatrixFull FCmatrixFull::operator+(const FCmatrix &externo) const
{
    if (M.size() != (externo.GetM()).size())
    {
        cout << "Err-- Invalid Operation. Matrixes need have the same size! (rows)"<<endl;
        exit(EXIT_FAILURE);
    }
    if (M[0].Size() != (externo.GetM())[0].Size())
    {
        cout << "Err-- Invalid Operation. Matrixes need have the same size! (columns)"<<endl;
        exit(EXIT_FAILURE);
    }
    FCmatrixFull new_matrix;
    Vec aux;

    for (int i = 0; i < M.size(); i++)
    {
        aux= GetM()[i]+(externo.GetM())[i];
        (new_matrix.M).push_back(aux);
    }
    return new_matrix;
}

FCmatrixFull FCmatrixFull::operator-(const FCmatrix &externo) const
{
    if (M.size() != (externo.GetM()).size())
    {
        cout << "Err-- Invalid Operation. Matrixes need have the same size! (rows)"<<endl;
        exit(EXIT_FAILURE);
    }
    if (M[0].Size() != (externo.GetM())[0].Size())
    {
        cout << "Err-- Invalid Operation. Matrixes need have the same size! (columns)"<<endl;
        exit(EXIT_FAILURE);
    }
    FCmatrixFull new_matrix;

    for (int i = 0; i < M.size(); i++)
    {
        (new_matrix.M).push_back(GetM()[i] - externo.GetM()[i]);
    }
    return new_matrix;
}

FCmatrixFull FCmatrixFull::operator*(const FCmatrix &exterior) const
{
    int m1_rows = M.size();
    int m1_cols= M[0].Size();

    int m2_rows= exterior.GetM().size();
    int m2_cols= exterior.GetM()[0].Size();

    if(m1_cols != m2_rows)
    {
        cout << "Err-- Invalid Operation. Matrixes need have the same size! (operator*)" << endl;
        exit(EXIT_FAILURE);
    }
    FCmatrixFull result;
    Vec aux(m2_cols);

    for(int i=0; i<m1_rows; i++)
    {
        result.M.push_back(aux); // aloca logo a memoria necessaria
        for(int j=0; j<m2_cols;j++)
        {
          result.M[i][j]=GetM()[i].Dot(exterior.GetCol(j));
        }
    }
    return result;
}

FCmatrixFull FCmatrixFull::operator*(double lambda) const
{
    FCmatrixFull save(*this);
    for (int i = 0; i < M.size(); i++)
    {
        save.M[i] = GetM()[i]*lambda;
    }
    return save;
}

Vec FCmatrixFull::operator[](int i) const //get a row by giving índex inside []
{
  return M[i];
}

Vec& FCmatrixFull::operator[] (int i) //get a row by giving índex inside []
{
  return M[i];
}

void FCmatrixFull::SetEntries(int fm, int fn, double value)
{
  FCmatrixFull cpy(fm,fm,value);
  (*this)=cpy;
}

void FCmatrixFull::SetEntries(double** fM, int fm, int fn)
{
  FCmatrixFull cpy(fM,fm,fn);
  (*this)=cpy;
}

void FCmatrixFull::SetEntries(double* fM, int fm, int fn)
{
  FCmatrixFull cpy(fM,fm,fn);
  (*this)=cpy;
}

void FCmatrixFull::SetEntries(const vector<Vec>& V)
{
  FCmatrixFull cpy(V);
  (*this)=cpy;
}

double FCmatrixFull::Determinant() const //metodo dos cofactores - funcao recursiva
{
  if(Get_nRows()!=Get_nCols())
  {
    cout << "Erro-- Determinant() requires square matrix.\n";
    exit(EXIT_FAILURE);
  }
  int n=Get_nCols(); //dimensao da matriz

  // se a matriz tem dimensoes 1x1
  if(n==1)  { return (*this)[0][0]; }

  double* cofs = new double[n]; //vector dos cofactores da primeira coluna
  FCmatrixFull auxm; //matrizes de dimensao (n-1), omitindo a linha (e coluna) do cofactor respectivo
  vector<Vec> values; // usado para inicializar as matrizes acima
  Vec aux; //vec auxiliar usado para encher o vector acima
  vector<double> aux_vec; // usado para inicializar o Vec acima
  double determinant = 0;

  for(int k=0; k<n; k++) // em cada ciclo destes calcula-se o cofactor da coluna 0, linka k
  {
    for(int i=0; i<n; i++) // cria a matriz cujo det e necessario calcular pa determinar o cofactor deste ciclo (em k)
    {
      if(i!=k) // omite-se a linha do cofactor que se pretende calcular
      {
        for(int j=1; j<n; j++)
        {
          aux_vec.push_back((*this)[i][j]);
        }
        aux.SetEntries(aux_vec);
        values.push_back(aux);
        aux_vec.clear();
      }
    }
    auxm.SetEntries(values);
    cofs[k]=auxm.Determinant(); //recursivo!
    determinant+=pow(-1,k)*cofs[k]*(*this)[k][0]; //calculo do determinante: pode nao ser o final, mas o de uma matriz intermedia
    values.clear();
  }
  delete[] cofs;
  return determinant;
}

int FCmatrixFull::Get_nRows() const //number of rows of M
{
  return M.size();
}

int FCmatrixFull::Get_nCols() const //number of columns of M7
{
  return M[0].Size();
}

Vec FCmatrixFull::GetRow(int i) const
{
    if (i >= M.size())
    {
        cout << "ERR-- FCmatrixFull-- GetRow. Index i is bigger than Matrix row size." << endl;
        exit(EXIT_FAILURE);
    }
    return M[i];
}

Vec FCmatrixFull::GetCol(int i) const
{
    if (i >= M[0].Size())
    {
        cout << "Err-- FCmatrixFull-- GetCol. Index i is bigger than Matrix column size." << endl;
        exit(EXIT_FAILURE);
    }

    double* entries = new double[M.size()];
    for(int j = 0; j < M.size(); j++)
    {
        entries[j] = M[j][i];
    }

    Vec save(M.size(), entries);
    delete[] entries;

    return save;
}

int FCmatrixFull::GetRowMax(int i) const
{
  Vec row = GetRow(i);
  int index = row.GetMax();
  return index;
}

int FCmatrixFull::GetColMax(int j) const
{
  int n_lines = M.size();
  int size=n_lines-j;
  Vec compares(size);
  Vec aux;

  for(int i=j; i<n_lines;i++)
  {
    compares[i-j]=abs(M[i][j])/M[i].Norm();
  }
  return compares.GetMax()+j;
}

void FCmatrixFull::swapRows(int i, int j)
{
    if (i < 0 or j < 0 or i > M.size() or j > M.size())
    {
        cout << "Err-- swapRows index out of range\n";
        exit(EXIT_FAILURE);
    }

    Vec save(M[i]);
    M[i] = M[j];
    M[j] = save;
}



FCmatrixFull operator*(const double lambda, const FCmatrixFull& m)
{
  return m*lambda;
}

//NEWLY ADDED
void FCmatrixFull::Transpose()
{
    int size = M[0].Size();
    double** matriz = new double*[size];

    for(int i = 0; i <size; i++)
    {
        matriz[i] = new double[M.size()];
        for(int j = 0; j < M.size(); j++)
        {
            matriz[i][j] = M[j][i];
        }
    }
    this->SetEntries(matriz, size, M.size());

    for(int i = 0; i < size; i++)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
}

Vec FCmatrixFull::operator*(const Vec &v) const
{
    if (v.Size() != this->Get_nCols())
    {
        cout << "Err-- operator*. FCmatrixFull and Vec aren't of the same size.\n";
        exit(EXIT_FAILURE);
    }

    Vec res(this->Get_nRows());
    for (int i = 0; i < this->Get_nRows(); i++)
    {
        for (int j = 0; j < this->Get_nCols(); j++)
        {
            res[i] += v[j]*M[i][j];
        }
    }
    return res;
}

Vec operator*(const Vec &v, const FCmatrixFull& m)
{
    if (v.Size() != m.Get_nRows())
    {
        cout << "Err-- operator*. FCmatrixFull and Vec aren't of the same size.\n";
        exit(EXIT_FAILURE);
    }

    Vec res(m.Get_nCols());
    for (int i = 0; i < m.Get_nCols(); i++)
    {
        for (int j = 0; j < v.Size(); j++)
        {
            res[i] += v[j]*m[j][i];
        }
    }
    return res;
}
