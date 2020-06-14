#include <string>
#include "Func1D.hpp"
#include "TApplication.h"
#include "TCanvas.h"
#include "TAxis.h"

int Func1D::Nplots = 0;

Func1D::Func1D(TF1* ff)
{
    if (ff != NULL)
    {
        F = (TF1*)ff->Clone();
    }
    else
    {
        F = NULL;
    }
}

Func1D::~Func1D()
{
   delete F;
}

void Func1D::SetFunc(TF1* ff)
{
  F=(TF1*)ff->Clone();
}

TF1* Func1D::GetFunc() const
{
  return (TF1*)F->Clone();
}

void Func1D::Draw(string filename, string title,string x_axis, string y_axis, Int_t npx)
{
  if(Nplots == 0)
  {
    TApplication*	MyRootApp;
    MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
    MyRootApp->SetReturnFromRun(true);
  }

  TCanvas* c1 = new TCanvas("c1","new canvas",700,500);
  c1->SetFillColor(10); // white
  c1->SetGrid();

  gPad->Clear();

  F->SetNpx(npx);
  F->SetLineColor(kPink);
  F->SetLineWidth(2);
  F->SetTitle(title.c_str());
  F->GetXaxis()->SetTitle(x_axis.c_str());
  F->GetYaxis()->SetTitle(y_axis.c_str());
  F->Draw(); //DRAW

  c1->Update();
  gPad->WaitPrimitive();
  c1->SaveAs(filename.c_str());

  delete c1;
  Nplots++;
}

double Func1D::Evaluate(double x)
{
  return F->Eval(x);
}

//  valgrind --num-callers=30 --suppressions=$ROOTSYS/etc/valgrind-root.supp 
//  root.exe -l -b -q myscript.C
