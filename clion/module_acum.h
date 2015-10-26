//
// Created by kenneth on 25/10/15.
//

#ifndef CPUCRBATTLES_MODULE_ACUM_H
#define CPUCRBATTLES_MODULE_ACUM_H


// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"


// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;

using namespace sc_dt;

SC_MODULE(accumulator)
{
    sc_in < sc_lv <12> >  address;
    sc_in <bool> clk;
    sc_in < sc_lv<6> > acum_SysC;
    sc_in < sc_lv<6> > word_1_SysC;
    sc_in < sc_lv<6> > word_2_SysC;

    sc_signal< sc_uint<6> > acumA;

    void entry_A();


    SC_CTOR(accumulator)
    {
        SC_METHOD(entry_A);

        sensitive << clk  ;

    }
};


#endif //CPUCRBATTLES_MODULE_ACUM_H
