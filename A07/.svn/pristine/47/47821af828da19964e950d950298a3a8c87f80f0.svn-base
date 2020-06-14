#include <iostream>
#include <math.h>
using namespace std;

int ret_factorial(int);
void factorial(int*,int*);

int main() //pq vou chamar este ficheiro noutros ficheiros, nao pode haver 2 mains
{
  int num=0;

  cout << "Introduza um numero inteiro positivo: ";
  cin >> num;
  while(num<0){
    cout << "Numeros negativos nao sao permitidos!\n";
    cout << "Introduza um numero inteiro positivo: ";
    cin >> num;
  }
  cout << "Factorial = " << ret_factorial(num) << endl;
  return 0;
}

int ret_factorial(int a)
{
  int result=1;
  factorial(&a, &result);
  return result;
}


void factorial(int* b,int* result)
{
    while(*b>0)
    {
      (*result)*=(*b);
      (*b)--;
      factorial(b,result);
    }
}
