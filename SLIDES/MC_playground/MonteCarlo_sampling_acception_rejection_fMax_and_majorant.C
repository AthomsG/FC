{

gStyle->SetOptStat(0);
TCanvas *c = new TCanvas("c", "3.x**2 distribution normalised",0,0,500,500);
//TLegend *legend = new TLegend(0.5,0.5,0.9,0.6);

Nsamp=100000;

//Use TF1->GetRandom() to draw from actual function we wish 
//to use as distribution function (regardeless of being normalised or not)
TF1 *f1 = new TF1("f1","3*x*x",3.,7.);
TH1D *h1 = new TH1D("h1", "3*x*x distribution normalised", 200, 3., 7.);
for (int i=0; i<Nsamp; i++) {
	h1->Fill(f1->GetRandom());
}
Double_t norm = h1->GetEntries();
h1->Scale(1/norm);
cout<<"Using the GetRandom() method i collect "<<norm<<" samples out of "<<Nsamp<<" draws "<<endl;

h1->SetLineColor(kBlue);
h1->SetLineWidth(2.0);
//h1->Draw("HIST");

// Now we "draw" from a Uniform in [a,b] and accept-reject using
// "fMax" method....
TRandom3 rgen(0); 
TH1D *h2 = new TH1D("h2", "Accept-Reject with fMax", 200, 3., 7.);
//double fMax=f1->Eval(7.0);
double fMax=50;
for (int i=0;i<Nsamp;i++) {
	double x=rgen.Uniform(3.,7.);
	double u=rgen.Uniform(0.,1.);
	if (u < f1->Eval(x)/fMax)
    	h2->Fill( x );
}
norm = h2->GetEntries();
h2->Scale(1/norm);
cout<<"Using the fMax method i collect "<<norm<<" samples out of "<<Nsamp<<" draws "<<endl;


h2->SetLineColor(kRed);
h2->SetLineWidth(2.0);
//h2->Draw("HIST SAME");


THStack *s = new THStack("histstack", "ROOT f1->GetRandom() vs User Accept-Reject");
s->Add(h1);
s->Add(h2);

s->Draw("HIST nostack");

c->BuildLegend(0.1,0.7,0.4,0.9);
c->Modified();
c->SaveAs("Accept-Reject.eps");

}
