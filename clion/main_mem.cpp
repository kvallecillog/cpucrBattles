#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_cpucr.h"

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
    sc_set_time_resolution(1, SC_NS);
    sc_clock clk("clk", 500, SC_NS, 0.5, 0, SC_NS, false);

    // Module instantiations.
    cpucr cpucr1("cpucr");

    sc_signal<sc_lv<1> > enable;
    sc_signal<sc_lv<1> > rw;
    sc_signal<sc_lv<6> > data;
    sc_signal<sc_lv<12> > address;
    sc_signal < sc_lv <6> > acum;
    sc_signal < sc_lv <6> > s;
    sc_signal < sc_lv <6> > ports_i;
    sc_signal < sc_lv <6> > ports_o;
    sc_signal < sc_lv <1> > rps;
    sc_signal < sc_lv <12> > pc;

    cpucr1.rps_c_o.initialize("1");

    sc_trace_file *wf = sc_create_vcd_trace_file("cpucr");

    sc_trace(wf, address, "address");
    sc_trace(wf, data, "data");
    sc_trace(wf, enable, "enable");
    sc_trace(wf, rw, "rw");
    sc_trace(wf, clk, "clk");

    sc_trace(wf, acum, "acum");
    sc_trace(wf, s, "s");
    sc_trace(wf, ports_i, "ports_i");
    sc_trace(wf, ports_o, "ports_o");
    sc_trace(wf, rps, "rps");
    sc_trace(wf, pc, "pc");

    sc_trace(wf, cpucr1.addr_c_o, "addr_c_o");
    sc_trace(wf, cpucr1.dat_c_o, "dat_c_o");
    sc_trace(wf, cpucr1.en_c_o, "en_c_o");
    sc_trace(wf, cpucr1.rw_c_o, "rw_c_o");
    sc_trace(wf, cpucr1.rps_c_o, "rps_c_i");
    sc_trace(wf, cpucr1.pc_c_o, "pc_c_o");
    sc_trace(wf, cpucr1.s_c_o, "s_c_o");



    sc_trace(wf, cpucr1.memory1.addr_m_i, "addr_m_i");
    sc_trace(wf, cpucr1.memory1.dat_m_i, "dat_m_i");
    sc_trace(wf, cpucr1.memory1.dat_m_o, "dat_m_o");
    sc_trace(wf, cpucr1.memory1.en_m_i, "en_m_i");
    sc_trace(wf, cpucr1.memory1.rw_m_i, "rw_m_i");
    
    sc_trace(wf, cpucr1.transactor1.addr_t_o, "addr_t_o");
    sc_trace(wf, cpucr1.transactor1.dat_t_i, "dat_t_i");
    sc_trace(wf, cpucr1.transactor1.dat_t_o, "dat_t_o");
    sc_trace(wf, cpucr1.transactor1.en_t_o, "en_t_i");
    sc_trace(wf, cpucr1.transactor1.rw_t_o, "rw_t_i");

    sc_trace(wf, cpucr1.transactor1.acum_t_o, "acum_t_o");
    sc_trace(wf, cpucr1.transactor1.s_t_o, "s_t_o");
    sc_trace(wf, cpucr1.transactor1.ports_t_i, "ports_t_i");
    sc_trace(wf, cpucr1.transactor1.ports_t_o, "ports_t_o");

    cpucr1.dat_c_o(data);
    cpucr1.addr_c_o(address);
    cpucr1.rw_c_o(rw);
    cpucr1.en_c_o(enable);
    cpucr1.clk_c_i(clk);

    cpucr1.acum_c_o(acum);
    cpucr1.s_c_o(s);
    cpucr1.ports_c_i(ports_i);
    cpucr1.ports_c_o(ports_o);
    cpucr1.rps_c_o(rps);
    cpucr1.pc_c_o(pc);

    sc_start(10, SC_US);
    cpucr1.monitor();
    cpucr1.transactor1.inst_exec();
    cpucr1.memory1.memdump();
    sc_stop();


    sc_close_vcd_trace_file(wf);

    return (0);
}
