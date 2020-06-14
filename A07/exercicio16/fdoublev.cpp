#include "fdoublev.hpp"
#include <iostream>

using namespace std;


double*** fdoublev(int x, int y, int z)
{
  double*** ret = new double**[x];

  for(int i=0; i<x; i++)
  {
    ret[i]= new double*[y];
    for(int j=0; j<y; j++)
    {
      ret[i][j] = new double[z];
      for (int k=0; k<z; k++)
      {
        ret[i][j][k]=5;
      }
    }
  }
  return ret;
}


void print (double*** tensor,int x,int y,int z)
{
  cout << "--- Tensor de Doubles ---\n\n";
  for(int i=0; i<z; i++)
  {
    cout << i+1 << "º plano (na 3ª dimensao)\n";
    for(int j=0; j<x; j++)
    {
      for (int k=0; k<y; k++)
      {
        cout << tensor[j][k][i] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
