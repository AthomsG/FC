#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
  double realPart;
  double imaginaryPart;
public:
  Complex();
  Complex operator+(const Complex&);
  Complex operator-(const Complex&);
  Complex operator*(const Complex&);
  Complex operator/(const Complex&);
  void setComplex(double,double);
  void printComplex(); // na forma a+bi
};

#endif
