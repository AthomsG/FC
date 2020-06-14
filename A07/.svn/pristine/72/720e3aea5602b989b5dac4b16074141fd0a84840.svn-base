#include <iostream>
#include <vector>
using namespace std;
#include "Vec.hpp"
#include "FCmatrix.hpp"
#include "FCmatrixFull.hpp"
#include "FCmatrixBanded.hpp"
#include "EqSolver.hpp"

int main()
{
  //Nao e possivel resolver sem recorrer a pivotagem, porque logo apos
  // o primeiro passo da eliminacao de gauss (linha 2 + 0.5*linha 1)
  // a segunda linha fica com um zero na segunda posiçao; como tal
  // se se continuasse o metodo sem a correcta troca de linhas, o coeficiente
  // calculado para eliminar o pivo da 3 linha seria inf (dividir por zero)
  FCmatrixFull A(4,4);
  A[0][0]=4; A[0][1]=-2; A[0][2]=2; A[0][3]=2;
  A[1][0]=-2; A[1][1]=1; A[1][2]=3; A[1][3]=1;
  A[2][0]=2; A[2][1]=-2; A[2][2]=2; A[2][3]=1;
  A[3][0]=2; A[3][1]=-1; A[3][2]=2; A[3][3]=1;

  cout << "Matriz:\n";
  A.Print();

  Vec b(4);
  b[0]= -2; b[1]=1; b[2]=0; b[3]=2;

  cout << "Vector:\n";
  b.Print();

  EqSolver S(A,b);
  cout << "Soluçao pelo metodo de Eliminacao de Gauss:\n";
  S.GaussEliminationSolver().Print();

  return 0;
}
