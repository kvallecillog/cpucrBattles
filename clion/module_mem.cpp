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
/** Proceso que escribe o lee al arreglo de memoria de 4096 posiciones de la CPUCR.
 * @param en_m_i - en_m_i señal de entrada que habilita la memoria.
 * @param rw_m_i - rw_m_i señal de entrada que define la tarea de lectura o escritura en memoria.
 * @param ramdata - ramdata arreglo de 4096 posiciones que simula la memoria de la CPUCR.
 * @param addr_m_i - addr_m_i variable que contiene la posicion de memoria que se lee o escribe.
 * @param dat_m_i - dat_m_i variable que contiene los datos a escribir en memoria.
 * @param dat_m_o - dat_m_o variable que contiene los datos leidos de memoria.
 */
    if(en_m_i.read() == 1) {
        if(rw_m_i.read() == 0) {
            // Escritura de memoria.
            ramdata[addr_m_i.read().to_uint()].write( dat_m_i.read() );
//            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<dat_m_i.read().to_uint() << "]|" << " en direccion " << "|["<< addr_m_i.read().to_uint() << "]|" << endl;
        }
        else {
            // Lectura de memoria.
            dat_m_o.write(ramdata[addr_m_i.read().to_uint()].read());
//            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< dat_m_o.read().to_uint()<< "]|" << " en direccion " <<"|["<< addr_m_i.read().to_uint() << "]|" << endl;
        }
    }
    else if(en_m_i.read() == 0) {
        // Si esta deshabilitada ponga en alta impedancia el puerto.
        dat_m_o.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    }
    else{
//        cout << "Inicializacion de la CPUCR" << endl;
    }
}