#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int factorial(int);
float eTaylor(float,int);

int main(){
  float exp = 1; //ponto sobre o qual se faz a expansao (neste caso 1)
  int dec = 0; // numero de casas decimais sem erro
  cout << "Insira a precisao em casas decimais: ";
  cin >> dec;
  cout << "e = " << setprecision(dec+1) << eTaylor(exp,dec) << endl;
  return 0;
}

float eTaylor(float a, int b)
{
  float aux = 1;
  float result = 0;

  for(int i=0;aux>=powf(10,-b-1);i++)
  {
    result+=powf(a,i)/factorial(i);
    aux=abs(M_E-result); //compara o resultado com o valor referencia
  }
  return result;
}


int factorial(int a)
{
  int result=0;
  for(result=1;a>0;a--)
  {
    result*=a;
  }
  return result;
}
