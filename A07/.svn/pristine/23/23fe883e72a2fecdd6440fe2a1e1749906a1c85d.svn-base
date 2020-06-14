#include <iostream>
#include <string>
#include "TF1.h"
#include "TCanvas.h"
#include "TApplication.h"
#include "TMath.h"
using namespace std;
#include "Func1D.hpp"

int main()
{
  Func1D hola;
  TF1* f1 = new TF1("f1","TMath::Cos(x)",-2,2);
  hola.SetFunc(f1);

  Func1D myfunc(f1);
  myfunc.Draw("func1d.eps");

  // TF1* f2 = new TF1("f2","TMath::Sin(x)",0,10);
  //
  // myfunc.SetFunc(f2);
  // myfunc.Draw("func1d_2.eps");
  //
  // cout << "\nf(5) = " << myfunc.Evaluate(5) << endl;

  delete f1;
  //delete f2;

  return 0;
}
