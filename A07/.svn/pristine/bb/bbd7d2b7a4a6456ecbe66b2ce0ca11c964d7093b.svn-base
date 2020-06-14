#include <iostream>
using namespace std;

void flip(double* const,int);
void print(double* const, int);

int main()
{
  int N = 0;

  cout << "Insira a dimensao do vector: ";
  cin >> N;

  double* const vec = new double[N]; // pointeiro const para array de doubles!
  // nao queremos const doubles pq vamos altera-los de seguida!
  if(!vec)
  {
    cout << "Erro a alocar memoria.\n";
    return -1;
  }

  for(int i=0; i<N; i++)
  {
    vec[i]=50-i+i*i;
  }
  cout << "Array:\n";
  print(vec,N);
  flip(vec,N);
  cout << "Array invertido:\n";
  print(vec,N);

  return 0;
}

void print(double* const v, int N)
{
  for(int i=0; i<N; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

void flip(double* const v,int N) //const pointer to doubles - we dont want them to be const!
{
  double aux = 0;
  for(int i=0; i< (N/2+N%2); i++)
  {
    aux= v[N-1-i];
    v[N-1-i]=v[i];
    v[i]=aux;
  }
}
