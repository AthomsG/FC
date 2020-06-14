#include <iostream>
#include "exercicio27.hpp"
#include "exercicio28.hpp"


int main()
{
    alunoIST** pAluno = DoArray_IST(5);
    
    pAluno[0]->SetName("a");
    pAluno[0]->SetBornDate(123);
    pAluno[0]->SetBranch("MEFT");
    pAluno[0]->SetNumber(123);
    
    pAluno[1]->SetName("b");
    pAluno[1]->SetBornDate(123);
    pAluno[1]->SetBranch("Estudos Orientais");
    pAluno[1]->SetNumber(124);
    
    pAluno[2]->SetName("c");
    pAluno[2]->SetBornDate(123);
    pAluno[2]->SetBranch("MEFT");
    pAluno[2]->SetNumber(125);
    
    pAluno[3]->SetName("d");
    pAluno[3]->SetBornDate(123);
    pAluno[3]->SetBranch("MEFT");
    pAluno[3]->SetNumber(126);
    
    pAluno[4]->SetName("e");
    pAluno[4]->SetBornDate(123);
    pAluno[4]->SetBranch("MEFT");
    pAluno[4]->SetNumber(127);
    
    Dummy(pAluno, 5); //A função Print pertence à classe mãe pessoa. Sendo declarada como virtual é depois redefinida na classe alunoIST.
    
    Desaloc_IST(pAluno, 5);
    
    return 1;
}

