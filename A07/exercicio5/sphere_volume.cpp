#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  float radius = 0;
  float volume = 0;
  cout << "--- Volume de uma esfera ---\n";
  cout << "Insira o raio da esfera: ";
  cin >> radius;
  volume = 4.0/3*M_PI*radius*radius*radius;
  cout << "Volume = " << volume << endl;
  return 0;
}
