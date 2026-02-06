/***************************************************************
Root script to produce histograms of the ADC sample idx which
corresponds to the minimum ADC value of cosmic a event, 
for both Paddles-in and Paddles-out data
****************************************************************/

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TGraph.h>
#include <TLatex.h> 
#include <TPaveStats.h>

void Min_Sample_combined() {
    gROOT->Reset("a");
    gROOT->Clear();

    TChain chain1("t1"); //Paddles-in data chain
    chain1.Add("Tree_1066_fixed.root");
    chain1.Add("Tree_1065_fixed.root");
    chain1.Add("Tree_1069_fixed.root");
    chain1.Add("Tree_1070_fixed.root");
    chain1.Add("Tree_1071_fixed.root");
    chain1.Add("Tree_1072_fixed.root");
    chain1.Add("Tree_1073_fixed.root");
    chain1.Add("Tree_1074_fixed.root");
    chain1.Add("Tree_1075_fixed.root");
    
    TChain chain2("t1"); //Paddles-out data chain
    chain2.Add("Tree_1067_fixed.root");

    const Int_t knumsamples = 4096;
    const Int_t post_trig = 1024;
    const Int_t trig_pt = 3034;
    const Int_t dsamples = 10;
    const Int_t upper_limit = trig_pt - dsamples;
    const Int_t lower_limit = trig_pt + dsamples;

    //Paddles-in variables
    Float_t chain1_ch1[knumsamples];
    Float_t chain1_ch2[knumsamples];
    Float_t chain1_min_ch2;
    Float_t chain1_min_ch2_sp;

    std::vector<Int_t> chain1_first_below_indices;
    Long64_t chain1_nentries = chain1.GetEntries();

    chain1.SetBranchAddress("ch1", chain1_ch1);
    chain1.SetBranchAddress("ch2", chain1_ch2);

    //Paddles-out variables
    Float_t chain2_ch1[knumsamples];
    Float_t chain2_ch2[knumsamples];
    Float_t chain2_min_ch2;
    Float_t chain2_min_ch2_sp;

    std::vector<Int_t> chain2_first_below_indices;
    Long64_t chain2_nentries = chain2.GetEntries();

    chain2.SetBranchAddress("ch1", chain2_ch1);
    chain2.SetBranchAddress("ch2", chain2_ch2);

    for (Long64_t i = 0; i < chain1_nentries; i++) {
        chain1.GetEntry(i);
        chain1_min_ch2_sp = std::min_element(chain1_ch2 + upper_limit, chain1_ch2 + lower_limit) - chain1_ch2;
        chain1_min_ch2 = *std::min_element(chain1_ch2 + upper_limit, chain1_ch2 + lower_limit);
        chain1_first_below_indices.push_back(chain1_min_ch2_sp);
    }

    for (Long64_t i = 0; i < chain2_nentries; i++) {
    chain2.GetEntry(i);
    chain2_min_ch2_sp = std::min_element(chain2_ch2 + upper_limit, chain2_ch2 + lower_limit) - chain2_ch2;
    chain2_min_ch2 = *std::min_element(chain2_ch2 + upper_limit, chain2_ch2 + lower_limit);
    chain2_first_below_indices.push_back(chain2_min_ch2_sp);
}

    TH1I *hist_idx1 = new TH1I("Paddles-in", "Sample index of the ADC min; Sample idx; Count", 30, 3020, 3050);

    for (auto idx : chain1_first_below_indices) {
        if (idx >= 0) hist_idx1->Fill(idx);
    }

    TH1I *hist_idx2 = new TH1I("Paddles-out", "Sample index variation of the ADC min; Sample idx; Count", 30, 3020, 3050);

    for (auto idx : chain2_first_below_indices) {
        if (idx >= 0) hist_idx2->Fill(idx);
    }

    TCanvas *c = new TCanvas("c", "Canvas", 800, 600);
    TLatex *latex = new TLatex();
    gStyle->SetOptFit(1111);

    hist_idx1->GetXaxis()->CenterTitle();
    hist_idx1->GetYaxis()->CenterTitle();
    hist_idx1->SetLineColor(kRed);
    hist_idx1->Draw();
    //hist_idx1->Fit("gaus");

    hist_idx2->SetLineColor(kBlue);
    hist_idx2->Draw("sames");

    latex->SetTextFont(42);
    latex->SetTextSize(0.03);
    latex->SetTextAlign(13);
    latex->DrawLatexNDC(0.15, 0.85, "Combined Sample variation");

    gPad->Update();
	TPaveStats *stat1 = (TPaveStats*)hist_idx1->FindObject("stats");
	stat1->SetX1NDC(0.75);
	stat1->SetY1NDC(0.7);
	stat1->SetX2NDC(0.9);
	stat1->SetY2NDC(0.9);
    stat1->SetTextColor(kRed);
	stat1->Draw();

    TPaveStats *stat2 = (TPaveStats*)hist_idx2->FindObject("stats");
	stat2->SetX1NDC(0.6);
	stat2->SetY1NDC(0.7);
	stat2->SetX2NDC(0.75);
	stat2->SetY2NDC(0.9);
    stat2->SetTextColor(kBlue);
	stat2->Draw();
	gPad->Modified();
	gPad->Update();
 
    //c->SaveAs("MinSampleVariation_Combined.png");
}
 