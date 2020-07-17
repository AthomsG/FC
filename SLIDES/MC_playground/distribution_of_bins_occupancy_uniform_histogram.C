{
gStyle->SetOptStat(1);
TCanvas *c = new TCanvas("c", "uniform distribution",0,0,500,500);

int Nbins=100;
int Ntrials=1000;
int Nexpe=2000;

double range=(1.0-0.0);
TH1D * h1 = new TH1D("h1", "h1", Nbins, 0.+range/(double)Nbins, 1.+range/(double)Nbins);

TRandom3 rgen(0); //by giving (0) i.e. seed=0 i ensure that the seed 
                  //is guaranteed to be unique in space and time

for (int i=0;i<Ntrials;i++) {
    h1->Fill(rgen.Uniform(0,1));
}

double tmp,err;
double avgbin_occup=(double)Ntrials/(double)Nbins;
double binaxis;
TGraphErrors * gr1 = new TGraphErrors(Nbins);
for (int i=0;i<Nbins;i++) {
	binaxis = h1->GetXaxis()->GetBinCenter(i);
	cout << binaxis << endl;
	tmp = (h1->GetBinContent(i) - avgbin_occup)/avgbin_occup;
	err = h1->GetBinError(i)/avgbin_occup;
//	tmp = (h1->GetBinContent(i));
//	err = h1->GetBinError(i);
	gr1->SetPoint( i, binaxis, tmp );
	gr1->SetPointError( i, 0, err );
}
h1->Reset(); //ja nao preciso do h1 entao apaga conteudo

gr1->SetMarkerStyle(20);
gr1->SetMarkerColor(2);
gr1->SetLineColor(2);
gr1->SetTitle("Normalised error in bin occupancy");
gr1->GetXaxis()->SetRangeUser(0.,1.);
gr1->Draw("APE");



Ntrials*=10.;
for (int i=0;i<Ntrials;i++) {
    h1->Fill(rgen.Uniform(0,1));
}
avgbin_occup=(double)Ntrials/(double)Nbins;
TGraphErrors * gr2 = new TGraphErrors(Nbins);
for (int i=0;i<Nbins;i++) {
	binaxis = h1->GetXaxis()->GetBinCenter(i);
	tmp = (h1->GetBinContent(i) - avgbin_occup)/avgbin_occup;
	err = h1->GetBinError(i)/avgbin_occup;
//	tmp = (h1->GetBinContent(i));
//	err = h1->GetBinError(i);
	gr2->SetPoint( i, binaxis, tmp );
	gr2->SetPointError( i, 0, err );
}
h1->Reset();

gr2->SetMarkerStyle(21);
gr2->SetMarkerColor(4);
gr2->SetLineColor(4);
gr2->GetXaxis()->SetRangeUser(0.,1.);
gr2->Draw("SAME PE");


c->Modified();
c->SaveAs("Normalised_bin_distribution_Uniform_graph.eps");
delete c;
delete gr1,gr2,h1;

//##########################################################
// And now for the distribution of these normalised errors....
c = new TCanvas("c", "normalised error in bins",0,0,500,500);
Ntrials=100000;
Nbins=1000;
h1 = new TH1D("h1", "h1", Nbins, 0.+range/(double)Nbins, 1.+range/(double)Nbins);
h2 = new TH1D("h2", "normalised error in bins", Nbins, -0.5, 0.5);
avgbin_occup=(double)Ntrials/(double)Nbins;
for (int k=0;k<Nexpe;k++) {
	for (int i=0;i<Ntrials;i++) {
	    h1->Fill(rgen.Uniform(0,1));
	}
	gr2 = new TGraphErrors(Nbins);
	for (int i=0;i<Nbins;i++) {
		binaxis = h1->GetXaxis()->GetBinCenter(i);
		tmp = (h1->GetBinContent(i) - avgbin_occup)/avgbin_occup;
		//cout << tmp << endl;
		err = h1->GetBinError(i)/avgbin_occup;
		h2->Fill(tmp);
	}
	h1->Reset();
}
delete gr2;

h2->Draw("HIST");
c->Modified();
c->SaveAs("Normalised_bin_distribution_Uniform_hist.eps");

}
