// SystemC library.
#include <systemc>
// IO c library.
#include "stdio.h"
using namespace std;
using namespace sc_core;
using namespace sc_dt;

#include "module_mem.h"
#include "module_transactor.h"

SC_MODULE(cpucr){

    // Declaracion de puertos.
    sc_in_clk  clk_c_i;
    sc_out < sc_lv <6> > dat_c_o;
    sc_out< sc_lv <12> > addr_c_o;
    sc_out < sc_lv<1> > rw_c_o;
    sc_out < sc_lv<1> > en_c_o;
    sc_out < sc_lv <6> > acum_c_o;
    sc_out < sc_lv <6> > s_c_o;
    sc_out < sc_lv <6> > ri_c_o;
    sc_in < bool > rps_c_i;
    sc_out < sc_lv<12> > pc_c_o;
    sc_out <int> s_est_pres_c_o;
    sc_out <int> s_est_prox_c_o;
    sc_out <bool> s_CB_c_o;
    sc_out <bool> s_CM_c_o;
    sc_out <bool> s_LE_c_o;

    // Declaracion de señales internas para conexiones entre modulos.
    sc_signal < sc_uint<6> > ramdata[MEMORY-1];
    sc_signal < sc_lv <6> > dat_c_i_s;
    sc_signal < sc_lv <6> > dat_c_o_s;
    sc_signal< sc_lv <12> > addr_c_s;
    sc_signal < sc_lv<1> > rw_c_s;
    sc_signal < sc_lv<1> > en_c_s;

    void monitor();

    // Instanciacion de los modulos de memoria y transactor.
    memory memory1; /**< Se instancia el modulo de memoria. */
    transactor transactor1; /**< Se instancia el modulo de la FSM. */


    SC_CTOR(cpucr):memory1("memory1"), transactor1("transactor1"){

        /**< Conexion entre los modulos. */
        memory1.dat_m_i(transactor1.dat_t_o);
        memory1.dat_m_o(dat_c_o_s);
        memory1.addr_m_i(transactor1.addr_t_o);
        memory1.rw_m_i(rw_c_o);
        memory1.en_m_i(en_c_o);

        transactor1.dat_t_i(memory1.dat_m_o);
        transactor1.dat_t_o(dat_c_o);
        transactor1.addr_t_o(addr_c_o);
        transactor1.rw_t_o(rw_c_o);
        transactor1.en_t_o(en_c_o);

        transactor1.acum_t_o(acum_c_o);
        transactor1.s_t_o(s_c_o);

        transactor1.rps_t_i(rps_c_i);
        transactor1.pc_t_o(pc_c_o);
        transactor1.clk_t_i(clk_c_i);

        transactor1.s_est_pres(s_est_pres_c_o);
        transactor1.s_est_prox(s_est_prox_c_o);

        transactor1.ri_t_o(ri_c_o);

        transactor1.s_CB(s_CB_c_o);
        transactor1.s_CM(s_CM_c_o);
        transactor1.s_LE(s_LE_c_o);

        SC_METHOD(monitor);
        dont_initialize();
        sensitive << rps_c_i.pos();
    }
};

