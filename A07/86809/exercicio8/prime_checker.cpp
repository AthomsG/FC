#include <iostream>
using namespace std;

int main()
{
  int ipt = 0; //input
  bool is_prime= true;

  cout << "Insira um numero: ";
  cin >> ipt;

  for(int i=2; i<=ipt/2;i++){
    if(ipt%i==0){
      is_prime=false;
      break;
    }
  }
  (is_prime ==true) ? cout << "E primo!\n" : cout << "Nao e primo!\n";
  return 0;
}
