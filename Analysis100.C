gROOT -> Reset();
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>
Analysis100(int setnum)
{
     const int num_files=15;
     string *infile[num_files] = {"chn1.adc","chn2.adc","chn3.adc","chn4.adc","chn5.adc","chn6.adc","chn7.adc","chn8.adc","chn9.adc","chn10.adc","chn11.adc","chn12.adc","chn13.adc","chn14.adc", "chn15.adc"};
        string * mychar[num_files]={"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O"};
        std::ofstream outfile("set_maxbin.txt", std::ofstream::out);
 TH1F *flux1[num_files];
   TH2F *hpx[num_files];
    c100 = new TCanvas("c1","",800,800);
    c100->SetFillColor(10);
    c100->GetFrame()->SetFillColor(21);
    c100->GetFrame()->SetBorderSize(12);
    gStyle->SetPalette(1,0); // Recommended options when drawing legos
    gStyle->SetOptStat(0000);   // So that statistic information is not printed
    gStyle->SetFrameFillColor(10);
    gStyle -> SetPadLeftMargin (0.15);
    gStyle -> SetPadTopMargin (0.05);
    gStyle -> SetPadBottomMargin (0.15);
    c100->Divide(4,4);

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
        int kk=ii+1;
  c100->cd(kk);
  hpx[ii] = new TH2F(Form("hpx%d",ii),"",400,0.,4.,20,1,2000.);
  hpx[ii]->SetStats(kFALSE);
  hpx[ii]->SetTitle(Form("Set 1 PMT Nr%d",ii));
  hpx[ii]->GetXaxis()->SetTitle("ADC kChannel ");
  hpx[ii]->GetYaxis()->SetTitle("Events");
  hpx[ii]->GetYaxis()->SetTitleOffset(1.6);
  hpx[ii]->GetXaxis()->SetLabelSize(0.035);
  hpx[ii]->GetYaxis()->SetLabelSize(0.035);
  hpx[ii]->GetYaxis()->SetTitleSize(0.035);
  hpx[ii]->GetXaxis()->SetTitleSize(0.035);
  hpx[ii]->Draw();

  flux1[ii] = new TH1F(Form("flux%d",ii),"flux his",400,0.,4.);
ifstream infile1(Form("%s",infile[ii]), ios::in);

 for (int i = 0; i < nu[ii]; ++i)
        {
                double a1;
                infile1 >> a1;
                a1  = a1 /1000.;
                flux1[ii]->Fill(a1);
        }
        infile1.close();
//      cout << " I am here " << ii <<endl;
        int jj=0;
            if (ii < 9)
                jj = ii+1;  // jj =0 - 8  
            else
                jj =ii+28;

        flux1[ii]->SetLineColor((jj));
        flux1[ii]->SetLineWidth(2);
        flux1[ii]->SetMarkerColor((jj));
        flux1[ii]->SetMarkerStyle((20+ii));
        flux1[ii]->SetMarkerSize(1.);
  double area = flux1[ii]->Integral();
        cout << "area under "<<ii <<"  is "<<area <<endl;
        flux1[ii]->Draw("lpsame");
        TH1F *hnew = (TH1F*)flux1[ii]->Clone("hnew");

if (ii==0 || ii==1)
        hnew->GetXaxis()->SetRange(50,300);
else
        hnew->GetXaxis()->SetRange(40,300);

         int locmax1,locmax2,locmax3, locmax4,locmax5,locmaxy,locmaxz;
        hnew->GetMaximumBin(locmax1,locmax2,locmax3);
        cout << locmax1 <<endl;
        hnew->SetBinContent(locmax1,0);
        hnew->GetMaximumBin(locmax2,locmaxy,locmaxz);
        cout << locmax2 <<endl;
        hnew->SetBinContent(locmax2,0);
        hnew->GetMaximumBin(locmax3,locmaxy,locmaxz);
        cout << locmax3 <<endl;
        hnew->SetBinContent(locmax3,0);
        hnew->GetMaximumBin(locmax4,locmaxy,locmaxz);
        cout << locmax4 <<endl;
        hnew->SetBinContent(locmax4,0);
   hnew->GetMaximumBin(locmax5,locmaxy,locmaxz);
        cout << locmax5 <<endl;
        hnew->SetBinContent(locmax5,0);


        flux1[ii]->GetXaxis()->SetRange(0,400);
        flux1[ii]->Draw("lpsame");
        double peak_value = (locmax1+locmax2+locmax3+locmax4+locmax5) *4./400./5.;

if (peak_value > 0.4 ) {
  outfile << setnum <<"   " << (ii+1) << "  "<<  peak_value <<endl;
        }

        t22 = new TLatex(1.,1500,Form("peak: %3.3f", peak_value));
        t22->SetTextSize(0.06);
        t22->SetTextColor(1);
        t22->Draw();
       cout << "++++++++++++++++++++++++++++++++++++++++++++ "<< endl;
}  // end of the file number loop 
             outfile.close();
        }


