#include <iostream>
#include <math.h>
using namespace std;

int main()
{
  float num = 0;
  int precision=0;
  do{
    precision++;
    num=1+pow(10,-precision);
  }while (num!=1);
  precision--; // a ultima vez que incrementou o resultado deu um, o valor anterior era a precisao verdadeira
  cout << "Precisao float = "<< powf(10,-precision) << endl;

  double num1=0;
  precision=0;
  do{
    precision++;
    num1=1+pow(10,-precision);
  }while (num1!=1);
  precision--; // a ultima vez que incrementou o resultado deu um, o valor anterior era a precisao verdadeira
  cout << "Precisao double = "<< powf(10,-precision) << endl;
  return 0;
}
