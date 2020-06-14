#include <iostream>
#include "fintv.hpp"
#include "fdoublev.hpp"

using namespace std;

int main()
{
  int*** a = fintv(100,50);
  double*** b = fdoublev(100,50,2);
  print(a,100,50);
  print(b,100,50,2);

  for(int i=0;i<100;i++)
  {
    for(int j=0; j<50; j++)
    {
      delete a[i][j];
      delete b[i][j];
    }
    delete a[i];
    delete b[i];
  }
  delete a;
  delete b;

  return 0;
}
