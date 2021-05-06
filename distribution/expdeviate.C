TCanvas* expdeviate(){

	TH1* h = new TH1D("histogram", "Exponential Deviate", 100, 0., 50);
	TRandom3 r;

	for ( Int_t i = 0; i < 1u << 16; ++i){
		Double_t x1 = r.Exp(10);
		h->Fill(x1);
	}

	TCanvas* c1 = new TCanvas("c1", "pdf", 10, 10, 700, 500);
	h->Draw();

	TH1* hc = h->GetCumulative();
	TCanvas* c2 = new TCanvas("c2", "cdf", 10, 510, 700, 500);
	c2->cd();
	hc->Draw();

	h->GetXaxis()->SetTitle("t");
	hc->GetXaxis()->SetTitle("t");

	return c1,c2;
}

