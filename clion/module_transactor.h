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

        int mem_cont, A, word_1, word_2, word_cont, opcode_mem, address_ind_int, oper_cont;

        unsigned int mem_data_dec;

        string mem_data_str, operand, address_ind_str, pa_address_ind, pb_address_ind;

        stringstream address_ind_ss, pa_address_ind_ss, pb_address_ind_ss;

        bool stop, decode, fetched, execute;

//    en_t_o.write(0);
    void inst_exec();

        SC_CTOR(transactor){

            SC_METHOD(inst_exec);

            sensitive << clk_t_i;
            
            mem_cont= A= word_1= word_2= word_cont= opcode_mem= address_ind_int= oper_cont = 0;

            mem_data_dec = 0;

            stop = false;
            
            decode = false;
            
            fetched = false;
            
            execute = false;

            dat_t_i.initialize(0);
            addr_t_o.initialize(0);
            rw_t_o.initialize(0);
            en_t_o.initialize(0);
//            dat_t_o = 0;
//            addr_t_o = 0;
//            rw_t_o = 0;
//            en_t_o = 0;


        }

};


