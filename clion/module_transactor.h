//
// Created by kenneth on 25/10/15.
//

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(transactor){

        // Port declarations
        sc_inout < sc_lv <6> > data_trans;
        sc_out < sc_lv <12> > address_trans;
        sc_out < sc_lv<1> > rw_trans;
        sc_out < sc_lv<1> > enable_trans;
        sc_in_clk  clk_trans;

//        void load_obj_file();
        //void inst_exec();
        void inst_exec();
//        void word_load(int );

        SC_CTOR(transactor){


        //   SC_METHOD(get_obj_file);
            //
            //
            SC_METHOD(inst_exec);
            // Lista de sensitivad del proceso load_obj_file.
            sensitive << clk_trans;
//            SC_METHOD(word_load);
            SC_METHOD(inst_exec);


//        sensitive << address << data_out << rw << enable ;
        //sensitive << clk_trans;
        }
};


