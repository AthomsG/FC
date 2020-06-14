#include <iostream>
#include <vector>
using namespace std;
#include "stlmatrix.hpp"

int main()
{
  vector<vector<int>> M1;

  vector<int>aux {1,2,7};
  M1.push_back(aux);
  aux[0]=-2; aux[1]=6; aux[2]=-3;
  M1.push_back(aux);
  aux[0]=3; aux[1]=9; aux[2]=3;
  M1.push_back(aux);

  cout << "O traço da matriz M1 e igual a " << trace(M1) << endl;

  for(int i =0; i<3; i++)
  {
    cout << "A linha " << i+1 << " da matriz M1 tem os elementos ";
    cout << Mrow(M1,i)[0] << " " << Mrow(M1,i)[1] << " " << Mrow(M1,i)[2] << endl;
  }

  aux[0]=2; aux[1]=3; aux[2]=-2;
  cout << "The result of (M1 x v) is the vector ";
  print_vec(vec_matrix(M1,aux));

  vector<vector<int>> M2;

  aux[0]=2; aux[1]=3; aux[2]=1;
  M2.push_back(aux);
  aux[0]=3; aux[1]=0; aux[2]=-2;
  M2.push_back(aux);

  cout << "The result of (M2 x M1) is the matrix ";
  print_matrix(mult(M2,M1));

  return 0;
}
