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
    sc_signal < sc_lv <1> > enable_ch;
    sc_signal < sc_lv <1> > rw_ch;
    sc_signal < sc_lv <6> > data_ch;
    sc_signal < sc_lv <12> > address_ch;

    // Create clock
    sc_set_time_resolution(1,  SC_PS);
    sc_clock clk ("clk", 10 ,  SC_NS, 0.5, 5,SC_NS,false);

    // Module instantiations.
    cpucr cpucr1("cpucr");
//    transactor trans("trans");
//    memory mem("mem");
    // Trace vcd.
//    sc_trace_file *wf = sc_create_vcd_trace_file("CPUCR");
//    sc_trace(wf, address, "address");
//    sc_trace(wf, data, "data");
//    sc_trace(wf, enable, "enable");
//    sc_trace(wf, rw, "rw");
//    sc_trace(wf, clk, "clk");

    // Module port bindings.
//    trans(data_ch, address_ch, rw_ch, enable_ch, clk);
////    mem(data_ch, address_ch, rw_ch, enable_ch, clk);
//    trans.data_trans(mem.data_mem);
//    trans.address_trans(mem.address_mem);
//    trans.rw_trans(mem.rw_mem);
//    trans.enable_trans(mem.enable_mem);
//    trans.clk(clk);

//    mem.data_mem(trans.data_trans);
//    mem.address_mem(trans.address_trans);
//    mem.rw_mem(trans.rw_trans);
//    mem.enable_mem(trans.enable_trans);
//    mem.clk_mem(clk);
//    trans.clk_trans(clk);

//    sc_inout < sc_lv <6> > data_mem;
//    sc_in < sc_lv <12> >  address_mem;
//    sc_in < sc_lv<1> > rw_mem;
//    sc_in < sc_lv<1> > enable_mem;
//    sc_in_clk  clk;

//    sc_signal < sc_lv <6> > acum_SysC;
//    sc_signal < sc_lv <6> > mem_data_SysC;
//    sc_signal < sc_lv <6> > word_1_SysC;
//    sc_signal < sc_lv <6> > word_2_SysC;

//    sc_trace(wf, acum.acum_SysC, "acum_SysC");
//    sc_trace(wf, acum.word_1_SysC, "word_1_SysC");
//    sc_trace(wf, acum.word_2_SysC, "word_2_SysC");


//    sc_start(100, SC_NS);
//    mem.mem_init();
//    trans.load_obj_file();
//    sc_stop();

//    exec.rw(rw);
//    exec.data(data);
//    exec.address(address);
//    exec.enable(enable);
//    exec.clk(clk);


//    acum.address(address);
//    acum.clk(clk);
//    acum.acum_SysC(acum_SysC);
//    acum.word_1_SysC(word_1_SysC);
//    acum.word_2_SysC(word_2_SysC);

    //load.load_obj_file();
//    mem.memdump();
//    sc_close_vcd_trace_file(wf);

    return(0);
}