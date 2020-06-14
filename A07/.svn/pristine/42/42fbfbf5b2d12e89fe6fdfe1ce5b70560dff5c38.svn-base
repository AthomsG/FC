#include <iostream>

using namespace std;

//Por Ponteiro---------------------------------

void fact(int*, int);

int main()
{
   int var;

   cout << "introduza um número: \n";
   cin  >> var;

   fact(&var, var);
   cout << "factorial = " << var << "\n";

   return 1;
}

void fact(int* w, int n)
{
   if (n > 1)
   {
       *w *= (n - 1);
       fact(w, n - 1);
   }
}

//Por Referência---------------------------------

// void fact(int&, int);
//
// int main()
// {
//     int var;
//     int *pntr = &var;
//
//     cout << "introduza um número: \n";
//     cin  >> var;
//
//     fact(*pntr, var);
//     cout << "factorial = " << var << "\n";
//
//     return 1;
// }
//
// void fact(int& w, int n)
// {
//     if (n > 1)
//     {
//         w *= (n - 1);
//         fact(w, n - 1);
//     }
// }
