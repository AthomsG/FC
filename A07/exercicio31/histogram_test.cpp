void histogram_test()
{
    TCanvas* grafico = new TCanvas("g1", "Histogramas", 1);
    grafico->Divide(3, 1); // horizontal and vertical divisions

    //Creates random numbers generator
    TRandom3 rgen(0);
    //Creates array of 3 histogram objects

    //TH1F objeto[3] = {TH1F("h1", "Histogram 1", 100, -10, 10), TH1F("h2","Histogram 2", 100, -10, 10), TH1F("h3", "Histogram 3", 100, -10, 10)};

    //PORQUE NÃO FUNCIONA QUANDO CRIO UM ARRAY DE TH1F???

    TH1F* objeto = new TH1F[3];

    // 100 bins, between -10 and 10 (bin size = 0.2)
    objeto[0] = TH1F("h1", "Histogram 1", 100, -10, 10);
    objeto[1] = TH1F("h2", "Histogram 2", 100, -10, 10);
    objeto[2] = TH1F("h3", "Histogram 3", 100, -10, 10);

    // a)
    for (int i = 0; i<100000 ;i++) {
        objeto[0].Fill(rgen.Uniform(-5, 5));
    }
    //define 2x^2 entre -10 e 10
    TF1 *f1 = new TF1("f1","2*x**2",-10,10);

    for (int i = 0; i<100000 ;i++) {
        objeto[1].Fill(f1->GetRandom(-10,10));
    }
    //define aquilo entre -10 e 10
    TF1 *f2 = new TF1("f2", "1/(sqrt(2*[0])*[1])*exp(-x*x/(2*[1]*[1]))",-10,10);
    f2->SetParameters(0,3.14); //param 0 = pi
    f2->SetParameters(1,2); // param 1 = 2

    for (int i = 0; i<100000 ;i++) {
        objeto[2].Fill(f2->GetRandom(-10,10));
    }

    grafico->cd(1);
    objeto[0].Draw();

    grafico->cd(2);
    objeto[1].Draw();

    grafico->cd(3);
    objeto[2].Draw();

    grafico->Update();
    grafico->SaveAs("a).eps");
}
