#include "InBox1D.h"
#include <cstdio>
#include "TGraph.h"
#include "TCanvas.h"
#include "TAxis.h"
#include "TApplication.h"
#include <utility>
using namespace std;

int main()
{
	TApplication	*	MyRootApp;
	MyRootApp	=	new	TApplication("click	twice",	NULL,	NULL);
	MyRootApp->SetReturnFromRun(true);

	double* m= new double[2]{1,10};
	double* x0= new double[2]{5,10};
	double* v0= new double[2]{0,-1};
	double alpha=1;//0.99;
	double t0=0.0;

	InBox1D Obj(x0,v0,m,alpha);

	double ttime = 10; //total run time
	double dt = 0.005; //step time...

	//prepare to store the solution in vectors...
	vector<pair<double,double>> xobj;
	xobj.push_back(make_pair(x0[0],x0[1]));
	vector<pair<double,double>> vobj;
	vobj.push_back(make_pair(v0[0],v0[1]));
	vector<double> tobj;
	tobj.push_back(t0);

	double tcur=t0;

	while (tcur <= ttime)
	{
			Obj.StepInTime(dt);
      tcur += dt;
      xobj.push_back(make_pair(Obj.GetX()[0],Obj.GetX()[1]));
      vobj.push_back(make_pair(Obj.GetV()[0],Obj.GetV()[1]));
      tobj.push_back(tcur);
	}

	int npoints=xobj.size();
	double * xptr=new double [npoints];
	double * vptr=new double [npoints];
	double * tptr=new double [npoints];

	//...now transfer the time, psoition-X and velocity-V to pointer arrays
    for (int i = 0; i < npoints; i++)
    {
        xptr[i]=xobj[i].first;
        vptr[i]=vobj[i].first;
        tptr[i]=tobj[i];
    }


	TCanvas *c = new TCanvas("c", "My_trajectory",200,10,600,400);
    c->Divide(2,1);
    // Generate a plot of the time evolution of position X(t)
    // and velocity V(t) of the object on a single canvas,
    // X(t) on the top and V(t) on the bottom.
    //...

    c->cd(1);
    TGraph* graph = new TGraph(npoints, tptr, xptr);
    graph->SetTitle("Evolucao em x");
    graph->GetXaxis()->SetTitle("t");
    graph->GetYaxis()->SetTitle("x");
    graph->Draw("AP");
    c->Update();

    c->cd(2);
    TGraph* graph2 = new TGraph(npoints, tptr, vptr);
    graph2->SetTitle("Evolucao em v");
    graph2->GetXaxis()->SetTitle("t");
    graph2->GetYaxis()->SetTitle("v");
		graph2->SetMarkerSize(1);
    graph2->Draw("APSAME");
    c->Update();

		c->Modified();
		gPad->WaitPrimitive();
		c->SaveAs("Trajectory.eps");

    delete[] xptr;
    delete[] vptr;
    delete[] tptr;
		cout << "Nr of collisions: " << Obj.GetN() << endl;
}
