#include "module_mem.cpp"
#include "module_mem.h"

//g++ -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o main_mem.sim main_mem.cpp -lsystemc -lm -std=c++11 -lboost_regex


// Basic library c++ set.
#include <iostream>
#include <string>
// System C library.
#include <systemc.h>

// To call basic c++ methods.
using namespace std;
// To call boost methods.    
using namespace sc_core;
 
int sc_main(int argc, char* argv[]) {

    memory mem("memory");
    sc_set_time_resolution(1, SC_PS);
 
    sc_trace_file *wf = sc_create_vcd_trace_file("data/memory");
    sc_trace(wf, mem.address, "address");
    sc_trace(wf, mem.data, "data");
    sc_trace(wf, mem.enable, "enable");
    sc_trace(wf, mem.rw, "rw");
 
    sc_signal enable;
    sc_signal rw;
    sc_signal > data;
    sc_signal<sc_lv > address;
 
    mem.rw(rw);
    mem.data(data);
    mem.address(address);
    mem.enable(enable);
 
    enable  = 0;
    data    = 0;
    address = 0;
    rw      = 0;
    sc_start(0, SC_PS);
 
    rw      = 1;
    address.write(0x10);
    data.write(0x110011);
    enable  = 1;
    sc_start(5, SC_PS);
 
    enable  = 0;
    sc_start(5, SC_PS);
 
    address.write(0x12);
    data.write(0x1100);
    enable  = 1;
    sc_start(5, SC_PS);
 
    address.write(0x8);
    data.write(0x1010);
    sc_start(5, SC_PS);
 
    rw      = 0;
    address = 0x10;
    sc_start(5, SC_PS);
 
    address = 0x1;
    sc_start(5, SC_PS);
 
    address = 0x3;
    sc_start(5, SC_PS);
 
    enable  = 0;
    sc_start(1, SC_PS);
 
    mem.memdump();
    sc_close_vcd_trace_file(wf);
 
    return(0);
}