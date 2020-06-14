#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "array2vec.hpp"

int main()
{
  int* arr1=new int[6];
  int* arr2=new int[5];

  arr1[0]=1; arr1[1]=10; arr1[2]=5; arr1[3]=6; arr1[4]=9; arr1[5]=3;
  arr2[0]=2; arr2[1]=5; arr2[2]=5; arr2[3]=7; arr2[4]=3;

  vector<int> vec1= array2vec(6,arr1);
  vector<int> vec2= array2vec(5,arr2);

  cout << "arr1 = ";
  print_vec(vec1,6);
  cout << "arr2 = ";
  print_vec(vec2,5);

  vec1= array2vecs(6,arr1,1); //crescente
  vec2= array2vecs(5,arr2,-1); //descrescente

  cout << "arr1 ordenado (crescente) = ";
  print_vec(vec1,6);
  cout << "arr2 ordenado (decrescente)= ";
  print_vec(vec2,5);

  cout << "maximo de arr1 = " << array2vecmax(6,arr1) << endl;
  cout << "maximo de arr2 = " << array2vecmax(5,arr2) << endl;

  // quando nao encontra, retorna a posiçao do end() do vector
  cout << "posicao do numero 7 no arr1: " << array2vecfind(6,arr1,7) +1 <<endl;
  cout << "posicao do numero 7 no arr2: " << array2vecfind(5,arr2,7) +1 << endl;

  delete arr1;
  delete arr2;
  return 0;
}
