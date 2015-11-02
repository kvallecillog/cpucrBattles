//
// Created by kenneth on 01/11/15.
//

#include <systemc>
#include "module_cpucr_stim.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


void cpucr_stim::stimgen() {

    while (true) {


        sc_core::wait(1, SC_US);

        rps_stim_o.write("1");


    }
}