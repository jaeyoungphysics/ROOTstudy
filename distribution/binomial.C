#include <cassert>
#include <cmath>

#include "TH1.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TRandom.h"

TCanvas *binomial()
{
	TH1* h = new TH1D("h", "binomial distribution", 100, 0., 100.);

	TRandom3 r;
	for (Int_t i = 0; i < 1u << 20 ; ++i){
		Double_t x1 = r.Binomial(100,0.5);
		h->Fill(x1);
	}
	TH1* hc = h->GetCumulative();

/*	Double_t* integral = h->GetIntegral();
	for (Int_t i = 1; i <= hc->GetNbinsX(); ++i){
		assert(std::abs(integral[i] * h->GetEntries() - hc->GetBinContent(i)) < 1e-7);
	}
*/
	TCanvas* c = new TCanvas;
	c->Divide(1,2);
	c->cd(1);
	h->Draw();
	c->cd(2);
	hc->Draw();
	c->Update();

	return c;
}

