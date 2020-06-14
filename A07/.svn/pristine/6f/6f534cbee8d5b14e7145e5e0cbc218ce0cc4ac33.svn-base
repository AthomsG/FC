#include "IntegratorMC.hpp"
#include <cmath>
#include "DataPoints.hpp"

IntegratorMC::IntegratorMC(TF1* f, int M, double x0, double x1) : Integrator(x0,x1,f)
{
  Ndim = 1;
  fF=NULL;
}

IntegratorMC::IntegratorMC(TFormula* f, int M, double* _xmin, double*_xmax)
{
  fF=new TFormula(*f);
  Ndim=M;

  this->xmin= new double[M];
  this->xmax= new double[M];

  for(int i =0; i<M; i++)
  {
    this->xmin[i]=_xmin[i];
    this->xmax[i]=_xmax[i];
  }
}

IntegratorMC::IntegratorMC(const IntegratorMC& cpy)
{
  Ndim=cpy.Ndim;

  if(Ndim==1)
  {
    if (cpy.F!=NULL)
      F=(TF1*)cpy.F->Clone();
    else
      F=NULL;
    fF = NULL;
    xmin = NULL;
    xmax = NULL;
  } else
  {
    fF = new TFormula(*(cpy.fF));
    this->xmin= new double[cpy.Ndim];
    this->xmax= new double[cpy.Ndim];


    if (cpy.xmin!=NULL && cpy.xmax!=NULL)
    {
      for(int i =0; i<cpy.Ndim; i++)
      {
        this->xmin[i]=cpy.xmin[i];
        this->xmax[i]=cpy.xmax[i];
      }
    } else {
      for(int i =0; i<cpy.Ndim; i++)
      {
        this->xmin[i]=0;
        this->xmax[i]=1;
      }
    }
  }
}

void IntegratorMC::UniformRandom(int N, double& result, double& error)
{
  result=0;
  error=0;

  if(Ndim==1)
  {
    double u, avg_sq = 0;

    for(int i =0; i<N; i++)
    {
      u = rgen.Uniform(x0,x1);
      result+=F->Eval(u);
      avg_sq+=pow(F->Eval(u),2);
    }
    result/=N;
    avg_sq/=N;
    error = (x1-x0)*sqrt(avg_sq-result*result)/sqrt((double)N);
    result*=(x1-x0);
  }
  else
  {
    double* entries = new double[Ndim];
    double avg_sq = 0;

    for(int i =0; i<N; i++)
    {
      for(int i =0; i<Ndim; i++)
      {
        entries[i]=rgen.Uniform(xmin[i],xmax[i]);
      }
      result+=fF->EvalPar(entries);
      avg_sq+=pow(fF->EvalPar(entries),2);
    }
    delete[] entries;
    result/=N;
    avg_sq/=N;
    error = sqrt(avg_sq-result*result);

    for(int i =0; i<Ndim; i++)
    {
      error*=(xmax[i]-xmin[i]);
      result*=(xmax[i]-xmin[i]);
    }
    error/=sqrt((double)N);
  }
}

void IntegratorMC::ImportanceSampling(int N, TF1* p, TF1* xofy, double& result, double& error)
{
    result = 0;
    error = 0;
    double u=0;
    double aux = 0;

    if(Ndim==1)
    {
        for (int j = 0; j < N; j++)
        {
            u= rgen.Uniform();
            result += F->Eval(xofy->Eval(u))/p->Eval(xofy->Eval(u));
            aux+= pow( F->Eval(xofy->Eval(u))/p->Eval(xofy->Eval(u)),2);
        }
        error=sqrt(aux/(double)N-pow(result/N,2))/sqrt(N);
        result/=N;
    } else
    {
        cout << "\nEste metodo nao suporta mais do que 1 dimensao.\n";
        exit(EXIT_FAILURE);
    }
}

void IntegratorMC::AcceptanceRejection(int N, double fMax,double& result, double& error)
{
  result = 1, error= 0;
  double u;
  int Nr=0;

  if(Ndim == 1)
  {
    double x;
    for(int i =0; i<N; i++)
    {
      x=rgen.Uniform(x0,x1);
      u = rgen.Uniform(0,1);
      if (u < F->Eval(x)/fMax) {Nr++;}
    }
    result*=(x1-x0)*fMax*Nr/(double)N;
    error = result*sqrt(1/(double)Nr-1/(double)N);
  }
  else
  {
    double* x = new double[Ndim];

    for(int i =0; i<N; i++)
    {
      for(int i =0; i<Ndim; i++)
      {
        x[i]=rgen.Uniform(xmin[i],xmax[i]);
      }
      u = rgen.Uniform(0,1);
      if (u < fF->EvalPar(x)/fMax) {Nr++;}
    }
    delete[] x;
    for(int i =0; i<Ndim; i++)
    {
      result*=(xmax[0]-xmin[0]);
    }
    result*=fMax*Nr/(double)N;
    error = result*sqrt(1/(double)Nr-1/(double)N);
  }
}
