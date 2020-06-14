#include "fintv.hpp"
#include <iostream>

using namespace std;

int*** fintv(int x, int y, int z)
{
  int*** ret = new int**[x];

  for(int i=0; i<x; i++)
  {
    ret[i]= new int*[y];
    for(int j=0; j<y; j++)
    {
      ret[i][j] = new int[z];
      for (int k=0; k<z; k++)
      {
        ret[i][j][k]=1;
      }
    }
  }
  return ret;
}

void print (int*** tensor,int x,int y,int z)
{
  cout << "--- Tensor de Inteiros ---\n\n";
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
