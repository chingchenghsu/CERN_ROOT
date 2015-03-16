gROOT -> Reset();
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio>
#include <TString>
#include <string>
Analysis22()
{
     const int num_files=10;
     string *infile[num_files] = {"china.txt_info.txt","france.txt_info.txt","germany.txt_info.txt","india.txt_info.txt","indonesia.txt_info.txt","japan.txt_info.txt","korea_south.txt_info.txt","taiwan.txt_info.txt","russia.txt_info.txt","usa.txt_info.txt"};
        string * mychar[num_files]={"China","France","Germany","India","Indonesia","Japan","Korea","Taiwan","Russia","USA"};
        //std::ofstream outfile("set12_fitdata.txt", std::ofstream::app);

   TH2F *flux1[num_files];
   TH2F *hpx[num_files];
    c100 = new TCanvas("c1","",1200,800);
    c100->SetFillColor(10);
    c100->GetFrame()->SetFillColor(21);
 gStyle->SetPalette(1,0); // Recommended options when drawing legos
    gStyle->SetOptStat(0000);   // So that statistic information is not printed
    gStyle->SetFrameFillColor(10);
    gStyle -> SetPadLeftMargin (0.15);
    gStyle -> SetPadTopMargin (0.05);
    gStyle -> SetPadBottomMargin (0.15);
    c100->Divide(3,4);

        int nu[num_files];
        for (int ii=0;ii<num_files;ii++) {
        gSystem->Exec(Form(" wc -l %s >> temp", infile[ii]));
        gSystem->Exec("gawk '{print $1}' temp > temp1");
        ifstream infile21("temp1", ios::in);
        int lineN[1];
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
  hpx[ii] = new TH2F(Form("hpx%d",ii),"",2000,0.,2,9000,5.,8.);
  hpx[ii]->SetStats(kFALSE);
  hpx[ii]->SetTitle(Form("Population %s",mychar[ii]));
  hpx[ii]->GetXaxis()->SetTitle("ADC kChannel ");
  hpx[ii]->GetYaxis()->SetTitle("Events");
  hpx[ii]->GetYaxis()->SetTitleOffset(1.6);
  hpx[ii]->GetXaxis()->SetLabelSize(0.035);
  hpx[ii]->GetYaxis()->SetLabelSize(0.035);
  hpx[ii]->GetYaxis()->SetTitleSize(0.035);
 hpx[ii]->GetYaxis()->SetTitleSize(0.035);
  hpx[ii]->GetXaxis()->SetTitleSize(0.035);
  hpx[ii]->Draw();

    flux1[ii] = new TH2F(Form("flux%d",ii),"flux his",2000,0.,2,9000,5.,8.);
//-------------------------------------------------

        ifstream infile1(Form("%s",infile[ii]), ios::in);

 for (int i = 0; i < nu[ii]; ++i)
        {
                double a1,c1;
                string b1;
                infile1 >> a1 >> b1 >> c1;
                cout<< a1 <<endl;
                flux1[ii]->Fill((log10(i+1)),log10(c1));
        }
        infile1.close();
   flux1[ii]->SetLineColor((4));
        flux1[ii]->SetLineWidth(2);
        flux1[ii]->SetMarkerColor((4));
        flux1[ii]->SetMarkerStyle((20));
        flux1[ii]->SetMarkerSize(1.);
        double area = flux1[ii]->Integral();
        cout << "area under "<<ii <<"  is "<<area <<endl;
        flux1[ii]->Draw("lpsame");
        cout << "++++++++++++++++++++++++++++++++++++++++++++ "<< endl;
}  // end of the file number loop 
           //  outfile.close();
        }

