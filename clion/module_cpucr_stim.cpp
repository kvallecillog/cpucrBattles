//
// Created by kenneth on 01/11/15.

#include <systemc>
#include "module_cpucr_stim.h"

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

        sc_core::wait(500, SC_NS);

        en_ports_stim_o.write("1");/**< Habilita la memoria de puertos. */
        address_ports_stim_o.write("0");/**< Direccion del puerto a escribir. */
        rw_ports_stim_o.write("1"); /**< Modo de escritura a puerto. */
        int valor = 7;
        ports_stim_o.write(valor);/**< Se genera el estimulo de puerto de entrada. */

    }
}