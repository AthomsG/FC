#include <iostream>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
#include "stlmatrix.hpp"

int trace(vector<vector<int>> m)
{
  int sum=0;
  for(int i=0; i<m.size(); i++)
  {
    sum+=m[i][i];
  }
  return sum;
}

vector<int> Mrow(vector<vector<int>> m,int row)
{
  return m[row];
}

vector<int> vec_matrix(vector<vector<int>> m, vector<int> v)
{
  int rows= m.size();
  int cols= v.size();
  vector<int> result(rows);

  for(int i=0; i<rows; i++)
  {
    result[i]=inner_product(m[i].begin(),m[i].end(),v.begin(),0);
  }
  return result;
}

void print_vec(vector<int> v)
{
  for (int i =0; i<v.size();i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

void print_matrix(vector<vector<int>> m)
{
  cout << endl;
  for (int i =0; i<m.size();i++)
  {
    for (int j = 0; j < m[0].size(); j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

vector<vector<int>> mult(vector<vector<int>> m1,vector<vector<int>> m2)
{
  int m1_rows = m1.size();
  int m1_cols= m1[0].size();
  int m2_rows= m2.size();
  int m2_cols= m2[0].size();

  if(m1_cols != m2_rows)
  {
    cout << "Impossivel multiplicar matrizes, por causa das dimensoes." << endl;
    exit(-1);
  }
  vector<vector<int>> result;
  vector<int> aux(m1_cols);

  for(int i=0; i<m1_rows; i++)
  {
    result.push_back(aux); // aloca logo a memoria necessaria
    for(int j=0; j<m2_cols;j++)
    {
      for(int k=0;k<m1_cols; k++)
      {
        result[i][j]+=m1[i][k]*m2[k][j];
      }
    }
  }
  return result;
}
