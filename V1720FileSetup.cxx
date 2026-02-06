#include "V1720FileSetup.h"
#include "Rtypes.h"

#include <RtypesCore.h>
#include <TTree.h>
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <TROOT.h>
#include <TFile.h>
#include <TChain.h>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

V1720FileSetup::V1720FileSetup(const string& fName, const string& T) :
                        m_File(TFile::Open(fName.c_str(), "READ")) 
{
    if (!m_File || m_File->IsZombie()) {
        throw runtime_error("File Open Unsuccessfull with: " + fName );
    }
    m_Tree = m_File->Get<TTree>(T.c_str());
    if (!m_Tree) {
        throw runtime_error("No Tree: " + T);
    }

    cout << "Tree setup successfull!\n";
}

V1720FileSetup::V1720FileSetup(const vector<string>& fList, const string& T) :
                        m_Chain(make_unique<TChain>(T.c_str()))
{
    if (fList.empty()) {
        throw runtime_error("File List Empty!");
    }
    if (m_Chain->GetEntries() == 0) {
        throw runtime_error("The Chain is Empty!");
    }

    for (const std::string& file : fList) {
        m_Chain->Add(file.c_str());
    }

    m_Tree = m_Chain.get();

    cout << "Tree setup successfull!\n";
}

void V1720FileSetup::setupBranch(const string& branch, const string& spBranch) 
{
    if (!m_Tree) {
        throw runtime_error("Tree not setup!");
    }

    auto& data = m_allSamples[branch];
    data.branchName = branch;
    data.samples.clear();

    if (!branch.c_str() || !spBranch.c_str()) {
        throw runtime_error("Error in Branch Setup!");
    }

    m_Tree->SetBranchAddress(spBranch.c_str(), &m_numSamples);
    m_Tree->SetBranchAddress(branch.c_str(), m_Samples);

    Int_t nEntries = m_Tree->GetEntries();
    data.samples.reserve(nEntries);
    for (Long64_t i = 0; i < nEntries; i++) {
        m_Tree->GetEntry(i);

        if (!m_Samples[i]) {
            data.samples.emplace_back();
            continue;
        }
        data.samples.emplace_back(m_Samples, m_Samples + m_numSamples);
    }

    cout << "Branch " << branch << " setup successfull!\n";
}

void V1720FileSetup::processMinSamples(const string& branch, const Int_t& trigPoint, const Int_t& dSamples)
{
    m_trigPoint = trigPoint;
    m_dSamples = dSamples;
    m_lowerLimit = trigPoint - dSamples;
    m_upperLimit = trigPoint + dSamples;

    auto& branchData = m_allSamples.at(branch);
    branchData.minSamples.clear();
    branchData.minSampleidxs.clear();

    for (size_t evt = 0; evt < branchData.samples.size(); evt++) {
        auto& waveform = branchData.samples[evt];

        if (waveform.empty()) {
            branchData.minSamples.push_back(0.0f);
            branchData.minSampleidxs.push_back(0);
            continue;
        }

        auto beginIt = waveform.begin() + m_lowerLimit;
        auto endIt = waveform.begin() + m_upperLimit;
        auto idx = min_element(beginIt, endIt) - waveform.begin();
        auto val = *min_element(beginIt, endIt);

        branchData.minSamples.push_back(val);
        branchData.minSampleidxs.push_back(idx);
    }
}

void V1720FileSetup::printAllSamples(const string& branch, const Int_t& nEvents
                                    , const Int_t& startSamp, const Int_t& endSamp) 
{
    auto& samples = m_allSamples.at(branch).samples;

    for (size_t i = 0; i < nEvents; i++) {
        for (size_t j = startSamp; j < endSamp; j++) {
            cout << "Entry " << i + 1 << " data point " << j + 1 << " = " << samples[i][j] << endl;
        }
        cout << "-----------------------------------\n";
    }
    cout << "==================================\n\n";
}

void V1720FileSetup::printMinSamples(const string& branch, const Int_t& nEvents)
{
    auto& samples = m_allSamples.at(branch).minSamples;

    for (size_t i = 0; i < nEvents; i++) {
        cout << "Minimum sample for event " << i + 1 << " = " << samples[i] << endl;
    }
    cout << "==================================\n\n";
}

void V1720FileSetup::printMinSampleidxs(const string& branch, const Int_t& nEvents)
{
    auto& samples = m_allSamples.at(branch).minSampleidxs;

    for (size_t i = 0; i < nEvents; i++) {
        cout << "Minimum sample for event " << i + 1 << " = " << samples[i] << endl;
    }
    cout << "==================================\n\n";
}

ClassImp(V1720FileSetup)