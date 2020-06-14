#include <iostream>
#include <string>
//#include <cmath>
#include "TH1F.h"
#include "TCanvas.h"
#include "TApplication.h"
using namespace std;
#include "FCrand.hpp"

int main()
{
  FCrand gen;
  float* x = gen.GetRandom(10E+6,0,10);
  float avg = 0;
  float std_dev = 0;

  for(int i =0; i<10E+6; i++) { avg+=x[i]; }
  avg/=(float)(10E+6);
  cout << "\nValor medio = " << avg;

  for(int i =0; i<10E+6; i++)
  {
    std_dev+=powf(x[i]-avg,2);
  }
  std_dev/=(float)10E+6;
  std_dev=sqrt(std_dev);
  cout << "\nDesvio Padrao = " << std_dev << endl;

  TApplication	*	MyRootApp;
  MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
  MyRootApp->SetReturnFromRun(true);

  TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);

  TH1F* h1 = new TH1F("h1","PseudoRandom Generator",10,0,10);
  for(int i =0; i<10E+6; i++)
  {
    h1->AddBinContent((int)x[i]+1);
  }
  h1->Draw();

  c1->Update();
  c1->Draw();
  c1->SaveAs("Random.eps");
  gPad->WaitPrimitive();

  return 0;
}
