#ifndef PIC_H
#define PIC_H
#include <vector>
#include "ODEsolver.hpp"
#include "Vec.hpp"
#include "TApplication.h"
#include "TMarker.h"
#include "TCanvas.h"
#include "TLegend.h"
#include "TObject.h"
#include <utility>
using namespace std;

class PIC
{
  public:
    PIC(vector<double> velocity, int Npart=1000, double xmin=0.0, double xmax=1.0, int ngrid=100);
    ~PIC();
    // metodos
    void FdistV(vector<double> veloc, bool save_plot, bool show_plot=false);
    void Plot_Phase_Space(bool save_plot, bool show_plot=false);
    void Density(bool save_plot, bool show_plot=false);
    void Poisson(bool save_plot, bool show_plot=false);
    void TimeStep(double dt);
    // modo animacao
    void AnimateMode(bool set) {animate = set; }
  private:
    vector<double> velocity; //velocidades dos dois feixes
    int Npart; // numero de particulas
    double xmin;
    double xmax;
    int ngrid; // numero de pontos na grelha espacial
    double dx; //incremento espacial
    double* x; //coordenadas da grelha espacial
    double* n; //densidade electronica
    double* phi; //potencial electrico
    double* r; // posiçoes dos electroes
    double* v; // velocidades dos electroe
    ODEpoint odep;
    vector<TFormula> tform; // sistema de equaçoes que gere o sistema
    ODEsolver odes;
    double sim_time; // tempo da simulaçao (em unidades normalizadas)
    // elementos graficos
    double* color_track; //sinaliza as particulas dos dois feixes iniciais para as diferenciar por cor
    int* Nobj; // numero de objectos das funcoes [FdistV,phase_space,density,potential]
    bool animate = false; // modo animate!!
    TApplication* MyRootApp;
    TCanvas* c;
    TLegend* legend;
    TMarker* m;
    //metodos graficos
    void Draw(TObject* obj1, TObject* ob2 ,bool colors = false, bool show_plot = false);
    void Save(string filename);
};

#endif
