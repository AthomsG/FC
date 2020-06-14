#include <iostream>
using namespace std;
#include "complex.hpp"

Complex::Complex()
{
  realPart=0;
  imaginaryPart=0;
}

void Complex::setComplex(double re, double im)
{
  realPart=re;
  imaginaryPart=im;
}

void Complex::printComplex()
{
  cout << realPart << " + " << imaginaryPart << "i\n";
}

Complex Complex::operator+(const Complex& other)
{
  Complex result;
  result.realPart=this->realPart+other.realPart;
  result.imaginaryPart=imaginaryPart+other.imaginaryPart;
  return result;
}

Complex Complex::operator-(const Complex& other)
{
  Complex result;
  result.realPart=this->realPart-other.realPart;
  result.imaginaryPart=imaginaryPart-other.imaginaryPart;
  return result;
}

Complex Complex::operator*(const Complex& other)
{
  Complex result;
  // this = a+bi; other = c+di
  double a=realPart, b=imaginaryPart;
  double c=other.realPart, d=other.imaginaryPart;

  result.realPart=a*c-b*d;
  result.imaginaryPart=a*d+b*c;
  
  return result;
}

Complex Complex::operator/(const Complex& other)
{
  Complex result;
  // this = a+bi; other = c+di
  double a=realPart, b=imaginaryPart;
  double c=other.realPart, d=other.imaginaryPart;
  double denom = c*c+d*d;

  result.realPart= (a*c+b*d)/denom;
  result.imaginaryPart = (b*c-a*d)/denom;

  return result;
}
