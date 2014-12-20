#ifndef LC_Info 
#define LC_Info
#include <vector>
#include <iostream>


class GBM_LC : public TObject
        {
public:
        GBM_LC():
        id(-9999),
        mjd_gbm(-9999),
        a_band(-9999),
        b_band(-9999),
        c_band(-9999),
        d_band(-9999),
        e_band(-9999),
        f_band(-9999),
        g_band(-9999),
        a_band_err(-9999),
        b_band_err(-9999),
        c_band_err(-9999),
        d_band_err(-9999),
        e_band_err(-9999),
        f_band_err(-9999),
        g_band_err(-9999)
        {}
        ~GBM_LC()
        {}
        int id;  //cluster id 
    double mjd_gbm; // number of hit inside one cluster 
        double a_band;
        double b_band;
        double c_band;
        double d_band;
        double e_band;
        double f_band;
        double g_band;
        double a_band_err;
        double b_band_err;
        double c_band_err;
        double d_band_err;
        double e_band_err;
        double f_band_err;
        double g_band_err;
        };
#endif
