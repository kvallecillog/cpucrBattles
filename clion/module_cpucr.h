
// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"
using namespace std;
using namespace sc_core;
using namespace sc_dt;

#include "module_mem.h"
#include "module_transactor.h"

SC_MODULE(cpucr){

    // Port declarations

    sc_inout < sc_lv <6> > data_cpucr;
    sc_in < sc_lv <12> > address_cpucr;
    sc_in < sc_lv<1> > rw_cpucr;
    sc_in < sc_lv<1> > enable_cpucr;
    sc_in_clk  clk_cpucr;

    // Signals declarations.
    sc_signal < sc_uint<6> > ramdata[MEMORY_H_-1];

//    sc_signal < sc_lv <6> > data_bus;
//    sc_signal < sc_lv <12> > address_bus;
//    sc_signal < sc_lv <1> > rw_bus;
//    sc_signal < sc_lv <1> > enable_bus;

    void monitor();

    memory memory1;
//    transactor transactor1;

    SC_CTOR(cpucr):memory1("memory"){

        memory1.data_mem(data_cpucr);
        memory1.address_mem(address_cpucr);
        memory1.rw_mem(rw_cpucr);
        memory1.enable_mem(enable_cpucr);
        memory1.clk_mem(clk_cpucr);

//        sc_inout < sc_lv <6> > data_mem;
//        sc_in < sc_lv <12> >  address_mem;
//        sc_in < sc_lv<1> > rw_mem;
//        sc_in < sc_lv<1> > enable_mem;
//        sc_in_clk  clk_mem;
//
//        transactor1.data_trans(data_cpucr);
//        transactor1.address_trans(address_cpucr);
//        transactor1.rw_trans(rw_cpucr);
//        transactor1.enable_trans(enable_cpucr);
//        transactor1.clk_trans(clk_cpucr);
//        memory1.memdump();
        SC_METHOD(monitor);
        sensitive << clk_cpucr << enable_cpucr << rw_cpucr << address_cpucr ;
            
    }
};
