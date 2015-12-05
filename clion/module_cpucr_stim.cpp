//
// Created by kenneth on 01/11/15.

#include <systemc>
#include "module_cpucr_stim.h"
//#include "module_main.cpp"

using namespace std;
using namespace sc_core;
using namespace sc_dt;


void cpucr_stim::stimgen() {
/** Proceso que simula el estimulo externo de la señal de reposicion.
 * @param rps_stim_o - rps_stim_o puerto de señal de reposicion.
 */
    while (true) {

        sc_core::wait(500, SC_NS);
        rps_stim_o.write(1);/**< Se genera el estimulo de reposicion. */

    }
}