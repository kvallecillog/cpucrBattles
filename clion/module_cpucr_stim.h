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

        // Declaracion de puertos.
        sc_in_clk clk_stim_i;
        sc_out < bool > rps_stim_o;
        sc_out < sc_lv <6> > ports_stim_o;
        sc_out < sc_lv <6> > address_ports_stim_o;
        sc_out < sc_lv<1> > rw_ports_stim_o;
        sc_out < sc_lv<1> > en_ports_stim_o;

        void stimgen();

        SC_CTOR(cpucr_stim){
            SC_THREAD(stimgen);
            sensitive << clk_stim_i.neg();
            rps_stim_o.initialize(0);
            ports_stim_o.initialize(0);
            en_ports_stim_o.initialize(0);
            rw_ports_stim_o.initialize(0);
        }
};

#endif //CPUCRBATTLES_MODULE_CPUCR_STIM_H
