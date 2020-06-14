#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#include "polynomial.hpp"

Polynomial::Polynomial() // default constructor: 1+2x+3x^2
{
  for(int i=0;i<3;i++)
  {
    p.push_back(make_pair(i+1,i));
  }
}

Polynomial::Polynomial(vector<pair<int,int>> v)
{
  for(auto i = v.begin(); i!=v.end(); i++)
  {
    p.push_back(make_pair(i->first,i->second));
  }
}

Polynomial::Polynomial(const Polynomial& copy)
{
  for(auto i=copy.p.begin(); i!= copy.p.end();++i)
  {
    p.push_back(make_pair(i->first,i->second));
  }
}

void Polynomial::Group() // agrupar os termos com expoente igual
{
  for(auto i=this->p.begin();i!=this->p.end();i++)
  {
    for(auto j=i+1;j!=this->p.end();j++)
    {
      if(i->second == j->second)
      {
        i->first+=j->first;
        this->p.erase(j);
        // se apagar o end(), tem de verificar o novo end() outra vez
        if(j== this->p.end()) {j--;}
      }
    }
  }
}

void Polynomial::Zero_coeff() // apagar os termos com coeficiente nulo
{
  for(auto i=this->p.begin();i!=this->p.end();i++)
  {
    if(i->first==0)
    {
      this->p.erase(i);
      // se apagar o begin(), tem de verificar o novo begin() outra vez
      if (i==this->p.begin() || i==this->p.end()) {i--;}
    }
  }
}

Polynomial Polynomial::operator=( const Polynomial& copy)
{
  p.clear();
  for(auto i=copy.p.begin(); i!= copy.p.end();++i)
  {
    p.push_back(make_pair(i->first,i->second));
  }
}

Polynomial Polynomial::operator+( const Polynomial& other)
{
  Polynomial result;

  for(auto i=this->p.begin();i!=this->p.end();i++)
  {
    result.p.push_back(make_pair(i->first,i->second));
  }
  for(auto i=other.p.begin();i!=other.p.end();i++)
  {
    result.p.push_back(make_pair(i->first,i->second));
  }
  result.Group();
  result.Zero_coeff();
  result.Sort();
  return result;
}

Polynomial Polynomial::operator-( const Polynomial& other)
{
  Polynomial result(other.p);
  for(auto i= result.p.begin();i!=result.p.end();i++)
  {
    i->first*=-1;
  }
  result= (*this)+result;
  return result;
}

Polynomial Polynomial::operator*( const Polynomial& other)
{
  Polynomial result;

  for(auto i=this->p.begin();i!=this->p.end();i++)
  {
    for(auto j= other.p.begin();j!=other.p.end();j++)
    {
      result.p.push_back(make_pair((i->first)*(j->first),(i->second)+(j->second)));
    }
  }
  result.Group();
  result.Zero_coeff();
  result.Sort();
  return result;
}

void Polynomial::Print()
{
  vector<pair<int,int>>::iterator i;
  if (p.size()==0)
  {
    cout << "0"<< endl;
    return;
  }
  for(i=p.begin(); i!=p.end()-1;i++)
  {
    cout << i->first << "x^" << i->second << " + ";
  }
  cout << i->first << "x^" << i->second << endl;
}

void Polynomial::Sort() //ordena em ordem crescente ao expoente
{
  sort(this->p.begin(),this->p.end(),
  [](const pair<int,int>& x, const pair<int,int>& y){return x.second<y.second;});
}

void Polynomial::Fill() // o utilizador insere o polinomio
{
  this->p.clear();
  int N = 0, exp=0, coef=0;

  cout << "Quantos termos quer inserir? ";
  cin >> N;
  if(N==0)
  {
    this->p.push_back(make_pair(0,0));
  }
  for(int i=0; i<N; ++i)
  {
    cout << i+1 << "º termo ---\n";
    cout << "Expoente = ";
    cin >> exp;
    cout << "Coeficiente = ";
    cin >> coef;
    this->p.push_back(make_pair(coef,exp));
  }
}
