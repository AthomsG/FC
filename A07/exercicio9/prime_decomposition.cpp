#include <iostream>
using namespace std;

int main()
{
  int ipt = 0, aux=0; //input
  bool is_prime = true;

  cout << "--- Decomposicao em numeros primos ---\nInsira um numero: ";
  cin >> ipt;
  aux=ipt;
  cout << aux << " = ";
  for(int i=2; i<=ipt/2;i++)
  {
    if(aux%i==0)
    {
      aux/=i;
      (aux == 1) ? cout << i <<endl : cout << i << " x ";
      i=1; //com o incremento final fica i=2
      is_prime=false;
    }
  }
  if (is_prime){
    cout << "numero primo!"<< endl;
  }
  return 0;
}
