#include <iostream>
#include <vector>
#include <string>
using namespace std;
#include "Vec.hpp"
#include "FCmatrix.hpp"


FCmatrix::FCmatrix()
{
    classname = "EMPTY";
}

FCmatrix::FCmatrix(int fm, int fn,double value, string classname) //matrix fm x fn given from pointer of pointers
{
    Vec line(fn,value);
    for (int i = 0; i < fm; i++)
    {
        M.push_back(line);
    }
    this->classname = classname;
}

FCmatrix::FCmatrix(double** fM, int fm, int fn,string classname) //matrix fm x fn given from pointer of pointers
{
    Vec line;
    for (int i = 0; i < fm; i++)
    {
        line.SetEntries(fn, fM[i]);
        M.push_back(line);
    }
    this->classname = classname;
}

FCmatrix::FCmatrix(double* fM, int fm, int fn,string classname) //matrix fm x fn given as single pointer (what length ?!)
{
    Vec line(fn);
    double* aux = new double[fn]; // tamanho de cada linha

    for (int i = 0; i < fm; i++)
    {
      for(int j=0; j < fn ; j++)
      {
        aux[j]=fM[i*fn+j];
      }
      line.SetEntries(fn, aux);
      M.push_back(line);
    }
    delete[] aux;

    this->classname = classname;
}


FCmatrix::FCmatrix( const vector<Vec>& matrix,string classname)
{
    for(int i = 0; i < matrix.size(); i++)
    {
        M.push_back(matrix[i]);
    }
    this->classname = classname;
}

void FCmatrix::Print() const //imprime as matries alinhadas por colunas (sinal menos fica atras do inicio da coluna)
{
  int size = M[0].Size();
  string str = to_string(M[0][0]);
  int max = str.size();

  for(int i =0; i<M.size(); i++)
  {
    for(int j=0; j<size; j++)
    {
      str= to_string(M[i][j]);
      if(str.size()>max)
      {
        max=str.size();
      }
    }
  }

  for(int i =0; i<M.size(); i++)
  {
    for(int j=0; j<size; j++)
    {
      str= to_string(M[i][j]);
      str = str.substr(0,str.size()-4);
      if(str[0]!='-') { cout << " ";}
      cout << str;
      for(int k=0; k<max-str.size()-3;k++)
      {
        cout << " ";
      }
      if(str[0]=='-') {cout << " ";}
    }
    cout << endl;
  }
}
