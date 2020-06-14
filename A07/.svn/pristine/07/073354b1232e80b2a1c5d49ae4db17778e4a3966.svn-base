#include <iostream>
#include "sum.hpp"
using namespace std;

int main()
{
  long int* N = new long int;
  if (!N)
  {
    cout << "Erro a alocar memoria.\n";
    return -1;
  }
  cout << "Introduza um numero inteiro positivo: ";
  cin >> *N;
  cout << "A soma dos naturais até " << *N << " é " << sum(*N) << endl;
  return 0;
}
