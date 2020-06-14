#include <vector>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#include "atom.hpp"

int main()
{
  char choice;

  cout << "Main da alinea a ou b? ";
  cin >> choice;
  cout << "----------------" << endl;

  switch(choice)
  {
    case 'a':
    {
        ATOM hydrogen;
        hydrogen.A = 1;
        hydrogen.Z = 1;
        hydrogen.name = "Hydrogen";
        vector<ATOM> veccy_boy = vperiodic();

        print(veccy_boy);
        break;
    }
    case 'b':
    {
        ATOM n1, n2, n3, n4;

        n1.name = "Hidrogénio";
        n2.name = "Hélio";
        n3.name = "Lítio";
        n4.name = "Berílio";

        n1.A    = 1.008;
        n2.A    = 4.0026;
        n3.A    = 6.94;
        n4.A    = 9.0122;

        n1.Z    = 1;
        n2.Z    = 2;
        n3.Z    = 3;
        n4.Z    = 4;
        // criar mapa
        map< string, ATOM > mperiodic;
        // preencher mapa com os 1os 4 elementos; duas formas de fazer pair
        mperiodic.insert( pair< string, ATOM> ("Hidrogénio",n1));
        mperiodic.insert( pair< string, ATOM> ("Hélio",n2));
        mperiodic.insert( make_pair("Lítio",n3));
        mperiodic.insert( make_pair("Berílio",n4));
        // imprimir no ecrã todas as entradas do mapa ...
        print(mperiodic.at("Hidrogénio"));
        print(mperiodic.at("Hélio"));
        print(mperiodic.at("Lítio"));
        print(mperiodic.at("Berílio"));
        break;
    }
    default: cout << "Erro." << endl;
  }
  return 0;
}
