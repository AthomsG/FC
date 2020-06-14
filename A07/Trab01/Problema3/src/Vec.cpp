#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
#include "Vec.hpp"

//default value = 0!!
Vec::Vec(int n,double value)
{
  entries = new double[n];
  for(int i =0; i<n; i++) {entries[i]=value;}
  N=n;
}

Vec::Vec(int n, double* values)
{
  entries= new double[n];
  for(int i=0; i<n; i++) {entries[i]=values[i];}
  N=n;
}

Vec::Vec(const Vec& v)
{
  N=v.N;
  entries = new double[N];
  for(int i=0; i<N; i++) {entries[i]=v.entries[i];}
}

Vec::Vec(const vector<double>& v)
{
  N=v.size();
  entries = new double[N];
  for(int i=0;i<N;i++) {entries[i]=v[i];}
}

void Vec::operator=(const Vec& v)
{
  N=v.N;
  delete[] entries;
  entries = new double[N];
  for(int i=0; i<N; i++) {entries[i]=v.entries[i];}
}

Vec Vec::operator+(const Vec& v) const
{
  if(N!=v.N) {cout << "Err-- Vectors need to have the same dimension (+operator)\n\n"; exit(EXIT_FAILURE);}
  Vec a(v);
  for(int i =0; i<N; i++) {a.entries[i]+=entries[i];}
  return a;
}

void Vec::operator+=(const Vec& v)
{
  (*this)=(*this)+v;
}

Vec Vec::operator-(const Vec& v) const
{
  if(N!=v.N) {cout << "Err-- Vectors need to have the same dimension (-operator)\n\n"; exit(EXIT_FAILURE);}
  Vec a(*this);
  for(int i =0; i<N; i++) {a.entries[i]-=v.entries[i];}
  return a;
}

void Vec::operator-=(const Vec& v)
{
  (*this)=(*this)-v;
}

double Vec::operator[](int entry) const
{
  return this->entries[entry];
}


double& Vec::operator[](int entry)
{
  return this->entries[entry];
}

Vec Vec::operator+()
{
  return (*this);
}

Vec Vec::operator-()
{
  Vec aux(N);
  aux-=(*this);
  return aux;
}

Vec Vec::operator*(const Vec& v) const
{
  Vec aux(*this);
  for(int i =0; i<N; i++) { aux[i]*=v[i];}
  return aux;
}

Vec Vec::operator*(const double a) const
{
  Vec aux(*this);
  for(int i =0; i<N; i++) { aux[i]*=a;}
  return aux;
}

void Vec::SetEntries(const Vec& v)
{
  delete[] entries;
  N=v.N;
  entries = new double[N];
  for(int i=0; i<N; i++) {entries[i]=v[i];}
}

void Vec::SetEntries(int n,double values)
{
  delete[] entries;
  entries = new double[n];
  for(int i=0; i<n; i++) {entries[i]=values;}
  N=n;
}

void Vec::SetEntries(int n,double* values)
{
  delete[] entries;
  entries = new double[n];
  for(int i=0; i<n; i++) {entries[i]=values[i];}
  N=n;
}

void Vec::SetEntries(vector<double> v)
{
  delete[] entries;
  int n = v.size();
  entries = new double[n];
  for(int i=0; i<n; i++) {entries[i]=v[i];}
  N=n;
}

void Vec::push_back(double add)
{
    N++;
    double* v = new double[N-1];

    for(int i = 0; i < N-1; i++)
    {
        v[i] = entries[i];
    }
    delete[] entries;
    entries = new double[N];
    for(int i = 0; i < N-1; i++)
    {
        entries[i] = v[i];
    }
    entries[N-1] = add;

    delete[] v;
}

void Vec::push_front(double add)
{
    N++;
    double* v = new double[N-1];

    for(int i = 0; i < N-1; i++)
    {
        v[i] = entries[i];
    }
    delete[] entries;
    entries = new double[N];
    for(int i = 0; i < N-1; i++)
    {
        entries[i+1] = v[i];
    }
    entries[0] = add;

    delete[] v;
}

int Vec::Size() const
{
    return N;
}

double Vec::Norm() const
{
    double sqr_sum = 0;
    for(int i=0; i<N; i++) {sqr_sum+=(*this)[i]*(*this)[i];}
    return sqrt(sqr_sum);
}

double Vec::Dot(const Vec& v) const
{
  double result=0;
  for(int i=0; i<N; i++)
  {
    result+=(*this)[i]*v[i];
  }
  return result;
}

void Vec::Swap(int i,int j)
{
  if (i>=N || j>=N)
  {
    cout << "Err-- Vec index out of range. Cannot perform Swap\n\n";
    exit (EXIT_FAILURE);
  }
  double aux = (*this)[j];
  (*this)[j]=(*this)[i];
  (*this)[i]=aux;
}

void Vec::Print() const
{
  for(int i =0; i<N; i++)
  {
    cout << entries[i] << " ";
  }
  cout << endl;
}

int Vec::GetMax() const
{
  double max = (*this)[0];
  int index=0;

  for(int i=1; i<N; i++)
  {
    if(max<(*this)[i])
    {
      max=(*this)[i];
      index=i;
    }
  }
  return index;
}

int Vec::GetMin() const
{
  double min = (*this)[0];
  int index = 0;

  for(int i=1; i<N; i++)
  {
    if(min>(*this)[i])
    {
      min=(*this)[i];
      index=i;
    }
  }
  return index;
}

void Vec::pop(int i)
{
    if (i > N-1)
    {
        cout << "Err-- Vec index out of range. Cannot have a pop performance\n\n";
        exit(EXIT_FAILURE);
    }
    double* hold = new double[N-1];
    for(int j = 0; j < N-1; j++)
    {
        if (j != i){hold[j] = entries[j];}
    }
    this->SetEntries(N-1, hold);
    delete[] hold;
}

double* Vec::GetArray() const //NOT TESTED
{
    double* vetor = new double[N];
    for(int i = 0; i < N; i++)
    {
        vetor[i] = entries[i];
    }
    return vetor;
}

 // FRIEND FUNCTIONS

Vec operator*(const double lambda, const Vec& v)
{
   Vec result(v);
   result=v*lambda;
   return result;
}

void Swap(Vec& vec1, Vec& vec2)
{
    Vec aux(vec1);
    vec1.SetEntries(vec2);
    vec2.SetEntries(aux);
}
