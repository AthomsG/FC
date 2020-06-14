#include <iostream>
#include <utility>
#include <vector>
using namespace std;
#include "polynomial.hpp"

int main()
{
  vector<pair<int,int>> v1;
  v1.push_back(make_pair(1,-2));
  v1.push_back(make_pair(18,1));
  v1.push_back(make_pair(2,2));
  v1.push_back(make_pair(-2,3));
  v1.push_back(make_pair(3,5));
  v1.push_back(make_pair(-7,8));

  Polynomial p1(v1);

  Polynomial p2;
  p2.Print(); //default constructor = 1+2x+3x^2
  p2.Fill();

  Polynomial p3;
  p3=p1*p2;

  p3.Print();

  return 0;
}
