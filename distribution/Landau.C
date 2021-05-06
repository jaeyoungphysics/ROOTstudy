TCanvas* Landau(){

        TH1* h = new TH1D("histogram","Landau distribution",100, 0., 100.);
        TRandom3 r;

        for (Int_t i = 0; i < 1u << 16 ; ++i){
		Double_t x1 = r.Landau(10,1);
	        h->Fill(x1);
        }

        TCanvas* c1 = new TCanvas("c1","pdf",10,10,700,500);
        h->Draw();

        TH1* hc = h->GetCumulative();
        TCanvas* c2 = new TCanvas("c2","cdf",10,510,700,500);
        c2->cd();
        hc->Draw();

        h->GetXaxis()->SetTitle("n");
        hc->GetXaxis()->SetTitle("n");

        return c1,c2;
}
