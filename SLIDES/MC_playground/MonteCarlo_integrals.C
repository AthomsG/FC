{

/*	
*/

double xmin=...; 
double xmax=...;

gStyle->SetOptStat(1);

TF1 *f2 = new TF1("f2","0.5",xmin,xmax);

TRandom3 rgen; //by giving (0) i.e. seed=0 i ensure that the seed 
                  //is guaranteed to be unique in space and time

int M=5000;
double * Nsamples = new double[M];
double * Estimate2 = new double[M];

for (int j=0;j<M;j++) {

	Nsamples[j]=20+j;
	int N=Nsamples[j];

	double F2=0.;
	double f2s=0.;

	for (int i=0;i<N;i++) {
		//double x = xmin+(xmax-xmin)*rgen.Uniform(0,1);
		double x = xmin+(xmax-xmin)*gRandom->Uniform();
		double func2= f2->Eval(x);
	
		F2 += func2;
		f2s += func2*func2;
	}

	//mean
	double f2m = F2/N;

	// integrals
	double I2 = ...;

	// variances
	double Var2 = ...

	// errors
	double E2= ...;

	Estimate2[j]=I2;
}

TCanvas *c = new TCanvas("c", "A simple Graph Example", 0, 0, 500, 300);
c->SetLogx();
c->SetLogy();
c->SetGridx();
c->SetGridy();


TGraph* gr2 = new TGraph(M,Nsamples,Estimate2);
gr2->SetMarkerStyle(24);
gr2->Draw("AP");
c->Modified();
c->SaveAs("Integral_f2.eps");



}
