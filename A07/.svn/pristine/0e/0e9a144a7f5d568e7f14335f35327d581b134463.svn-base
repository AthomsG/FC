#include <iostream>
#include "exercicio27.hpp"

using namespace std;

pessoa::pessoa(string nome , unsigned int data_nasc)
{
    name  = nome;
    DataN = data_nasc;
}

void pessoa::SetName(string name)
{
    this->name = name;
}

void pessoa::SetBornDate(unsigned int idade)
{
    DataN = idade;
}

string pessoa::GetName(){ return name;}

unsigned int pessoa::GetBornDate()
{
    return DataN;
}

void pessoa::Print()
{
    cout << "nome: " << name << endl;
    cout << "data nascimento: " << DataN << endl;
}

//Funções exterior à classe

pessoa** DoArray(int N)
{
    pessoa** array = new pessoa*[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = new pessoa;
    }
    return array;
}

void Desaloc(pessoa** array, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete array[i];
    }
    delete array;
}

