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
//    memory mem("memory");
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



//    cpucr1.memory1.data_mem(data);
//    cpucr1.memory1.address_mem(address);
//    cpucr1.memory1.rw_mem(rw);
//    cpucr1.memory1.enable_mem(enable);
//    cpucr1.memory1.clk_mem(clk);
    cpucr1.rw_cpucr(rw);
    cpucr1.data_cpucr(data);
    cpucr1.address_cpucr(address);
    cpucr1.enable_cpucr(enable);
    cpucr1.clk_cpucr(clk);

//    cpucr1.data_(data);
//    cpucr1.address_trans(address);
//    cpucr1.rw_trans(rw);
//    cpucr1.enable_trans(enable);
//    cpucr1.clk_trans(clk);
////
//    mem.rw_mem(rw);
//    mem.data_mem(data);
//    mem.address_mem(address);
//    mem.enable_mem(enable);
//    mem.clk_mem(clk);
//    enable = 0;
//    data = 0;
//    address = 0;
//    rw = 0;
//
//    sc_start(0, SC_PS);
//
//    rw = 1;
//    address.write(0x11);
//    data.write(0x6F);
//    enable = 1;
//    sc_start(5, SC_PS);
//
//
//    enable = 0;
//    sc_start(5, SC_PS);
//
//    address.write(0x12);
//    data.write(0x6F);
//
//    enable = 1;
//    sc_start(5, SC_PS);
//
//    address.write(0x8);
//    data.write(0x6F);
//    sc_start(5, SC_PS);
//
//    rw = 0;
//    address = 0x0;
//    sc_start(5, SC_PS);
//
//    rw = 0;
//    address = 0x1;
//    sc_start(5, SC_PS);
//
//    rw = 0;
//    address = 0x2;
//    sc_start(5, SC_PS);
//
//    rw = 0;
//    address = 0x3;
//    sc_start(5, SC_PS);
//
//    address = 0x4;
//    sc_start(5, SC_PS);
//
//    address = 0x5;
//    sc_start(5, SC_PS);
//
//    address = 0x6;
//    sc_start(5, SC_PS);
//
//    address = 0x7;
//    sc_start(5, SC_PS);
//
//    address = 0x8;
//    sc_start(5, SC_PS);
//
//    address = 0x9;
//    sc_start(5, SC_PS);
//
//    address = 0xA;
//    sc_start(5, SC_PS);
//
//
//    address = 0xB;
//    sc_start(5, SC_PS);
//
//
//    address = 0xC;
//    sc_start(5, SC_PS);
//
//    enable = 0;

    sc_start(1, SC_US);
    cpucr1.transactor1.inst_exec();
    cpucr1.memory1.memdump();
//    sc_start(1, SC_PS);
//
//    mem.memdump();
   sc_close_vcd_trace_file(wf);

    return (0);
}
//    Trace vcd.
//    sc_trace_file *wf = sc_create_vcd_trace_file("CPUCR");
//    sc_trace(wf, address, "address");
//    sc_trace(wf, data, "data");
//    sc_trace(wf, enable, "enable");
//    sc_trace(wf, rw, "rw");
//    sc_trace(wf, clk, "clk");



//    sc_close_vcd_trace_file(wf);
//
//    return(0);
//}