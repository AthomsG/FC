#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
  cout << "--- PI ---" << endl;
  cout << setprecision(5) << atan(1)*4 << endl;
  cout << setprecision(9) << atan(1)*4 << endl;
  return 0;
}
