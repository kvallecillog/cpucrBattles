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
/** Proceso que escribe o lee al arreglo de memoria de puertos 64 posiciones.
 * @param en_p_i - en_p_i señal de entrada que habilita la memoria de puertos.
 * @param rw_p_i - rw_p_i señal de entrada que define la tarea de lectura o escritura en memoria de puertos.
 * @param ramdata - ramdata arreglo de 4096 posiciones que simula la memoria de puertos.
 * @param addr_p_i - addr_p_i variable que contiene la posicion de memoria que se lee o escribe.
 * @param dat_p_i - dat_p_i variable que contiene los datos a escribir en memoria de puertos.
 * @param dat_p_o - dat_p_o variable que contiene los datos leidos de memoria de puertos.
 */
    // Si la memoria esta habilitada realice la operacion (Lectura o escritura).
    if(en_p_i.read() == 1) {
        if(rw_p_i.read() == 0) {
            // Escritura de memoria.
            ramdata[addr_p_i.read().to_uint()].write( dat_p_i.read() );
//            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<dat_p_i.read().to_uint() << "]|" << " en direccion " << "|["<< addr_p_i.read().to_uint() << "]|" << endl;
        }
        else {
            // Lectura de memoria.
            dat_p_o.write(ramdata[addr_p_i.read().to_uint()].read());
//            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< dat_p_o.read().to_uint()<< "]|" << " en direccion " <<"|["<< addr_p_i.read().to_uint() << "]|" << endl;
        }
    }
    else if(en_p_i.read() == 0) {
        // Si esta deshabilitada ponga en alta impedancia el puerto.
        dat_p_o.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    }
    else{
//        cout << "Inicializacion de la CPUCR" << endl;
    }
}