#include <iostream>
#include <string>
#include "exercicio27.hpp"
#include "exercicio28.hpp"

using namespace std;


alunoIST::alunoIST(int number, string curso)
{
    this->number = number;
    branch       = curso;
}

void alunoIST::SetNumber(int number)
{
    this->number = number;
}

void alunoIST::SetBranch(string branch)
{
    this->branch = branch;
}

int alunoIST::GetNumber()
{
    return number;
}

void alunoIST::Print()
{
    cout << "número de Aluno: " << number << "." << endl;
    cout << "curso: " << branch << "." << endl;
    
}

//Funcções externas à classe

alunoIST** DoArray_IST(int N)
{
    alunoIST** array = new alunoIST*[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = new alunoIST;
    }
    return array;
}

void Desaloc_IST(alunoIST** array, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete array[i];
    }
    delete array;
}

void Dummy(alunoIST** pAluno, const int N)
{
    for (int i = 0; i < N; i++)
    {
        pAluno[i]->Print();
    }
}
