gROOT -> Reset();
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>


//PlotQE(char* filename1)
Peak(char *filename1, char *filename2, char *filename3, char *filename4, char *filename5)
{

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
cout << " number_data_point1: "  <<  number_data_point1 <<endl;
gSystem->Exec(Form("wc -l  %s >> temp", filename2));
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

gSystem->Exec(Form("wc -l  %s >> temp", filename3));
gSystem->Exec("gawk '{print $1}' temp > temp1");
ifstream infile22("temp1", ios::in);
int lineN[1];
for (Int_t i = 0; i < 1; i++)
{
        infile22 >> lineN[i];
                }
infile22.close();
const int number_data_point3 = lineN[0];
gSystem->Exec("rm -rf temp*");
cout << " number_data_point3: "  <<  number_data_point3 <<endl;
gSystem->Exec(Form("wc -l  %s >> temp", filename4));
gSystem->Exec("gawk '{print $1}' temp > temp1");
ifstream infile32("temp1", ios::in);
int lineN[1];
for (Int_t i = 0; i < 1; i++)
{
        infile32 >> lineN[i];
                }
infile32.close();
const int number_data_point4 = lineN[0];
gSystem->Exec("rm -rf temp*");
cout << " number_data_point4: "  <<  number_data_point4 <<endl;

gSystem->Exec(Form("wc -l  %s >> temp", filename5));
gSystem->Exec("gawk '{print $1}' temp > temp1");
ifstream infile42("temp1", ios::in);
int lineN[1];
for (Int_t i = 0; i < 1; i++)
{
        infile42 >> lineN[i];
                }
infile42.close();
const int number_data_point5 = lineN[0];
gSystem->Exec("rm -rf temp*");
cout << " number_data_point5: "  <<  number_data_point5 <<endl;
  TH1F *flux1 = new TH1F("flux1","flux his",400,0.,4.1);
        TH1F *flux2 = new TH1F("flux2","flux his 2",400,0.,4.1);
        TH1F *flux3 = new TH1F("flux3","flux his 3",400,0.,4.1);
        TH1F *flux4 = new TH1F("flux4","flux his 4",400,0.,4.1);
        TH1F *flux5 = new TH1F("flux5","flux his 5",400,0.,4.1);
        TH2F *adc = new TH2F("adc","adc his",200,0.,4000.,200,0.,4000);


 double  a1[number_data_point1],b1[number_data_point1];
 double  a1_err[number_data_point1], b1_err[number_data_point1];
 double  c1[number_data_point1], c1_err[number_data_point1];

 double  a2[number_data_point2],a2_err[number_data_point2];
 double  b2[number_data_point2],b2_err[number_data_point2];
 double  c2[number_data_point2],c2_err[number_data_point2];

 double  a3[number_data_point3],a3_err[number_data_point3];
 double  b3[number_data_point3],b3_err[number_data_point3];
 double  c3[number_data_point3],c3_err[number_data_point3];

 double  a4[number_data_point4],a4_err[number_data_point4];
 double  b4[number_data_point4],b4_err[number_data_point4];
 double  c4[number_data_point4],c4_err[number_data_point4];

 double  a5[number_data_point5],a5_err[number_data_point5];
 double  b5[number_data_point5],b5_err[number_data_point5];
 double  c5[number_data_point5],c5_err[number_data_point5];
//-------------------------------------------------

 ifstream infile1(filename1, ios::in);
 for (Int_t i = 0; i < number_data_point1; i++)
        {
                infile1 >> c1[i] >> a1[i] >> b1[i];
                a1_err[i] =0.;
                b1_err[i] =0.;
                c1_err[i] =0.;
                a1[i]  = a1[i] *1000.;
                b1[i]  = b1[i] *1000.;
        }
        infile1.close();

 ifstream infile2(filename2, ios::in);
        for (Int_t i = 0; i < number_data_point2; i++)

        {
                infile2 >> c2[i]>> a2[i] >> b2[i];
                a2_err[i] =0.;
                b2_err[i] =0.;
                c2_err[i] =0.;
                a2[i]  = a2[i] *1000.;
                b2[i]  = b2[i] *1000.;
        }
        infile2.close();

 ifstream infile3(filename3, ios::in);
        for (Int_t i = 0; i < number_data_point3; i++)

        {
                infile3 >> c3[i] >> a3[i] >> b3[i];
                a3_err[i] =0.;
                b3_err[i] =0.;
                c3_err[i] =0.;
                a3[i]  = a3[i]*1000. ;
                b3[i]  = b3[i]*1000. ;
        }
        infile3.close();

 ifstream infile4(filename4, ios::in);
        for (Int_t i = 0; i < number_data_point4; i++)
        {
                infile4 >> c4[i] >> a4[i] >> b4[i];
                a4_err[i] =0.;
                b4_err[i] =0.;
                a4[i]  = a4[i]*1000. ;
                b4[i]  = b4[i]*1000. ;
        }
        infile4.close();
ifstream infile5(filename5, ios::in);
        for (Int_t i = 0; i < number_data_point5; i++)
        {
                infile5 >> c5[i] >> a5[i] >> b5[i];
                a5_err[i] =0.;
                b5_err[i] =0.;
                a5[i]  = a5[i] *1000.;
                b5[i]  = b5[i] *1000.;
        }
        infile5.close();


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
  hpx = new TH2F("hpx","",600,0.,3000.,420,0.,4200);
  hpx->SetStats(kFALSE);
  hpx->SetTitle("Peak value of the Spectra PMT pairs");
  hpx->GetXaxis()->SetTitle("E_{#gamma} keV");
  hpx->GetYaxis()->SetTitle("Peak ADC Channels");
  hpx->GetYaxis()->SetTitleOffset(1.6);
  hpx->GetXaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetTitleSize(0.035);
  hpx->GetXaxis()->SetTitleSize(0.035);
  hpx->Draw();
         gr1 = new TGraphErrors(number_data_point1,c1,a1, c1_err,b1);
         gr2 = new TGraphErrors(number_data_point2,c2,a2, c2_err,b2);
         gr3 = new TGraphErrors(number_data_point3,c3,a3, c3_err,b3);
         gr4 = new TGraphErrors(number_data_point4,c4,a4, c4_err,b4);
         gr5 = new TGraphErrors(number_data_point5,c5,a5, c5_err,b5);

    gr1->SetLineColor(1);
    gr1->SetLineWidth(2);
    gr1->SetMarkerColor(1);
    gr1->SetMarkerStyle(20);
    gr1->SetMarkerSize(1.2);
    gr1->Draw("samep");
 gr2->SetLineColor(2);
    gr2->SetLineWidth(2);
    gr2->SetMarkerColor(2);
    gr2->SetMarkerStyle(21);
    gr2->SetMarkerSize(1.2);
    gr2->Draw("samep");

    gr3->SetLineColor(3);
    gr3->SetLineWidth(2);
    gr3->SetMarkerColor(3);
    gr3->SetMarkerStyle(24);
    gr3->SetMarkerSize(1.2);
    gr3->Draw("samep");

    gr4->SetLineColor(4);
    gr4->SetLineWidth(2);
    gr4->SetMarkerColor(4);
    gr4->SetMarkerStyle(25);
    gr4->SetMarkerSize(1.2);
    gr4->Draw("samep");

    gr5->SetLineColor(6);
    gr5->SetLineWidth(2);
    gr5->SetMarkerColor(6);
    gr5->SetMarkerStyle(28);
    gr5->SetMarkerSize(1.2);
    gr5->Draw("samep");

   leg = new TLegend(0.75,0.65,0.9,0.8);
        leg->AddEntry(flux1,"^{133}Ba","lep");
        leg->AddEntry(flux2,"^{137}Cs","lep");
        leg->AddEntry(flux3,"^{22}Na","lep");
        leg->AddEntry(flux4,"^{243}Am","lep");
        leg->AddEntry(flux5,"Thoriated Tunsgten","lep");
//      leg->Draw();

//      gStyle->SetOptFit(1111);
        TF1 *p1 = new TF1("p1","[0]+[1]*x",0.,2700);
        p1->SetLineColor(1);
        p1->SetLineWidth(3);
        p1->SetLineStyle(2);
        gr1->Fit("p1","RO+");
        cout <<  p1->GetParameter(1) << "  " << p1->GetParameter(2) << endl;
}
