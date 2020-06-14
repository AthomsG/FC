#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#include "Vec.hpp"
#include "FCtools.hpp"

vector<string> FCtools::ReadFile2String(string name)
{
  ifstream my_file (name);
  string line;
  vector<string> lines;

  if(my_file.is_open())
  {
    while(getline(my_file,line))
    { //se encontrar volta 0, se nao voltar 0 executa o codigo dentro do if
      if(line.find("//")!=0 & line.size()!=0) { lines.push_back(line); }
    }
  }
  else { cout << "Erro a abrir ficheiro!!\n"; }

  my_file.close();
  return lines;
}

vector<Vec> FCtools::ReadFile2Vec(string name) //usar este!
{
  vector<string> vs = ReadFile2String(name);
  vector<Vec> result;
  double jerry=0;
  vector<double> aux;
  Vec vax;

  for(int i=0; i<vs.size();i++)
  {
    stringstream ss(vs[i]);
    while(ss >> jerry)
    {
      aux.push_back(jerry);
    }
    vax.SetEntries(aux);
    result.push_back(vax);
    aux.clear();
  }
  return result;
}

Vec* FCtools::ReadFile(string name, int* size)
{
  vector<Vec> vequi = ReadFile2Vec(name);
  Vec* result = new Vec[vequi.size()];
  for(int i=0; i<vequi.size();i++)
  {
    result[i].SetEntries(vequi[i]);
  }
  *size = vequi.size();
  return result;
}
