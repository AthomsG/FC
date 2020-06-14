#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
  vector<pair<int,int>> p;
public:
  Polynomial(); // default constructor: 1+2x+3x^2
  Polynomial(vector<pair<int,int>>); // constructor que aceita vector
  Polynomial(const Polynomial&); //copy constructor
  void Fill(); // o utilizador insere o polinomio
  Polynomial operator=( const Polynomial&); //copy assignment
  Polynomial operator+( const Polynomial&);
  Polynomial operator-( const Polynomial&);
  Polynomial operator*( const Polynomial&);
  void Print();
  void Sort(); // ordena por ordem crescente
  void Group(); // agrupa termos com mesmo expoente
  void Zero_coeff(); // apaga os termos com coef zero
};

#endif
