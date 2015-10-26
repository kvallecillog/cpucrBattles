// Basic library c++ set.
#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

// System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_mem.h"
#include "module_transactor.h"

#include "module_acum.h"

//#include "module_mem.cpp"

// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;

int sc_main(int argc, char* argv[]) {


//    executer exec("exec");
//    accumulator acum("acum");

    // Create channels
    sc_signal < sc_lv <1> > enable;
    sc_signal < sc_lv <1> > rw;
    sc_signal < sc_lv <6> > data;
    sc_signal < sc_lv <12> > address;

    // Create clock
    sc_set_time_resolution(1,  SC_NS);
    sc_clock clk ("clk", 10 ,  SC_NS, 0.5, 5,SC_NS,false);

    // Module instantiations.
    memory mem("memory");
    transactor trans("trans");

    // Trace vcd.
    sc_trace_file *wf = sc_create_vcd_trace_file("CPUCR");
    sc_trace(wf, mem.address, "address");
    sc_trace(wf, mem.data, "data");
    sc_trace(wf, mem.enable, "enable");
    sc_trace(wf, mem.rw, "rw");
    sc_trace(wf, mem.clk, "clk");

    // Module port bindings.
    trans(data, address, rw, enable, clk);
    mem(trans.data, trans.address, trans.rw, trans.enable, clk);


//    sc_signal < sc_lv <6> > acum_SysC;
//    sc_signal < sc_lv <6> > mem_data_SysC;
//    sc_signal < sc_lv <6> > word_1_SysC;
//    sc_signal < sc_lv <6> > word_2_SysC;

//    sc_trace(wf, acum.acum_SysC, "acum_SysC");
//    sc_trace(wf, acum.word_1_SysC, "word_1_SysC");
//    sc_trace(wf, acum.word_2_SysC, "word_2_SysC");



    trans.load_obj_file();
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
    sc_close_vcd_trace_file(wf);

    return(0);
}