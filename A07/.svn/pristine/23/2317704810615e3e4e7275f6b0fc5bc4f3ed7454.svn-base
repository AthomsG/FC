#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void randgen(double*, int*);

int main()
{
  double* num = new double;
  int* n = new int;
  *n=0; // numero de amostras realizadas
  for(int i=0; i<100; i++)
  {
    randgen(num,n);
    cout << *num << endl;
  }
  return 0;
}

void randgen(double* num, int* n)
{
  srand((*n)*10);
  *num = 50*(1+(double)rand()/RAND_MAX);
  (*n)++;
}
