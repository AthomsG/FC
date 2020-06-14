#include "PIC.h"
#include <iostream>
#include <vector>
#include <string>
#include "TFormula.h"
#include "TF1.h"
#include "TMath.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TRandom3.h"
#include "TLegend.h"
#include "TStyle.h"
#include "TAxis.h"
#include "TMarker.h"
#include "TH1F.h"
#include "EqSolver.hpp"
#include "Spline3Interpolator.hpp"
#include "ODEsolver.hpp"
using namespace std;

PIC::PIC(vector<double> velocity, int Npart, double xmin, double xmax, int ngrid)
{
    this->velocity=velocity;
    this->Npart=Npart;
    this->xmin=xmin;
    this->xmax=xmax;
    this->ngrid=ngrid;
    dx = (xmax-xmin)/(double)(ngrid-1);

    r = new double[Npart];
    v = new double[Npart];
    color_track = new double[Npart];

    x = new double[ngrid];
    n = new double[ngrid];
    phi = new double[ngrid];

    for (int i = 0; i < ngrid; i++){
        x[i]=xmin+i*dx;
        n[i] = 0;
        phi[i]=0;
    }
    // x = r (position) ; y = v (velocity) ; [0] = ef (electric field)
    TFormula func1("f1", "y");  // x' = y  => r'[i] = v[i]
    TFormula func2("f2", "-[0]"); // y' = -[0]  => v'[i] = -ef[i]

    tform.push_back(func1);
    tform.push_back(func2);
    odes = ODEsolver(tform);
    // GRAPHIXXX
    sim_time = 0;
    Nobj = new int[3]{0,0,0};

    MyRootApp = new TApplication("Crank that Button", 0, NULL);
    MyRootApp->SetReturnFromRun(kTRUE);

    c = new TCanvas("c1", "c1", 200, 50, 1200, 800);
    gStyle->SetOptTitle(0);
    m = new TMarker[Npart];
    legend = new TLegend(0.1,0.83,0.21,0.9);
}

void PIC::FdistV(vector<double> veloc, bool save_plot, bool show_plot) // initial velocity and position distribution
{
    velocity = veloc;
    //setting a very reasonable range for the PDF, then applying acceptance rejection method
    int x0= (int)(velocity[0]<velocity[1] ? velocity[0] : velocity[1]) - 10; // 10 sigma (sigma=1)
    int x1= (int)(velocity[1]<velocity[0] ? velocity[0] : velocity[1]) + 10; // 10 sigma

    //normalized PDF
    TF1* f1 = new TF1("PDF","(exp(-pow((x-[0]),2)/2)+exp(-pow((x-[1]),2)/2))/[2]",x0,x1);
    f1->SetParameters(velocity[0],velocity[1],2*sqrt(2*TMath::Pi()));
    f1->SetNpx(1000);
    f1->SetTitle("Normalised PDF #it{vs} Acceptance Rejection");

    TH1F* h1 = new TH1F("h1","",100,x0,x1);
    double bin_length=(x1-x0)/100.0;

    // ACCEPTANCE REJECTION -----------------------------------------
    TRandom3 rgen(0);
    double uf, ur, xr;
    double fmax = (double)f1->GetMaximum(); //maximum value of pdf function

    for(int i =0; i< Npart; i++)
    {
        r[i]=xmin+rgen.Uniform(0,1)*(xmax-xmin);
        do{
            xr = x0+rgen.Uniform(0,1)*(x1-x0);
            uf = f1->Eval(xr)/fmax;
            ur = rgen.Uniform(0,1);
        } while(ur>uf);
        v[i]=xr;
        if(v[i]<=0) //tracks the particles of the beam with negative velocity
            color_track[i]=-1;
        else //tracks the particles of the beam with positive velocity
            color_track[i]=1;
        h1->Fill(v[i]);
    }
    h1->Scale(1.0/(Npart*bin_length)); //normalized histogram

    if(!save_plot && !show_plot)  {
        delete f1;
        delete h1;
        return;
    }

    Draw(f1,h1,false,show_plot);
    if(save_plot)
        Save("../FdistV.png");
    delete f1;
    delete h1;
}

void PIC::Plot_Phase_Space(bool save_plot, bool show_plot)
{
    if(!save_plot && !show_plot)
        return;

    TGraph* g2 = new TGraph(Npart,r,v);
    g2->SetTitle("Phase Space");
    g2->GetXaxis()->SetLimits(xmin,xmax);
    g2->SetMarkerStyle(6);
    g2->GetXaxis()->SetTitle("r");
    g2->GetYaxis()->SetTitle("v");

    Draw(g2,NULL,true,show_plot); // color = true => two beams of different colors
    if (save_plot)
        Save("../phase_space" + to_string(Nobj[0]) + ".png");
    if(save_plot)
        Nobj[0]++;
    delete g2;
}

void PIC::Density(bool save_plot, bool show_plot)
{
    for(int i =0; i<ngrid;i++)  {
        n[i]=-1;
    }
    int j = 0;
    double n0 = Npart/(xmax-xmin);
    for(int i = 0; i < Npart; i++)
    {
        j = (int)((r[i]-xmin)/dx); // position in grid:  x[j] <= r[i] < x[j+1]
        n[j] += (x[j+1]-r[i])/(dx*dx*n0);
        n[j+1] += (r[i]-x[j])/(dx*dx*n0);
        if(j==0) // first and last position are considered to be the same in space (due to periodic boundary conditions)
          n[ngrid-1] += (x[1]-r[i])/(dx*dx*n0);
        else if(j+1==ngrid-1)
          n[0] += (r[i]-x[ngrid-2])/(dx*dx*n0);
    }

    if(!save_plot && !show_plot)
        return;

    TGraph* g3 = new TGraph(ngrid, x, n);
    g3->SetTitle("Density");
    g3->GetXaxis()->SetLimits(xmin,xmax);
    g3->SetMarkerStyle(6);
    g3->GetXaxis()->SetTitle("x");
    g3->GetYaxis()->SetTitle("n(x)");

    Draw(g3,NULL,false,show_plot);
    if(save_plot)
        Save("../density" + to_string(Nobj[1]) + ".png");
    if(save_plot)
      Nobj[1]++;
    delete g3;
}

void PIC::Poisson(bool save_plot, bool show_plot) //solving poisson equation
{
    // boundary value problem with finite differences:
    // phi''[i] = (phi[i+1]-2*phi[i]+phi[i-1])/(h*h);
    // with phi[0] = phi[ngrid] = 0 (boundary conditions)

    Vec lower(ngrid-1,1);
    lower[ngrid-2]=0;

    Vec main(ngrid,-2);
    main[0]=1;
    main[ngrid-1]=1;

    Vec upper(ngrid-1,1);
    upper[0]=0;

    FCmatrixBanded mb(lower,main,upper);

    Vec b(ngrid,0.0);

    for(int i = 1; i<ngrid-1; i++)  {
        b[i]=n[i]*dx*dx;
    }

    EqSolver potential(mb,b);
    Vec sol = potential.TridiagonalSolver();

    for(int i= 0; i<ngrid; i++) {
        phi[i]=sol[i];
    }

    if(!save_plot && !show_plot)
        return;

    TGraph* g4 = new TGraph(ngrid, x, phi);
    g4->GetXaxis()->SetLimits(xmin,xmax);
    g4->SetTitle("Potential");
    g4->SetMarkerStyle(7);
    g4->GetXaxis()->SetTitle("x");
    g4->GetYaxis()->SetTitle("#phi(x)");

    Draw(g4,NULL,false,show_plot);
    if(save_plot)
        Save("../potential" + to_string(Nobj[2]) + ".png");
    if(save_plot)
      Nobj[2]++;
    delete g4;
}

void PIC::TimeStep(double dt)
{
    Spline3Interpolator Fphi(ngrid,x,phi); // interpolate the potential
    Fphi.IsEvenlySpaced(true);

    vector<ODEpoint> sol;
    double* var = new double[2];
    odep=ODEpoint(0,var,2);

    for(int i=0; i<Npart; i++)
    {
        odep[0]=r[i];
        odep[1]=v[i];
        odes.SetParameter(1,0,-Fphi.Derivative1(r[i]));
        sol = odes.RK4solver(odep, 0, dt, dt);
        r[i]=sol[0][0];
        v[i]=sol[0][1];
        // periodic boundar conditions
        while(r[i]>xmax) {
            r[i]-=(xmax-xmin);
        }
        while(r[i]<xmin) {
            r[i]+=(xmax-xmin);
        }
    }
    sol.clear();

    sim_time+=dt;
    delete[] var;
}

void PIC::Draw(TObject* obj1, TObject* obj2, bool colors, bool show_plot)
{
    //gROOT->SetBatch(kTRUE); // ?

    gPad->Clear();

    if(obj1->InheritsFrom("TGraph") && obj2==NULL)
    { // phase_space, density, poisson
        obj1->Draw("AP");
        if(colors)
        { // create markers of different colors to track the 2 beams throughout the simulation
            for (Int_t i=0; i<Npart; i++) {
                m[i].SetMarkerStyle(6);
                m[i].SetX(r[i]);
                m[i].SetY(v[i]);
                if(color_track[i]>0)
                    m[i].SetMarkerColor(2);
                else
                    m[i].SetMarkerColor(4);
                m[i].Draw();
            }
        }
    } else if (obj1->InheritsFrom("TF1") && obj2->InheritsFrom("TH1F"))
    { //FdistV
      obj1->Draw();
      obj2->Draw("HIST SAME");
    }
    // desenha uma legenda com o tempo actual de simulacao, duas casas decimais
    string aux_time = to_string(sim_time);
    aux_time.erase(aux_time.end()-4, aux_time.end());
    legend->SetHeader(("t = " + aux_time).c_str(),"C");
    legend->Draw();

    c->Update();

    /*if(show_plot) {
      c->SetBatch(kFALSE);
      MyRootApp->Run();
    }*/

    if(animate || !show_plot)
        gPad->Update();
    else if (show_plot)
        gPad->WaitPrimitive();


}

void PIC::Save(string file)
{
    c->Modified();
    c->SaveAs(file.c_str());
}

PIC::~PIC() //destructor
{
    delete[] r;
    delete[] v;
    delete[] color_track;
    delete[] x;
    delete[] n;
    delete[] phi;
    delete[] m;
    delete[] Nobj;
    delete legend;
    delete c;
}
