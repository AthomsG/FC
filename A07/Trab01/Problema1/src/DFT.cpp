#include <iostream>
#include <vector>
#include <cmath>
#include "TF1.h"
#include "TMath.h"
#include <math.h>
#include "Signal.h"
#include "DFT.h"

using namespace std;

DFT::DFT()
{;}

DFT::DFT(Signal& sinal)
{
    sig1d = sinal;
}

vector<double> DFT::MultCOS(Signal& sinal, double& num)
{
    vector<double> res;

    vector<double> t = sinal.GetTime();
    vector<double> s = sinal.GetValue();

    for(int i = 0; i < sinal.Size(); i++)
    {
        res.push_back(s[i]*cos(2*M_PI*num*t[i]));
    }
    return res;
}

vector<double> DFT::MultSIN(Signal& sinal, double& num)
{
    vector<double> res;

    vector<double> t = sinal.GetTime();
    vector<double> s = sinal.GetValue();

    for(int i = 0; i < sinal.Size(); i++)
    {
        res.push_back(s[i]*sin(2*M_PI*num*t[i]));
    }
    return res;
}

double DFT::Sum(vector<double> somar)
{
    double res = 0;
    for(int i = 0; i < somar.size(); i++)
    {
        res+=somar[i];
    }
    return res;
}

double DFT::GetPowSpec(double f)
{
    int N = sig1d.Size();
    vector<double> s = sig1d.GetValue();
    vector<double> t = sig1d.GetTime();
    double res = 0;

    res += pow((1.0/N)*this->Sum(this->MultCOS(sig1d,f)),2);
    res += pow((1.0/N)*this->Sum(this->MultSIN(sig1d,f)),2);

    return res;
}

double DFT::GetAmpSpec(double f)
{
    return TMath::Sqrt(GetPowSpec(f));
}
