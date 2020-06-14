#ifndef exercicio29_hpp
#define exercicio29_hpp

class Turma {
public:
    // tenho de fazer default constructor - Turma()?????
    Turma(string name = "NULL", int n = 1); //nome da turma, num de alunos
    Turma(Turma const &);
    ~Turma(); //destructor
    Turma operator = (Turma const &obj);
    void AddAluno(alunoIST* const);
    int GetNalunos();
    alunoIST* FindAluno(int);
    void Print();
private:
    alunoIST **va; //pointer to array de pointers de objectos
    int Nalunos;
    string name;
};
#endif /* exercicio29_hpp */
