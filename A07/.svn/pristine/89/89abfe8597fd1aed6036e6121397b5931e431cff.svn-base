#include <iostream>
using namespace std;
#include "Signal.h"
#include "DFT.h"
#include "TApplication.h"
#include "TGraph.h"
#include "TAxis.h"
#include "TCanvas.h"

int main()
{
	string name;
	cout << "Introduza o nome do ficheiro: ";
	cin >>  name;
	Signal s1 = Signal("Signal.txt");
	s1.Plot(name); //Produce figure Signal_s1.eps

	cout << s1.GetTime()[10] << endl;
	cout << s1[10].first << endl; //same objective of previous line but using in syntax s1[10]

	Signal s2;
	s2=s1;
	s2.Plot("Signal_s2"); //Produce figure Signal_s2.eps

	Signal s3(s1*5.0);
	s3.Plot("Signal_s3"); //Produce figure Signal_s3.eps

	Signal s4;
	s4=s1*s3;
	s4.Plot("Signal_s4"); //Produce figure Signal_s4.eps

	DFT DFT1(s1);
	double fs=s1.Sampling_freq();
	cout << "Sampling Frequency = " << fs << endl;

	int nfreq=1000;
	double * freq = new double [nfreq];
	double * PS = new double [nfreq];

	for (int i=0;i<nfreq;i++)
	{
		freq[i]= 2+i*0.01; //frequencies between 2 and 20Hz.
		PS[i]=DFT1.GetAmpSpec(freq[i]);
	}

	TCanvas *c1 = new TCanvas("c1","Data Plot",700,500);
	TGraph* graph = new TGraph(nfreq, freq, PS);
	graph->SetTitle("MySpectra");
	graph->GetXaxis()->SetTitle("Freq (Hz)");
	graph->GetYaxis()->SetTitle("Amplitude (a.u.)");
	graph->Draw("ACP");

	c1->Update();
	c1->SaveAs("MySpectra.eps");

	delete[] freq;
	delete[] PS;
	delete c1;
	delete graph;

	return 0;
}
