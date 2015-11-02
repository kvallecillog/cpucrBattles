//
// Created by kenneth on 01/11/15.
//

#ifndef CPUCRBATTLES_MODULE_CPUCR_STIM_H
#define CPUCRBATTLES_MODULE_CPUCR_STIM_H

#include <systemc>

using namespace std;
using namespace sc_core;
using namespace sc_dt;


SC_MODULE(cpucr_stim) {

        sc_in_clk clk_stim_i;
        sc_out < bool > rps_stim_o;

        void stimgen();

        SC_CTOR(cpucr_stim){

            SC_THREAD(stimgen);
            sensitive_neg << clk_stim_i;


        }
};

#endif //CPUCRBATTLES_MODULE_CPUCR_STIM_H
