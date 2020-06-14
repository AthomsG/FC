//Não percebi se era isto que o professor queria

void histogram_test_mean()
{
    double mean1, mean2;
    
    int N = 100000;
    
    TCanvas* grafico = new TCanvas("g1", "Histogramas", 1);
    grafico->Divide(2, 1);
    
    TRandom3 rgen(0);
    
    TH1F* objeto = new TH1F[2];
    
    objeto[0] = TH1F("h1", "Histogram 1", 500, -4, 4);
    objeto[1] = TH1F("h2", "Histogram 2", 500, -4, 4);
    
    // a)
    TF1 *f1 = new TF1("f1","x**2", -4, 4);
    
    for (int i = 0; i<10000; i++){
        mean1 = 0;
        mean2 = 0;
        for (int i = 0; i<N; i++) {
            mean1 += f1->GetRandom();
        }
        for (int i = 0; i<N; i++) {
            mean2 += rgen.Uniform(-4, 4);
        }
        objeto[0].Fill(mean1/N);
        objeto[1].Fill(mean2/N);
    }
    grafico->cd(1);
    objeto[0].Draw();
    
    grafico->cd(2);
    objeto[1].Draw();
    
    grafico->Update();
    grafico->SaveAs("histograma_teste_mean.eps");
}

