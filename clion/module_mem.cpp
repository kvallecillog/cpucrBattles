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


#include "module_mem.h"


// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


void memory::entry(){

    if(en_m_i.read() == 1) {

        if(rw_m_i.read() == 0) {

            //write
            ramdata[addr_m_i.read().to_uint()].write( dat_m_i.read() );
//            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<dat_m_i.read().to_uint() << "]|" << " en direccion " << "|["<< addr_m_i.read().to_uint() << "]|" << endl;

        }
        else {

            //read
            dat_m_o.write(ramdata[addr_m_i.read().to_uint()].read());
//            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< dat_m_o.read().to_uint()<< "]|" << " en direccion " <<"|["<< addr_m_i.read().to_uint() << "]|" << endl;

        }
    }
    else if(en_m_i.read() == 0) {

        dat_m_o.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");

    }
    
    else{

//        cout << "Inicializacion de la CPUCR" << endl;

    }

}