//
// Created by kenneth on 25/10/15.
//

#include "module_acum.h"

#include <iostream>
using namespace std;
// System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;

using namespace sc_dt;

void accumulator::entry_A()
{
//    if(enable.read() == 1) {

//        if(rw.read() == 1) {            //write
////            write_count++;
           acumA.write( acum_SysC.read() );
           cout << "@ |[" << sc_time_stamp()  << "]| Acumulador " <<"|[" <<acum_SysC.read().to_uint() << "]|" << endl;
//        } else {                        //read
//            data.write(ramdata[address.read().to_uint()].read());
//            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< data.read().to_uint()<< "]|" << " en direccion " <<"|["<< address.read().to_uint() << "]|" << endl;
//        }
//    } else {
//        data.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
//    }
}