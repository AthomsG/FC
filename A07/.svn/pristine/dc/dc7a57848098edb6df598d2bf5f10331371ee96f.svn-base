#ifndef exercicio27_H
#define exercicio27_H

#include <string>

using namespace std;

class pessoa {
public:
    //constructor (nome do aluno, data de nascimento - AAAAMMDD) pessoa(string, unsigned int); //queremos ter default values. Como ? void SetName(string); //definir o nome...
    pessoa(string nome = "João", unsigned int data_nasc = 666);
    void SetName(string);
    void SetBornDate(unsigned int); //agora a data de nascimento
    string GetName(); //obter o nome
    unsigned int GetBornDate();//agora a data de nascimento.
    virtual void Print(); // print do nome e data de nascimento.
private:
    string name; //nome
    unsigned int DataN; //data de nascimento
};

pessoa** DoArray(int);
void Desaloc(pessoa** , int);

#endif
