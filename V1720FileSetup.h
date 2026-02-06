#ifndef V1720FILESETUP_H
#define V1720FILESETUP_H

#include "Rtypes.h"
#include <RtypesCore.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>
#include <memory>
#include <unordered_map>
#include <vector>

// Helper struct for per-branch data
struct BranchData {
    std::string branchName;
    std::vector<std::vector<Float_t>> samples; // All samples

    std::vector<Float_t> minSamples; // Minimum samples per-event
    std::vector<Float_t> minSampleidxs; // Sample indeces for minimum values
};

class V1720FileSetup {
public:
    // Constructor for single TFile
    V1720FileSetup(const std::string& fName, const std::string& T);
    // Constructor for multiple root files (TChain)
    V1720FileSetup(const std::vector<std::string>& fList, const std::string& T);
    ~V1720FileSetup() = default;

    void setupBranch(const std::string& branch, const std::string& spBranch);
    std::vector<std::vector<Float_t>> getAllSamples(const std::string& branch) const 
        { return m_allSamples.at(branch).samples; }

    //______________ Min sample processing __________________________________________________________
    void processMinSamples(const std::string& branch
                                    , const Int_t& trigPoint, const Int_t& dSamples);
    std::vector<Float_t> getMinSamples(const std::string& branch) const
        { return m_allSamples.at(branch).minSamples; }
    std::vector<Float_t> getMinSampleIdxs(const std::string& branch) const
        { return m_allSamples.at(branch).minSampleidxs; }
    
    //______________ Printing functions _______________________________________________________________
    void printAllSamples(const std::string& branch, const Int_t& nEvents
                                    , const Int_t& startSamp, const Int_t& endSamp);
    void printMinSamples(const std::string& branch, const Int_t& nEvents);
    void printMinSampleidxs(const std::string& branch, const Int_t& nEvents);

private:
    std::unique_ptr<TFile> m_File;
    std::unique_ptr<TChain> m_Chain;
    TTree* m_Tree {nullptr};

    // ADC parameters
	Int_t m_trigPoint = 0;
	Int_t m_dSamples = 0;
	Int_t m_lowerLimit =  0;
	Int_t m_upperLimit = 0;

    Int_t m_numSamples;
    Float_t m_Samples[5000];
    std::unordered_map<std::string, BranchData> m_allSamples;
    

    ClassDef(V1720FileSetup, 1)
};

#endif // V1720FILESETUP_H