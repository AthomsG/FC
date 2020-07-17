{
	
	/* Sugestão: usar este exemplo simples para treinar com a TFormula.......
	*/
	
TF1 *f3 = new TF1("gauss", "[0] / sqrt(2.0 * TMath::Pi()) / [2] * exp(-(x-[1])*(x-[1])/2./[2]/[2])", 0., 4.);
f3->SetParameters(1.0,2.0,0.5);
double area = f3->Integral(0,4.0);
f3->SetParameters(1.0/area,2.0,0.5);
f3->Draw();

}