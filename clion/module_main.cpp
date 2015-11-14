#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
//
//#include </usr/local/systemc-2.3.1/include/systemc>
#include </usr/local/systemc-2.3.1/include/sysc/kernel/sc_wait.h>

#include <systemc>

#include "module_cpucr.h"
#include "module_cpucr_stim.h"


using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;

int sc_main(int argc, char* argv[]) {


    sc_set_time_resolution(1, SC_NS);
    // Generacion de la señal de reloj de 2 MHz
    sc_clock clk("clk", 500, SC_NS, 0.5, 0, SC_NS, false);

    // Declaracion de la instancia CPUCR.
    cpucr cpucr1("cpucr");

    // Declaracion de la instancia del testbench.
    cpucr_stim test_bench ("test_bench");

    // Señales de observacion.
    sc_signal<sc_lv<1> > enable;
    sc_signal<sc_lv<1> > rw;
    sc_signal<sc_lv<6> > data;
    sc_signal<sc_lv<12> > address;
    sc_signal < sc_lv <6> > acum;
    sc_signal < sc_lv <6> > s;
    sc_signal < sc_lv <6> > ports_i;
    sc_signal < sc_lv <6> > ports_o;
    sc_signal < sc_lv <6> > RI;
    sc_signal < bool > rps;
    sc_signal < bool > init;
    sc_signal < sc_lv <12> > pc;
    sc_signal < int > est_pres;
    sc_signal < int > est_prox;

    sc_signal < bool > CB;
    sc_signal < bool > CM;
    sc_signal < bool > LE;


    // Se crea el trace vcd que contiene la simulacion gtkwave.
    sc_trace_file *wf = sc_create_vcd_trace_file("cpucr");

    // Se incluyen las señales a la simulacion vcd.

    // Señales de observacion externa.
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

    sc_trace(wf, CB, "CB");
    sc_trace(wf, CM, "CM");
    sc_trace(wf, LE, "LE");

    // Señales del modulo Testbench.
    sc_trace(wf, test_bench.rps_stim_o, "rps_stim_o");

    // Señales del modulo CPUCR.
    sc_trace(wf, cpucr1.addr_c_o, "addr_c_o");
    sc_trace(wf, cpucr1.dat_c_o, "dat_c_o");
    sc_trace(wf, cpucr1.en_c_o, "en_c_o");
    sc_trace(wf, cpucr1.rw_c_o, "rw_c_o");
    sc_trace(wf, cpucr1.rps_c_i, "rps_c_i");
    sc_trace(wf, cpucr1.pc_c_o, "pc_c_o");
    sc_trace(wf, cpucr1.s_c_o, "s_c_o");
    sc_trace(wf, cpucr1.ri_c_o, "RI");



    // Señales del modulo de memoria.
    sc_trace(wf, cpucr1.memory1.addr_m_i, "addr_m_i");
    sc_trace(wf, cpucr1.memory1.dat_m_i, "dat_m_i");
    sc_trace(wf, cpucr1.memory1.dat_m_o, "dat_m_o");
    sc_trace(wf, cpucr1.memory1.en_m_i, "en_m_i");
    sc_trace(wf, cpucr1.memory1.rw_m_i, "rw_m_i");

    // Señales del modulo transactor
    sc_trace(wf, cpucr1.transactor1.addr_t_o, "addr_t_o");
    sc_trace(wf, cpucr1.transactor1.dat_t_i, "dat_t_i");
    sc_trace(wf, cpucr1.transactor1.dat_t_o, "dat_t_o");
    sc_trace(wf, cpucr1.transactor1.en_t_o, "en_t_i");
    sc_trace(wf, cpucr1.transactor1.rw_t_o, "rw_t_i");
    sc_trace(wf, cpucr1.transactor1.acum_t_o, "acum_t_o");
    sc_trace(wf, cpucr1.transactor1.s_t_o, "s_t_o");
    sc_trace(wf, cpucr1.transactor1.ports_t_i, "ports_t_i");
    sc_trace(wf, cpucr1.transactor1.ports_t_o, "ports_t_o");
    sc_trace(wf, cpucr1.transactor1.rps_t_i ,"rps_t_i");

    sc_trace(wf, cpucr1.transactor1.init_t_o ,"init_t_o");

    sc_trace(wf, cpucr1.transactor1.s_est_pres ,"s_est_pres");
    sc_trace(wf, cpucr1.transactor1.s_est_prox ,"s_est_prox");

    sc_trace(wf, cpucr1.transactor1.s_CB ,"s_CB");
    sc_trace(wf, cpucr1.transactor1.s_CM,"s_CM");
    sc_trace(wf, cpucr1.transactor1.s_LE ,"s_LE");



    sc_trace(wf, cpucr1.init_c_o ,"init_c_o");


    // Conexiones entre el testbench y las señales externas.

    test_bench.clk_stim_i(clk);
    test_bench.rps_stim_o(rps);

    // Conexiones entre el modulo cpucr y las señales externas.
    cpucr1.rps_c_i(test_bench.rps_stim_o);
    cpucr1.dat_c_o(data);
    cpucr1.addr_c_o(address);
    cpucr1.rw_c_o(rw);
    cpucr1.en_c_o(enable);
    cpucr1.clk_c_i(clk);
    cpucr1.acum_c_o(acum);
    cpucr1.s_c_o(s);
    cpucr1.ports_c_i(ports_i);
    cpucr1.ri_c_o(RI);

    cpucr1.ports_c_o(ports_o);

    cpucr1.s_est_pres_c_o(est_pres);

    cpucr1.s_est_prox_c_o(est_prox);


    cpucr1.s_CB_c_o(CB);

    cpucr1.s_CM_c_o(CM);

    cpucr1.s_LE_c_o(LE);



    cpucr1.pc_c_o(pc);
    cpucr1.init_c_o(init);

    sc_start(100, SC_US);

    test_bench.stimgen();


    cpucr1.monitor();

//    cpucr1.transactor1.init_cpucr();
//    cpucr1.transactor1.inst_exec();
   // cpucr1.memory1.memdump();

    sc_stop();


    sc_close_vcd_trace_file(wf);

    return (0);
}
