
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

    sc_out < sc_lv <6> > dat_c_o;
    sc_out< sc_lv <12> > addr_c_o;
    sc_out < sc_lv<1> > rw_c_o;
    sc_out < sc_lv<1> > en_c_o;
    sc_in_clk  clk_c_i;

    // Signals declarations.

    sc_signal < sc_uint<6> > ramdata[MEMORY_H_-1];


    void monitor();

    memory memory1;

    transactor transactor1;

    SC_CTOR(cpucr):memory1("memory 1"), transactor1("transactor 1"){

        memory1.dat_m_i(transactor1.dat_t_o);
        memory1.dat_m_o(transactor1.dat_t_o);
        memory1.addr_m_i(transactor1.addr_t_o);
        memory1.rw_m_i(transactor1.rw_t_o);
        memory1.en_m_i(transactor1.en_t_o);
        memory1.clk_m_i(clk_c_i);

        transactor1.dat_t_i(memory1.dat_m_o);
        transactor1.dat_t_o(dat_c_o);
        transactor1.addr_t_o(addr_c_o);
        transactor1.rw_t_o(rw_c_o);
        transactor1.en_t_o(en_c_o);
        transactor1.clk_t_i(clk_c_i);

        SC_METHOD(monitor);

        sensitive << clk_c_i ;

    }

};
