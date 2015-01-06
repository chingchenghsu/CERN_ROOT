gROOT -> Reset();
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>


Analysis()
{

char filename1[100] ="crystal_data_Am_Na.txt";
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

        TH1F *flux1 = new TH1F("flux1","flux his",100,0.,1500);
        TH1F *flux2 = new TH1F("flux2","flux his 2",100,0.,1.);
        TH1F *flux3 = new TH1F("flux3","flux his 3",400,0.,4.1);
        TH2F *adc = new TH2F("adc","adc his",200,0.,4000.,200,0.,4000);


 double  a1[number_data_point1],b1[number_data_point1];
 double  a1_err[number_data_point1], b1_err[number_data_point1];
 double  c1[number_data_point1], c1_err[number_data_point1];
 double  d1[number_data_point1], d1_err[number_data_point1];
 double  e1[number_data_point1], e1_err[number_data_point1];
 double  f1[number_data_point1], f1_err[number_data_point1];
 double  g1[number_data_point1], g1_err[number_data_point1];
 double  h1[number_data_point1], h1_err[number_data_point1];
ifstream infile1(filename1, ios::in);
 for (Int_t i = 0; i < number_data_point1; i++)
        {
        infile1 >> a1[i] >> b1[i] >>c1[i]>>d1[i] >>e1[i]>>f1[i]>>g1[i] >> h1[i];
                a1[i] = a1[i]/1000.;
                f1[i] = f1[i]/1000.;
                g1_err[i] = 0.;
                a1_err[i]=0.;
                f1_err[i]=0.;
                flux1->Fill(a1[i]);
        }
        infile1.close();

    c100 = new TCanvas("c1","X-ray vs Gamma-ray ",1200,800);
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
  c100->Divide(3,2);
 c100->cd(1);
  hpx = new TH2F("hpx","",150,0.,150,10,0.,10.);
  hpx->SetStats(kFALSE);
  hpx->SetTitle("");
  hpx->GetXaxis()->SetTitle("Number of Events within 5mins x1000");
  hpx->GetYaxis()->SetTitle("Events");
  hpx->GetYaxis()->SetTitleOffset(1.6);
  hpx->GetXaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetLabelSize(0.035);
  hpx->GetYaxis()->SetTitleSize(0.035);
  hpx->GetXaxis()->SetTitleSize(0.035);
  hpx->Draw();
         flux1->SetLineColor(1);
         flux1->SetLineWidth(2);
        flux1->SetMarkerColor(1);
        flux1->SetMarkerStyle(20);
        flux1->SetMarkerSize(1.2);
        flux1->Draw("same");
 gStyle->SetOptFit(1111);
        TF1 *p1 = new TF1("p1","gaus",0.1,0.7);
        p1->SetLineColor(6);
        p1->SetLineWidth(2);
   cout << "++++++++++++++++++++++++++++++++++++++++++++ "<< endl;

        c100->cd(2);
        hpx2 = new TH2F("hpx2","",150,0.,150,10,0.,1.);
        hpx2->SetStats(kFALSE);
        hpx2->SetTitle("");
        hpx2->GetXaxis()->SetTitle("Number of Events within 5mins x1000");
        hpx2->GetYaxis()->SetTitle("511keV Peak kChannel");
        hpx2->GetYaxis()->SetTitleOffset(1.6);
        hpx2->GetXaxis()->SetLabelSize(0.035);
        hpx2->GetYaxis()->SetLabelSize(0.035);
        hpx2->GetYaxis()->SetTitleSize(0.035);
        hpx2->GetXaxis()->SetTitleSize(0.035);
        hpx2->Draw();
        gr1 = new TGraphErrors(number_data_point1,a1,b1, a1_err,c1);
        gr1->SetLineColor(1);
        gr1->SetLineWidth(2);
        gr1->SetMarkerColor(1);
        gr1->SetMarkerStyle(20);
        gr1->SetMarkerSize(1.);
        gr1->Draw("psame");

 c100->cd(3);
        hpx3 = new TH2F("hpx3","",150,0.,150,30,0.,3.);
        hpx3->SetStats(kFALSE);
        hpx3->SetTitle("");
        hpx3->GetXaxis()->SetTitle("Number of Events within 5mins x1000");
        hpx3->GetYaxis()->SetTitle("1274keV Peak kChannel");
        hpx3->GetYaxis()->SetTitleOffset(1.6);
        hpx3->GetXaxis()->SetLabelSize(0.035);
        hpx3->GetYaxis()->SetLabelSize(0.035);
        hpx3->GetYaxis()->SetTitleSize(0.035);
        hpx3->GetXaxis()->SetTitleSize(0.035);
        hpx3->Draw();
        gr2 = new TGraphErrors(number_data_point1,a1,d1, a1_err,e1);
        gr2->SetLineColor(1);
        gr2->SetLineWidth(2);
        gr2->SetMarkerColor(1);
        gr2->SetMarkerStyle(20);
        gr2->SetMarkerSize(1.);
        gr2->Draw("psame");
  c100->cd(4);
        hpx4 = new TH2F("hpx4","",10,0.,1.,30,0.,3.);
        hpx4->SetStats(kFALSE);
        hpx4->SetTitle("");
        hpx4->GetXaxis()->SetTitle("511keV Peak kChannel");
        hpx4->GetYaxis()->SetTitle("1274keV Peak kChannel");
        hpx4->GetYaxis()->SetTitleOffset(1.6);
        hpx4->GetXaxis()->SetLabelSize(0.035);
        hpx4->GetYaxis()->SetLabelSize(0.035);
        hpx4->GetYaxis()->SetTitleSize(0.035);
        hpx4->GetXaxis()->SetTitleSize(0.035);
        hpx4->Draw();
        gr3 = new TGraphErrors(number_data_point1,b1,d1, c1,e1);
        gr3->SetLineColor(1);
        gr3->SetLineWidth(2);
        gr3->SetMarkerColor(1);
        gr3->SetMarkerStyle(20);
        gr3->SetMarkerSize(1.);
        gr3->Draw("psame");
 c100->cd(5);
        hpx5 = new TH2F("hpx5","",150,0.,150.,30,0.,3.);
        hpx5->SetStats(kFALSE);
        hpx5->SetTitle("");
        hpx5->GetXaxis()->SetTitle("Number of Events within 5mins x1000");
        hpx5->GetYaxis()->SetTitle("channel/keV");
        hpx5->GetYaxis()->SetTitleOffset(1.6);
        hpx5->GetXaxis()->SetLabelSize(0.035);
        hpx5->GetYaxis()->SetLabelSize(0.035);
        hpx5->GetYaxis()->SetTitleSize(0.035);
        hpx5->GetXaxis()->SetTitleSize(0.035);
        hpx5->Draw();
        gr4 = new TGraphErrors(number_data_point1,a1,f1, a1_err,f1_err);
        gr4->SetLineColor(1);
        gr4->SetLineWidth(2);
        gr4->SetMarkerColor(1);
        gr4->SetMarkerStyle(20);
        gr4->SetMarkerSize(1.);
        gr4->Draw("psame");
 c100->cd(6);
      //  hpx6 = new TH2F("hpx6","",100,0.,1.,10,0.,10.);
        hpx6 = new TH2F("hpx6","",150,0.,150.,40,0.,40.);
        hpx6->SetStats(kFALSE);
        hpx6->SetTitle("");
        hpx6->GetYaxis()->SetTitle("Number of Events within 10mins x1000 (Am)");
        hpx6->GetXaxis()->SetTitle("Number of Events within 5mins x1000 (Na)");
        hpx6->GetYaxis()->SetTitleOffset(1.6);
        hpx6->GetXaxis()->SetLabelSize(0.035);
        hpx6->GetYaxis()->SetLabelSize(0.035);
        hpx6->GetYaxis()->SetTitleSize(0.035);
        hpx6->GetXaxis()->SetTitleSize(0.035);
        hpx6->Draw();

        gr5 = new TGraphErrors(number_data_point1,a1,f1, a1_err,f1_err);
        gr5->SetLineColor(1);
        gr5->SetLineWidth(2);
        gr5->SetMarkerColor(1);
        gr5->SetMarkerStyle(20);
        gr5->SetMarkerSize(1.);
        gr5->Draw("psame");
        flux2->SetLineColor(1);
        flux2->SetLineWidth(2);
        flux2->SetMarkerColor(1);
        flux2->SetMarkerStyle(20);
        flux2->SetMarkerSize(1.2);
    //    flux2->Draw("same");
        }
