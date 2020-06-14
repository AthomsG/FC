#include <iostream>
#include <cstdlib>
#include <complex>
#include <vector>
#include <math.h>

using namespace std;

vector<complex<double>> rand2vec (int);
complex<double> average (vector<complex<double>>);

// a medida que N aumenta, mais as medias das partes real e
// imaginaria se aproximam do zero. Apesar do zero nunca aparecer
// pois nao pertence a circ de raio 1, é o ponto central da circ
// pelo que e o valor medio dos numeros que sobre ela assentam

int main()
{
  int N =0;
  cout << "Quantos numeros complexos aleatorios deseja gerar? ";
  cin >> N;
  vector<complex<double>> vec = rand2vec(N);
  complex<double> mvec = average(vec);
  cout << "A media dos numros e o complexo z=" << real(mvec);
  imag(mvec)>0 ? cout << "+" : cout << ""; // perfeccionismo mata, deixe ja
  cout << imag(mvec) << "i\n";
  return 0;
}

vector<complex<double>> rand2vec (int N)
{
  cout << "--- Numeros complexos aleatorios---\n";
  vector<complex<double>> v;
  srand(1234);
  double re=0, im=0, theta=0;
  for(int i = 0; i<N; i++)
  {
    theta = 2*M_PI*(double)rand()/RAND_MAX;
    re= cos(theta);
    im = sin(theta);
    complex<double> z(re,im);
    v.push_back(z);
    cout << "z" << i << "=" << re << "+(" << im << ")i" << endl;
  }
  return v;
}

complex<double> average (vector<complex<double>> v)
{
  double re_avg =0, im_avg =0;
  for (auto i = v.begin(); i!=v.end(); i++)
  {
    re_avg+= real(*i);
    im_avg+=imag(*i);
  }
  re_avg/=v.size();
  im_avg/=v.size();

  complex<double> avg(re_avg,im_avg);

  return avg;
}
