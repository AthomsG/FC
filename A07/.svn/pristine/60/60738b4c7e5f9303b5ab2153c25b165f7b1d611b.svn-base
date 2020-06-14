#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <sstream>
#include "TCanvas.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TApplication.h"
#include "Signal.h"
#include <stdlib.h>
#include "FCtools.hpp"
#include "DataPoints.hpp"
using namespace std;

Signal::Signal()
{;}

Signal::Signal(double* t, double* sig, int n) //time and signal ptr arrays with size n
{
    for (int i = 0; i < n; i++)
    {
        time.push_back(t[i]);
        signal.push_back(sig[i]);
    }
}

Signal::Signal(vector<double> t, vector<double> sig)
{
    for (int i = 0; i < t.size(); i++)
    {
        time.push_back(t[i]);
        signal.push_back(sig[i]);
    }
}

Signal::Signal(string filename) //read a file "filename" and assign signal and time from it.
{
  FCtools f;
  vector<Vec> v = f.ReadFile2Vec(filename);

  for(int i=0; i<v.size(); i++)
  {
    time.push_back(v[i][0]);
    signal.push_back(v[i][1]);
  }
}

// copy constructor
Signal::Signal(const Signal& sinal)
{
    time.clear();
    signal.clear();
    for (int i = 0; i < sinal.time.size(); i++)
    {
        time.push_back(sinal.time[i]);
        signal.push_back(sinal.signal[i]);
    }
}

// operators
Signal& Signal::operator=(const Signal &sinal) // assign signal
{
    time.clear();
    signal.clear();
    for (int i = 0; i < sinal.time.size(); i++)
    {
        time.push_back(sinal.time[i]);
        signal.push_back(sinal.signal[i]);
    }
    return *this;
}

Signal Signal::operator+(const Signal & sinal)// add 2 signals of same "size"
{
    if(sinal.Size() != signal.size())
    {
        cout << "Err-- Signals têm de ter a mesma dimensão!\n\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < signal.size(); i++)
    {
        signal[i] += sinal.signal[i];
    }
    return *this;
}

Signal Signal::operator-(const Signal & sinal) // subtract 2 signals of same "size"
{
    if(sinal.Size() != signal.size())
    {
        cout << "Err-- Signals têm de ter a mesma dimensão!\n\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < signal.size(); i++)
    {
        signal[i] -= sinal.signal[i];
    }
    return *this;
}

Signal Signal::operator*(const Signal & sinal) // multiply 2 signals of same "size"
{
    if(sinal.Size() != signal.size())
    {
        cout << "Err-- Signals têm de ter a mesma dimensão!\n\n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < signal.size(); i++)
    {
        signal[i] *= sinal.signal[i];
    }
    return *this;
}

Signal Signal::operator*(double mult) // multiply each signal value by a double
{
    for (int i = 0; i < signal.size(); i++)
    {
        signal[i] *= mult;
    }
    return *this;
}

pair<double,double> Signal::operator[] (int i)
{
    if(i > signal.size() - 1)
    {
        cout << "Err-- Indíce inexistente\n";
        exit(EXIT_FAILURE);
    }
    return make_pair(time[i], signal[i]);
}

vector<double> Signal::GetTime() const
{
    vector<double> res;
    for (int i = 0; i < time.size(); i++)
    {
        res.push_back(time[i]);
    }
    return res;
}

vector<double> Signal::GetValue() const
{
    vector<double> res;
    for (int i = 0; i < signal.size(); i++)
    {
        res.push_back(signal[i]);
    }
    return res;
}

int Signal::Size() const
{
    return signal.size();
}

void Signal::Plot(string title) const //plot of signal over time with input title given
{
    /*if	(Nplots	==	0)	//create	application
    {
      TApplication	*	MyRootApp;
      MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
      MyRootApp->SetReturnFromRun(true);
    }
    Nplots++;

    double* x = new double[time.size()];
    double* y = new double[signal.size()];

    for (int i = 0; i < time.size(); i++)
    {
        x[i] = time[i];
        y[i] = signal[i];
    }
    TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);
    gPad->Clear();
    TGraph* graph = new TGraph(time.size(), x, y);
    graph->SetTitle(title.c_str());
    graph->GetXaxis()->SetTitle("Time");
    graph->GetYaxis()->SetTitle("Amplitude");
    graph->Draw("AP");

    c1->Update();
    gPad->WaitPrimitive();
    delete c1;
    delete graph;
*/

    int size = time.size();
    double* x = new double[size];
    double* y = new double[size];

    for(int i =0; i<size; i++)
    {
      x[i]=time[i];
      y[i]=signal[i];
    }
    string filename = title + ".eps";
    cout << filename << endl;
    DataPoints dp(size,x,y);
    dp.Draw(title.c_str());
    dp.Print(filename.c_str());
    delete[] x;
    delete[] y;
}

double Signal::Sampling_freq() const //return the sampling frequency i.e. 1/(time[i+1]-time[i])
{
    if(signal.size() < 2)
    {
        cout << "Signal tem de ter dimensão superior a 1\n";
        exit(EXIT_FAILURE);
    }
    return 1.0/(time[1]-time[0]);
}
