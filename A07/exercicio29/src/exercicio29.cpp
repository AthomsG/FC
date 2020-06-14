#include <iostream>
#include <string>
#include <math.h>

#include "exercicio27.hpp"
#include "exercicio28.hpp"
#include "exercicio29.hpp"

using namespace std;

Turma::Turma(string name, int n)
{
    this->Nalunos = n;
    this->name    = name;
    
    //memory allocated
    alunoIST **cpy = new alunoIST*[n];
    for (int i = 0; i < n; i++)
    {
        cpy[i] = new alunoIST;
    }
    va = cpy;
}

Turma::Turma(Turma const &copy)
{
    this->Nalunos = copy.Nalunos;
    this->name    = copy.name;
    //memory allocated
    
    alunoIST **cpy = new alunoIST*[this->Nalunos];
    for (int i = 0; i < this->Nalunos; i++)
    {
        cpy[i] = new alunoIST;
        cpy[i] = copy.va[i];
    }
    this->va      = cpy;
}

Turma::~Turma()
{
    delete[] va;
}

Turma Turma::operator = (Turma const &obj)
{
    Turma res(obj);
    return res;
}

int Turma::GetNalunos()
{
    return this->Nalunos;
}

void Turma::AddAluno(alunoIST* const novo)
{
    int n         = this->Nalunos;
    
    //memory allocated
    alunoIST **cpy = new alunoIST*[n + 1];
    for (int i = 0; i < n; i++)
    {
        cpy[i] = new alunoIST;
        cpy[i] = this->va[i];
    }
    cpy[n]     = novo;
    
    //Update member values
    this->va       = cpy;
//    cout << endl << "Nalunos memory adress: " << &this->Nalunos;
//    cout << endl << "va memory adress: " << this->va << endl << endl;
    this->Nalunos  = this->Nalunos + 1;
}

alunoIST* Turma::FindAluno(int num) //REVER MÉTODO
{
    int n      = this->Nalunos/2;
    int save = -1,  search = n;
    
    for (int i = 1; i < n*2; i++)
    {
        if (search == this->Nalunos) //ISTO É PROVISÓRIO!!!!!
        {
            break;
        }
        if (va[search]->GetNumber() == num)
        {
            save = search;
            break;
        }
        if (va[search]->GetNumber() < num)
        {
            if (search/pow(2, i + 1) < 1)
            {
                search += 1;
            }
            else
            {
                search += (int)search/(pow(2, i + 1));
            }
        }
        if (va[search]->GetNumber() > num)
        {
            if (search/pow(2, i + 1) < 1)
            {
                search -= 1;
            }
            else
            {
                search -= (int)search/(pow(2, i + 1));
            }
        }
    }
    
    if (save == -1)
    {
        cout << "Aluno não encontrado" << endl;
        return NULL;
    }
    
    cout << "O número " << num << " corresponde ao aluno: " << va[save]->GetName() << endl;
    return va[save];
}

void Turma::Print()
{
    cout << "\nA TURMA TEM " << this->Nalunos << " ALUNOS.\n";
    cout << "Os seus constituintes são:\n\n";
    
    for(int i = 0; i < this->Nalunos; i++)
    {
        cout << "nome: " << va[i]->GetName() << "\nnúmero aluno: " << va[i]->GetNumber() << endl << endl;
    }
}
