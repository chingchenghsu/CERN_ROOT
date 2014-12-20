#include <iostream>
#include <strstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <TObject.h>
#include <TSystem.h>
#include "TTree.h"
#include "TNtuple.h"
#include "TObject.h"
#include "TProfile.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "math.h"
#include "TF1.h"
#include <vector>
#include <map>
#include "LC_Info.hh"
int main(){
        using namespace std;
        multimap<int,GBM_LC> my_gbm;
//  char filename1[100] ="asm/mrk421_asm_dwell_format7column.txt";
// char filename1[100] ="maxi/mrk421_maxi_1orbit.txt";
// char filename1[100] ="gbm/mrk421_allflux_aftercut_new.txt";
// char filename1[100] ="lat/mrk421_LAT_new.txt";
 char filename1[100] ="bat/bat_orbit_lc.txt";

//   char filename1[100] ="integral_isgri/mrk421_lc_isgri_1orbit.txt";
 const int number_data_point1 =36476; // bat
// const int number_data_point1 =33410;
// const int number_data_point1 =33410;
// const int number_data_point1 = 10487;
// const int number_data_point1 = 11109;
// const int number_data_point1 = 1564; // lat 
 double  mjd1[number_data_point1],mjd2[number_data_point1];
 double  a1[number_data_point1],b1[number_data_point1];
 double  c1[number_data_point1],d1[number_data_point1];
 double  e1[number_data_point1],f1[number_data_point1];
 double  g1[number_data_point1];
 double  a1_err[number_data_point1],b1_err[number_data_point1];
 double  c1_err[number_data_point1],d1_err[number_data_point1];
 double  e1_err[number_data_point1],f1_err[number_data_point1];
 double  g1_err[number_data_point1];
 double  mjd_err[number_data_point1];
      GBM_LC tuple_lc;
// loop over events 
        vector<double>mjd_date_v;
        ifstream infile1(filename1, ios::in);
        for (int i=0;i<number_data_point1;i++)
        {
        infile1 >> mjd1[i]>>a1[i]>>a1_err[i]>>b1[i]>>b1_err[i]>>c1[i]>>c1_err[i]>>d1[i]>>d1_err[i]>>e1[i]>>e1_err[i]>>f1[i]>>f1_err[i]>>g1[i]>>g1_err[i];
        tuple_lc.id = i;
        tuple_lc.mjd_gbm = mjd1[i];
//      if (mjd1[i] > (int(mjd1[i])+0.5))
//              mjd2[i] = int(mjd1[i])+1; 
//      else 
//              mjd2[i] = int(mjd1[i]);
        mjd2[i] = mjd1[i];
        mjd_date_v.push_back(mjd2[i]);
        tuple_lc.a_band = a1[i];
        tuple_lc.b_band = b1[i];
        tuple_lc.c_band = c1[i];
        tuple_lc.d_band = d1[i];
        tuple_lc.e_band = e1[i];
        tuple_lc.f_band = f1[i];
        tuple_lc.g_band = g1[i];
        tuple_lc.a_band_err = a1_err[i];
        tuple_lc.b_band_err = b1_err[i];
        tuple_lc.c_band_err = c1_err[i];
        tuple_lc.d_band_err = d1_err[i];
        tuple_lc.e_band_err = e1_err[i];
        tuple_lc.f_band_err = f1_err[i];
          tuple_lc.g_band_err = g1_err[i];
        my_gbm.insert (pair<int,GBM_LC>(mjd2[i],tuple_lc));
                }

        double start_date = 54690; // the starting day of GBM 
//      double start_date = *std::min_element(mjd_date_v.begin(), mjd_date_v.end());
//      double last_date = *std::max_element(mjd_date_v.begin(), mjd_date_v.end());
        double last_date = 56466;

// start tp loop over each date and calculate the mean of each date .. 

//      const int number_of_files = 14;
//      int date_array[14] = {0,1,2,3,6,13,27,41,55,69,83,111,139,167}; 
        const int number_of_files = 20;
        int date_array[20] = {0,1,2,3,6,13,27,41,55,69,83,111,139,167,251,335,503,671,839,1721};

        for(int kk=0;kk<number_of_files;kk++)
{
        FILE *outfile;
        outfile = fopen(Form("bat_lc_%dday.txt",date_array[kk]+1), "w");
for (int i = int(start_date); i< int(last_date) ; i++) {
//      pair<multimap<int,GBM_LC>::iterator,multimap<int,GBM_LC>::iterator> ret1, ret2;
        int duration_date = date_array[kk];
        int temp_mjd1 = i;
        int temp_mjd2 = i+ duration_date; // here give the different time scale 
        multimap <int, GBM_LC>:: iterator ret1,ret2,p;
     ret1 = my_gbm.lower_bound(temp_mjd1);
        ret2 = my_gbm.upper_bound(temp_mjd2);
//      cout << " ret 1 :" << ret1 <<endl;
        int ct1 = std::distance(ret1, ret2);
        if (ret1 == ret2)
        {
//              cout << " we found nothing!: " << i <<endl;
//              cout << i << " " << ct1  << " 0." <<" "<< "-999." <<" " << "-999." << " " <<" -999." << " " << "-999." << "  " <<" -999." << "  " <<" -999." <<" " <<" -999." <<"  " <<" -999." << " " <<" -999." <<endl; 
                fprintf(outfile,"%d %d %d %d %d %d %d %d %d %d  %d %d\n", i, ct1, 0., -9999, -9999, -9999, -9999, -9999, -9999,-9999,-9999,-9999);

                i = temp_mjd2;
                continue;
        }
        double sum_sigma_a =0.;
        double sum_flux_a=0.;
        double sum_sigma_b =0.;
        double sum_flux_b=0.;
        double sum_sigma_c =0.;
        double sum_flux_c=0.;
        double sum_sigma_d =0.;
        double sum_flux_d =0.;
        double sum_sigma_ab =0.;
        double sum_flux_ab=0.;
        double sum_time=0.;
        int count =0 ;
for (p=ret1; p!=ret2; ++p){
        sum_sigma_a = sum_sigma_a + pow(p->second.a_band_err,-2.);
        sum_flux_a = sum_flux_a + p->second.a_band*pow(p->second.a_band_err,-2.);
        sum_sigma_b = sum_sigma_b + pow(p->second.b_band_err,-2.);
        sum_flux_b = sum_flux_b + p->second.b_band*pow(p->second.b_band_err,-2.);
        sum_sigma_c = sum_sigma_c + pow(p->second.c_band_err,-2.);
        sum_flux_c = sum_flux_c + p->second.c_band*pow(p->second.c_band_err,-2.);
        sum_sigma_d = sum_sigma_d + pow(p->second.d_band_err,-2.);
        sum_flux_d = sum_flux_d + p->second.d_band*pow(p->second.d_band_err,-2.);
        sum_sigma_ab = sum_sigma_ab + 1. / (pow(p->second.a_band_err,2.) + pow(p->second.b_band_err,2.));
        sum_flux_ab = sum_flux_ab + ((p->second.a_band + p->second.b_band) / (pow(p->second.a_band_err,2.) + pow(p->second.b_band_err,2.)));
        sum_time = sum_time + p->second.mjd_gbm;
        count = count+1;
        } // for p      
                double combine_a_f = sum_flux_a/sum_sigma_a;
                double combine_a_f_err = 1./sqrt(sum_sigma_a);
                double combine_b_f = sum_flux_b/sum_sigma_b;
                double combine_b_f_err = 1./sqrt(sum_sigma_b);
                double combine_c_f = sum_flux_c/sum_sigma_c;
                double combine_c_f_err = 1./sqrt(sum_sigma_c);
                double combine_d_f = sum_flux_d/sum_sigma_d;
                double combine_d_f_err = 1./sqrt(sum_sigma_d);
                double combine_ab_f = sum_flux_ab/sum_sigma_ab;
             double mean_time = sum_time / count;
//              printf("%d %d %d %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f %5.4f\n", i, ct1, count, mean_time, combine_a_f, combine_a_f_err, combine_b_f, combine_b_f_err, combine_ab_f, combine_ab_f_err, combine_c_f, combine_c_f_err, combine_d_f, combine_d_f_err);

// MAXI & LAT & ASM & BAT
                fprintf(outfile,"%d %d %d %5.4f %5.4e %5.4e %5.4e %5.4e %5.4e %5.4e  %5.4e %5.4e\n", i, ct1, count, mean_time, combine_a_f, combine_a_f_err, combine_b_f, combine_b_f_err, combine_c_f,combine_c_f_err,combine_d_f,combine_d_f_err);
// GBM 
//              fprintf(outfile, "%d %d %d %5.4f %5.4e %5.4e %5.4e %5.4e %5.4e %5.4e %5.4e %5.4e\n", i, ct1, count, mean_time, combine_a_f, combine_a_f_err, combine_b_f, combine_b_f_err,  combine_c_f, combine_c_f_err, combine_ab_f, combine_ab_f_err);
                sum_flux_a=0.;
                sum_sigma_a =0.;
                sum_flux_b=0.;
                sum_sigma_b =0.;
                sum_flux_c=0.;
                sum_sigma_c =0.;
                sum_flux_d=0.;
                sum_sigma_d =0.;
                sum_flux_ab=0.;
                sum_sigma_ab =0.;
                sum_time=0.;
                mean_time =0.;
                count =0;
           i = temp_mjd2;
        } // for i
                fclose(outfile);
}  // for kk 
} // main 

