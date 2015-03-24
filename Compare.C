gROOT -> Reset();
//#include <iostream.h>
//#include <fstream.h>
//#include <iomanip.h>
//#include <stdlib.h>
//#include <math.h>
//#include <stdio.h>
//#include <TString.h>
//#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>
Compare()
{

char filename1[100] ="correction_pmt_total_maxbin_remove_bad.txt";
char filename2[100] ="/home/cchsu/analysis/tetra/data/pmt_measurement_summary/before_cali/pmt_total_maxbin_remove_bad.txt";
gSystem->Exec(Form("wc -l  %s >> temp", filename1));
gSystem->Exec("gawk '{print $1}' temp > temp1");
ifstream infile20("temp1", ios::in);
int lineN[1];
for (Int_t i = 0; i < 1; i++)
{
        infile20 >> lineN[i];
                }
infile20.close();
const int number_data_point1 = lineN[0];
gSystem->Exec("rm -rf temp*");
cout << " number_data_point1: "  <<  number_data_point1 <<endl;gSystem->Exec(Form("wc -l  %s >> temp", filename2));
gSystem->Exec("gawk '{print $1}' temp > temp1");
ifstream infile21("temp1", ios::in);
int lineN[1];
for (Int_t i = 0; i < 1; i++)
{
        infile21 >> lineN[i];
                }
infile21.close();
const int number_data_point2 = lineN[0];
gSystem->Exec("rm -rf temp*");
cout << " number_data_point2: "  <<  number_data_point2 <<endl;
     TH1F *flux1 = new TH1F("flux1","511keV Peak",50,0.,4);
        TH1F *flux2 = new TH1F("flux2","511keV Peak",50,0.,4);

 double  a1[number_data_point1],b1[number_data_point1];
 double  a1_err[number_data_point1], b1_err[number_data_point1];
 double  c1[number_data_point1], c1_err[number_data_point1];
 double  d1[number_data_point1], d1_err[number_data_point1];
 double  e1[number_data_point1], e1_err[number_data_point1];
 double  f1[number_data_point1], f1_err[number_data_point1];
 double  g1[number_data_point1], g1_err[number_data_point1];
 double  a2[number_data_point2], b2[number_data_point2];
 double  c2[number_data_point2];
ifstream infile1(filename1, ios::in);
 for (Int_t i = 0; i < number_data_point1; i++)
        {
                infile1 >> a1[i] >> b1[i] >>c1[i];
                flux1->Fill(c1[i]);
        }
        infile1.close();

ifstream infile2(filename2, ios::in);
 for (Int_t i = 0; i < number_data_point2; i++)
        {
                infile2 >> a2[i] >> b2[i] >>c2[i];
                flux2->Fill(c2[i]);
        }
        infile2.close();
 c100 = new TCanvas("c1","X-ray vs Gamma-ray ",800,800);
    c100->SetFillColor(10);
 //   c100->SetGrid();
    c100->GetFrame()->SetFillColor(21);
    c100->GetFrame()->SetBorderSize(12);
    gStyle->SetPalette(1,0); // Recommended options when drawing legos
    gStyle->SetOptStat(0000);   // So that statistic information is not printed
    gStyle->SetFrameFillColor(10);
    gStyle -> SetPadLeftMargin (0.15);
    gStyle -> SetPadTopMargin (0.05);
    gStyle -> SetPadBottomMargin (0.15);
 c100->cd();
  hpx = new TH2F("hpx","",40,0.,4.,35,0.,35.);
  hpx->SetStats(kFALSE);
  hpx->SetTitle("PMT Measurement with Na22: total 259(exclude bad) tubes");
  hpx->GetXaxis()->SetTitle("511keV Peak (kChannel)");
//  hpx->GetYaxis()->SetTitle("511keV Width (kChannel)");
  hpx->GetYaxis()->SetTitleOffset(1.3);
  hpx->GetXaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetTitleSize(0.035);
  hpx->GetXaxis()->SetTitleSize(0.035);
  hpx->Draw();
flux1->SetLineColor(1);
        flux1->SetLineWidth(4);
        flux1->SetMarkerColor(1);
        flux1->SetMarkerStyle(20);
        flux1->SetMarkerSize(1.2);
        flux1->Draw("same");

         flux2->SetLineColor(2);
         flux2->SetLineWidth(4);
         flux2->SetLineStyle(5);
        flux2->SetMarkerColor(2);
        flux2->SetMarkerStyle(20);
        flux2->SetMarkerSize(1.2);
        flux2->Draw("same");

        cout << "number of tubes" << flux1->Integral(17,30) <<endl;
        cout << " ==================== " <<endl;
  leg = new TLegend(0.65,0.65,0.9,0.8);
        leg->AddEntry(flux1,"After Correction","lep");
        leg->AddEntry(flux2,"Before Correction","lep");
        leg->Draw();

        gStyle->SetOptFit(1111);
        TF1 *p1 = new TF1("p1","gaus",0.1,0.7);
        p1->SetLineColor(6);
        p1->SetLineWidth(2);
        cout << "++++++++++++++++++++++++++++++++++++++++++++ "<< endl;

        }


