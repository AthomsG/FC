#include <iostream>
#include <math.h>
using namespace std;


int main()
{
  // vamos converter os ponteiros para inteiros para podermos
  // subtrair o valor de um endereço ao valor do endereço anterior
  intptr_t that=1;

  char* a;
  that = reinterpret_cast<intptr_t>(a+1)-reinterpret_cast<intptr_t>(a);
  cout << "\nchar = " << that << " bytes" << endl;

  short int* b;
  that = reinterpret_cast<intptr_t>(b+1)-reinterpret_cast<intptr_t>(b);
  cout << "short int = " << that << " bytes" << endl;

  int* c;
  that = reinterpret_cast<intptr_t>(c+1)-reinterpret_cast<intptr_t>(c);
  cout << "int = " << that << " bytes" << endl;

  long int* d;
  that = reinterpret_cast<intptr_t>(d+1)-reinterpret_cast<intptr_t>(d);
  cout << "long int = " << that << " bytes" << endl;

  unsigned int* e;
  that = reinterpret_cast<intptr_t>(e+1)-reinterpret_cast<intptr_t>(e);
  cout << "unsigned int = " << that << " bytes" << endl;

  float * f;
  that = reinterpret_cast<intptr_t>(f+1)-reinterpret_cast<intptr_t>(f);
  cout << "float = " << that << " bytes" << endl;

  double * g;
  that = reinterpret_cast<intptr_t>(g+1)-reinterpret_cast<intptr_t>(g);
  cout << "double = " << that << " bytes" << endl;

  long double * h;
  that = reinterpret_cast<intptr_t>(h+1)-reinterpret_cast<intptr_t>(h);
  cout << "long double = " << that << " bytes" << endl;

  // UPDATE: existe o sizeof() lol

  cout << "\n--- Utilizando a funçao sizeof() ---\n";
  cout << "\nchar = " << sizeof(char) << " bytes" << endl;
  cout << "short int = " << sizeof(short int) << " bytes" << endl;
  cout << "int = " << sizeof(int) << " bytes" << endl;
  cout << "long int = " << sizeof(long int) << " bytes" << endl;
  cout << "unsigned int = " << sizeof(unsigned int) << " bytes" << endl;
  cout << "float = " << sizeof(float) << " bytes" << endl;
  cout << "double = " << sizeof(double) << " bytes" << endl;
  cout << "long double = " << sizeof(long double) << " bytes" << endl;

  return 0;
}
