/******************************************************************************
Root script to plot histograms of the minimum ADC value of a cosmic event,
both Paddles-in and Paddles-out data in the same canvas
*******************************************************************************/

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TGraph.h> 
#include <TLine.h>
#include <TLatex.h> 
#include <TPaveStats.h>

void Min_ADC_val_combined() {
	gROOT->Reset("a"); //Resets and deletes all the previous objects
	gROOT->Clear(); //Clears all objects in the memory
	
	TChain chain1("t1"); //Chain for Paddles-in data
	chain1.Add("Tree_1065_fixed.root");
    chain1.Add("Tree_1066_fixed.root");
    chain1.Add("Tree_1069_fixed.root");
    chain1.Add("Tree_1070_fixed.root");
    chain1.Add("Tree_1071_fixed.root");
    chain1.Add("Tree_1072_fixed.root");
    chain1.Add("Tree_1073_fixed.root");
    chain1.Add("Tree_1074_fixed.root");
    chain1.Add("Tree_1075_fixed.root");

    TChain chain2("t1"); //Chain for Paddles-out data
    chain2.Add("Tree_1067_fixed.root");
	
	//Variable assignment
	const Int_t knumsamples = 4096; //Change the value for different sample sizes
	const Int_t post_trig = 1024;
	const Int_t trig_pt = 3034; //Mean value of Min ADC sample
	const Int_t dsamples = 10; //10 samples pre/post trig
	const Int_t upper_limit =  trig_pt - dsamples;
	const Int_t lower_limit = trig_pt + dsamples;
	
    //Chain1 variables
	Float_t chain1_ch1[knumsamples];
	Float_t chain1_ch2[knumsamples];
	//const Int_t colors[5] = {kGreen, kMagenta, kOrange, kRed, kBlue}; 
	std::vector<Float_t> chain1_min_vals_ch1;
	std::vector<Float_t> chain1_min_vals_ch2;
	Long64_t chain1_nentries = chain1.GetEntries();
	Float_t chain1_min_ch1;
	Float_t chain1_min_ch2;
	
	//Set up branches to channels
	chain1.SetBranchAddress("ch1", chain1_ch1);
	chain1.SetBranchAddress("ch2", chain1_ch2);

    //Chain2 variables
	Float_t chain2_ch1[knumsamples];
	Float_t chain2_ch2[knumsamples];
	std::vector<Float_t> chain2_min_vals_ch1;
	std::vector<Float_t> chain2_min_vals_ch2;
	Long64_t chain2_nentries = chain2.GetEntries();
	Float_t chain2_min_ch1;
	Float_t chain2_min_ch2;
	chain2.SetBranchAddress("ch1", chain2_ch1);
	chain2.SetBranchAddress("ch2", chain2_ch2);

    for (Long64_t i = 0; i < chain1_nentries; i++) {
        chain1.GetEntry(i);

        chain1_min_ch1 = *std::min_element(chain1_ch1 + upper_limit, chain1_ch1 + lower_limit);
        chain1_min_ch2 = *std::min_element(chain1_ch2 + upper_limit, chain1_ch2 + lower_limit);

        chain1_min_vals_ch1.push_back(chain1_min_ch1);
        chain1_min_vals_ch2.push_back(chain1_min_ch2);
    }

    TH1F *hist1 = new TH1F("Paddles-in", "Min ADC value variation for all events; ADC val; Count", 100, 1500, 2150);

    for (auto value : chain1_min_vals_ch2) {
        hist1->Fill(value);
    }

    for (Long64_t i = 0; i < chain2_nentries; i++) {
        chain2.GetEntry(i);

        chain2_min_ch1 = *std::min_element(chain2_ch1 + upper_limit, chain2_ch1 + lower_limit);
        chain2_min_ch2 = *std::min_element(chain2_ch2 + upper_limit, chain2_ch2 + lower_limit);

        chain2_min_vals_ch1.push_back(chain2_min_ch1);
        chain2_min_vals_ch2.push_back(chain2_min_ch2);
    }

    TH1F *hist2 = new TH1F("Paddles-out", "Min ADC value variation for all events; ADC val; Count", 100, 1500, 2150);

    for (auto value : chain2_min_vals_ch2) {
        hist2->Fill(value);
    }

    TCanvas *c = new TCanvas("c", "Canvas", 800, 600);
	double y_min = 0;
	double y_max = hist1->GetMaximum();
	TLine *line = new TLine(2070, y_min, 2070, y_max);
	TLatex *latex = new TLatex();

    hist1->GetXaxis()->CenterTitle();
    hist1->GetYaxis()->CenterTitle();
    hist1->SetLineColor(kRed);
	gPad->SetLogy();
    hist1->Draw();

    hist2->SetLineColor(kBlue);
    hist2->Draw("sames");

	//line->SetLineColor(kRed);
	//line->SetLineStyle(1);
	//line->SetLineWidth(2);
	//line->Draw("same");

	latex->SetTextFont(42);
	latex->SetTextSize(0.03);
	latex->SetTextAlign(13);
	latex->DrawLatexNDC(0.15, 0.65, "First production model");
    latex->DrawLatexNDC(0.15, 0.60, "Combined data");

	gPad->Update();
	TPaveStats *stat1 = (TPaveStats*)hist1->FindObject("stats");
	stat1->SetX1NDC(0.45);
	stat1->SetY1NDC(0.7);
	stat1->SetX2NDC(0.65);
	stat1->SetY2NDC(0.9);
    stat1->SetTextColor(kRed);
	stat1->Draw();

    TPaveStats *stat2 = (TPaveStats*)hist2->FindObject("stats");
	stat2->SetX1NDC(0.2);
	stat2->SetY1NDC(0.7);
	stat2->SetX2NDC(0.4);
	stat2->SetY2NDC(0.9);
    stat2->SetTextColor(kBlue);
	stat2->Draw();
	gPad->Modified();
	gPad->Update();

    c->SaveAs("MinValVariation_Combined.png");
}
