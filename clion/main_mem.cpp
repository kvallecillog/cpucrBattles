#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

#include </usr/local/systemc-2.3.1/include/systemc>


#include "module_cpucr.h"

//#include "module_mem.cpp"

using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;

int sc_main(int argc, char* argv[]) {

    // Create channels
    sc_signal<sc_lv<1> > enable_ch;
    sc_signal<sc_lv<1> > rw_ch;
    sc_signal<sc_lv<6> > data_ch;
    sc_signal<sc_lv<12> > address_ch;

    // Create clock
    sc_set_time_resolution(1, SC_PS);
    sc_clock clk("clk", 10, SC_NS, 0.5, 5, SC_NS, false);

    // Module instantiations.
    cpucr cpucr1("cpucr");

    sc_signal<sc_lv<1> > enable;
    sc_signal<sc_lv<1> > rw;
    sc_signal<sc_lv<6> > data;
    sc_signal<sc_lv<12> > address;

    sc_trace_file *wf = sc_create_vcd_trace_file("cpucr");
    sc_trace(wf, address, "address");
    sc_trace(wf, data, "data");
    sc_trace(wf, enable, "enable");
    sc_trace(wf, rw, "rw");
    sc_trace(wf, clk, "clk");

    cpucr1.dat_c_o(data);
    cpucr1.addr_c_o(address);
    cpucr1.rw_c_o(rw);
    cpucr1.en_c_o(enable);
    cpucr1.clk_c_i(clk);

    sc_start(1, SC_US);
    cpucr1.transactor1.inst_exec();
    cpucr1.memory1.memdump();

   sc_close_vcd_trace_file(wf);

    return (0);
}
