#ifndef exercicio28_hpp
#define exercicio28_hpp

using namespace std;

class alunoIST : public pessoa
{
    public:
    //constructor (numero e curso do aluno)
    alunoIST(int number = 666, string curso = "MEFT");
    
    void SetNumber(int);
    void SetBranch(string);
    int GetNumber();
    void Print();
    ~alunoIST(){;}
    
private:
    int number;
    string branch;
    
};

alunoIST** DoArray_IST(int);
void Desaloc_IST(alunoIST**, int);
void Dummy(alunoIST**, const int);

#endif
