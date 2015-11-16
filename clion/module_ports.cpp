//
// Created by kenneth on 25/10/15.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

 // System C library.
//#include </usr/local/systemc-2.3.1/include/systemc>
#include <systemc>


#include "module_ports.h"


// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


void ports::entry(){

    if(en_p_i.read() == 1) {

        if(rw_p_i.read() == 0) {

            //write
            ramdata[addr_p_i.read().to_uint()].write( dat_p_i.read() );
//            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<dat_p_i.read().to_uint() << "]|" << " en direccion " << "|["<< addr_p_i.read().to_uint() << "]|" << endl;

        }
        else {

            //read
            dat_p_o.write(ramdata[addr_p_i.read().to_uint()].read());
//            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< dat_p_o.read().to_uint()<< "]|" << " en direccion " <<"|["<< addr_p_i.read().to_uint() << "]|" << endl;

        }
    }
    else if(en_p_i.read() == 0) {

        dat_p_o.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

    }
    
    else{

//        cout << "Inicializacion de la CPUCR" << endl;

    }

}