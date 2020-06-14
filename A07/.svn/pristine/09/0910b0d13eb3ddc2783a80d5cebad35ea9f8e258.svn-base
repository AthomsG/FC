#include <iostream>
#include "exercicio27.hpp"

using namespace std;

int main()
{
    //pessoa P[5];
    pessoa** array = DoArray(5);

    array[0]->SetName("Juan");
    array[0]->SetBornDate(20111998);
    array[1]->SetName("Consuela");
    array[1]->SetBornDate(31051994);
    array[2]->SetName("Felicidad");
    array[2]->SetBornDate(11022001);
    array[3]->SetName("Esperanza");
    array[3]->SetBornDate(12101999);
    array[4]->SetName("Carlitos");
    array[4]->SetBornDate(17031998);

    for(int i=0; i<5; i++)
    {
      array[i]->Print();
    }

    Desaloc(array, 5);

    return 0;
}
