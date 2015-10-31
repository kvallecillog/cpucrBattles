//
// Created by kenneth on 25/10/15.
//

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(transactor){

        // Port declarations
        sc_in< sc_lv <6> > dat_t_i;
        sc_out < sc_lv <6> > dat_t_o;
        sc_out < sc_lv <12> > addr_t_o;
        sc_out < sc_lv<1> > rw_t_o;
        sc_out < sc_lv<1> > en_t_o;
        sc_in_clk  clk_t_i;


        void inst_exec();

        SC_CTOR(transactor){

            SC_METHOD(inst_exec);

            sensitive << clk_t_i;


        }

};


