#include <iostream>
#include <vector>
using namespace std;
#include "Vec.hpp"
#include "FCtools.hpp"
#define SEPARATOR "\n------------\n\n"

int main()
{
  cout << SEPARATOR;

  FCtools from_file;
  int file_size = 0;


  Vec* matrix1 = from_file.ReadFile("matrix.txt",&file_size);
  for(int i =0; i<file_size; i++) { matrix1[i].Print();}

  cout << SEPARATOR;

  Vec line = matrix1[1]*5;

  Vec* matrix2 = new Vec[5];
  for(int i =0; i<5; i++) { matrix2[i].SetEntries(matrix1[i]); }
  matrix2[1]-=matrix2[0]*(matrix2[1][0]/matrix2[0][0]);
  for(int i =0; i<file_size; i++) { matrix2[i].Print();}

  cout << SEPARATOR;

  Vec mult;
  mult = matrix1[0]*matrix1[1];
  mult.Print();

  cout << SEPARATOR;

  Swap(matrix1[3],matrix1[4]);
  for(int i =0; i<file_size; i++) { matrix1[i].Print();}

  delete[] matrix1;
  delete[] matrix2;
  return 0;
}
