//
// Created by kenneth on 25/10/15.
//

#ifndef CPUCRBATTLES_MODULE_EXECUTER_H
#define CPUCRBATTLES_MODULE_EXECUTER_H

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(executer){


        sc_inout < sc_lv <6> > data;
        sc_inout < sc_lv <12> >  address;
        sc_out < sc_lv<1> > rw;
        sc_out < sc_lv<1> > enable;
        sc_in <bool> clk;


        void inst_exec();


        SC_CTOR(executer){

            SC_METHOD(inst_exec);

            sensitive << clk ;

        }
};



#endif //CPUCRBATTLES_MODULE_EXECUTER_H
