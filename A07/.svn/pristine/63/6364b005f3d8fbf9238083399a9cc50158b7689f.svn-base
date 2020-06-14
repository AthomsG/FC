#include <iostream>
#include "exercicio27.hpp"
#include "exercicio28.hpp"
#include "exercicio29.hpp"

using namespace std;

int main()
{
    Turma ano_2("ano 2", 1);
    
    alunoIST thomas(86809, "MEFT");
    alunoIST diogo(90057,  "MEFT");
    alunoIST rocha(77777, "não MEFT");

    thomas.SetName("Thomas Gaehtgens");
    thomas.SetBornDate(30121998);

    diogo.SetName("Diogo Miguez");
    diogo.SetBornDate(20111998);
    
    rocha.SetName("João Rocha");
    rocha.SetBornDate(696969);
    
    ano_2.AddAluno(&rocha);
    ano_2.AddAluno(&thomas);
    ano_2.AddAluno(&diogo);
    
    Turma copy = ano_2;
    copy.Print();

    copy.FindAluno(90057);
    copy.FindAluno(86809);
    copy.FindAluno(77777);
    copy.FindAluno(666);
    copy.FindAluno(9999999);
    
    return 1;
}
