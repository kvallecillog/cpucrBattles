//
// Created by kenneth on 01/11/15.
//
#include <systemc>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(cpucr_stim) {

        // Declaracion de puertos.
        sc_in_clk clk_stim_i;
        sc_out < bool > rps_stim_o;

        void stimgen();

        SC_CTOR(cpucr_stim){
            SC_THREAD(stimgen);
            rps_stim_o.initialize(0);
        }
};
