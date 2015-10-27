#ifndef MEMORY_H_
#define MEMORY_H_ 4096

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(cpucr){

    // Port declarations
    sc_inout < sc_lv <6> > data_cpucr;
    sc_in < sc_lv <12> >  address_cpucr;
    sc_in < sc_lv<1> > rw_cpucr;
    sc_in < sc_lv<1> > enable_cpucr;
    sc_in_clk  clk_cpucr;
    // Signals declarations.
    sc_signal< sc_uint<6> > ramdata[MEMORY_H_-1];

    void monitor();

    SC_CTOR(cpucr){

        SC_METHOD(monitor);
        sensitive << clk_cpucr << enable_cpucr << rw_cpucr << address_cpucr ;
            
    }
};

#endif /* MEMORY_H_ */