//
// Created by kenneth on 25/10/15.
//

#ifndef CPUCRBATTLES_MODULE_LOADER_H
#define CPUCRBATTLES_MODULE_LOADER_H

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(transactor){


        sc_out < sc_lv <6> > data;
        sc_out < sc_lv <12> > address;
        sc_out < sc_lv<1> > rw;
        sc_out < sc_lv<1> > enable;
        sc_in <bool> clk;


        vector <string> get_obj_file();
        void load_obj_file();
        void inst_exec();

//        void word_load(int );

        SC_CTOR(transactor){

        //   SC_METHOD(get_obj_file);
            SC_METHOD(load_obj_file);
//            SC_METHOD(word_load);
//            SC_METHOD(inst_exec);


        sensitive << clk ;

        }
};

#endif //CPUCRBATTLES_MODULE_LOADER_H
