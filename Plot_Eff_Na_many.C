gROOT -> Reset();
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>


Plot_Eff_Na_many()
{
     const int num_files=16;
     string *infile[num_files] = {"A-BGO_B68+B67-22Na-HV1200-5mins.adc","B-BGO_B37+No220-22Na-HV1200-5mins.adc","C-BGO_No007+A12-22Na-HV1200-5mins.adc","D-BGO_106+No320-22Na-HV1200-5mins.adc","E-BGO_No267+No274-22Na-HV1200-5mins.adc","F-BGO_No253+No208-22Na-HV1200-5mins.adc","G-BGO_B51+B52-22Na-HV1200-5mins.adc","H-BGO_088+356-22Na-HV1200-5mins.adc","I-BGO_No153+No185-22Na-HV1200-5mins.adc","J-BGO_No203+No301-22Na-HV1200-5mins.adc","K-BGO_No223+134-22Na-HV1200-5mins.adc","L-BGO_A2+A14-22Na-HV1200-5mins.adc","M-BGO_128+346-22Na-HV1200-5mins.adc","N-BGO_064+No243-22Na-HV1200-5mins.adc","O-BGO_No2501+No241-22Na-HV1200-5mins.adc", "P-BGO_117+No184-22Na-HV1200-5mins.adc"};
        string * mychar[num_files]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P"};
  TH1F *flux1[num_files];
    c100 = new TCanvas("c1","X-ray vs Gamma-ray ",800,800);
    c100->SetFillColor(10);
    c100->GetFrame()->SetFillColor(21);
    c100->GetFrame()->SetBorderSize(12);
    gStyle->SetPalette(1,0); // Recommended options when drawing legos
    gStyle->SetOptStat(0000);   // So that statistic information is not printed
    gStyle->SetFrameFillColor(10);
    gStyle -> SetPadLeftMargin (0.15);
    gStyle -> SetPadTopMargin (0.05);
    gStyle -> SetPadBottomMargin (0.15);
  c100->cd();
  hpx = new TH2F("hpx","",400,0.,4.1,1600,1,16000.);
  hpx->SetStats(kFALSE);
  hpx->SetTitle("^{22}Na Spectra: PMT pair F");
  hpx->GetXaxis()->SetTitle("ADC kChannel #sqrt{Ch0*Ch1}");
  hpx->GetYaxis()->SetTitle("Events");
  hpx->GetYaxis()->SetTitleOffset(1.6);
  hpx->GetXaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetLabelSize(0.035);
hpx->Draw();
        leg = new TLegend(0.75,0.65,0.9,0.8);

        for (int ii=0;ii<num_files;ii++) {
        gSystem->Exec(Form(" wc -l %s >> temp", infile[ii]));
        gSystem->Exec("gawk '{print $1}' temp > temp1");
        ifstream infile21("temp1", ios::in);
        int lineN[1];
        int nu[num_files];
        for (Int_t i = 0; i < 1; i++)
        {
                infile21 >> lineN[i];
                }
        infile21.close();
        nu[ii] = lineN[0];
        gSystem->Exec("rm -rf temp*");
        cout << " number_data_point1: "  <<  nu[ii] <<endl;
        } // loop over file 


for (int ii=0;ii<num_files;ii++)
{

flux1[ii] = new TH1F(Form("flux%d",ii),"flux his",400,0.,4.1);

//-------------------------------------------------
 ifstream infile1(Form("%s",infile[ii]), ios::in);


 for (int i = 0; i < nu[ii]; ++i)
        {
                double a1, b1;
                infile1 >> a1>> b1;
                a1  = a1 /1000.;
                b1  = b1[i] /1000.;
                flux1[ii]->Fill(sqrt(a1* b1));
        }
        infile1.close();
        cout << " I am here " << ii <<endl;

                int jj =ii+1;
        if (ii>=10)
                int jj = ii-8;
        flux1[ii]->SetLineColor((jj));
   flux1[ii]->SetLineWidth(2);
        flux1[ii]->SetMarkerColor((jj));
        flux1[ii]->SetMarkerStyle((20+ii));
        flux1[ii]->SetMarkerSize(1.);
//if(ii==1 | ii==2|ii==3|ii==4 | ii==5 | ii==6|ii==7)
if(ii==2 | ii== 9 |ii==10 |ii==11 | ii==12 | ii==13 |ii==14 | ii ==15)
{
        flux1[ii]->Draw("lpsame");

                leg->AddEntry(flux1[ii],Form("BGO %s",mychar[ii]),"lep");
                leg->Draw();
}
}  // end of the file number loop 
