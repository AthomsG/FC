#include "PIC.h"
#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	double xmin=0.0;
	double xmax=30;
	int Npart=100000;
	int ngrid=(xmax-xmin)/0.05+1; //dx = 0.05
	double dt=0.04;

	vector<double> velvec(2);
	velvec[0]=5; 	// velocidade do primeiro feixe
	velvec[1]=-5;  // velocidade do segundo feixe

	PIC twofluid=PIC(velvec,Npart,xmin,xmax,ngrid);

	twofluid.FdistV(velvec,1,1);
	twofluid.Plot_Phase_Space(1,1);
	twofluid.Density(1,1);
	twofluid.Poisson(1,1);

	// aconselhavel usar dados mais leves para um bom proveito do modo animaçao
	twofluid.AnimateMode(true);
	// guardar os plots a cada (rate) iteraçoes do ciclo seguinte
	int rate = 20;

	for (int i=1;i<=1500;i++) {
		twofluid.TimeStep(dt);
		twofluid.Density(i%rate==0,0);
		twofluid.Poisson(i%rate==0,0);
		twofluid.Plot_Phase_Space(i%rate==0,1);
		cout << i << endl;
	}
	twofluid.AnimateMode(false);

	return 0;
}
