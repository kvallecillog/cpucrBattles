//
// Created by kenneth on 25/10/15.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
//#include </usr/local/systemc-2.3.1/include/systemc>
#include <systemc>

#include "module_transactor.h"
#include "module_mem.h"

#include "definitions_dec.cpp"


using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;

void  transactor::p_Ports() {
/** Proceso que simula la interface de escritura externa de puertos.
 * @param port_address - port_address Direccion del puerto al que se quiere escribir.
 * @param port_data - port_data Arreglo que contiene los datos escritos a los puertos.
 * @param port_data_write - port_data_write variable que contiene el proximo estado.
 * @return port_data - port_data El arreglo con los datos escritos a los puertos.
 */

    cout << "Ingresa al proceso: tiempo " << sc_time_stamp() << endl;

//  Escritura de puertos
    sc_core::wait(500, SC_NS);
    port_address = 0;
    port_data[port_address] = 0;
    port_data_write = port_data[port_address];
    cout << "Escritura a Puerto: " << "|[@" << port_address << "]|" << " Dato: " << "|[@" << port_data_write << "]|" << " en T: " << "|[" << sc_time_stamp() << "]|" << endl;

    sc_core::wait(500, SC_NS);
    port_address = 1;
    port_data[port_address] = 1;
    port_data_write = port_data[port_address];
    cout << "Escritura a Puerto: " << "|[@" << port_address << "]|" << " Dato: " << "|[@" << port_data_write << "]|" << " en T: " << "|[" << sc_time_stamp() << "]|" << endl;

    sc_core::wait(500, SC_NS);
    port_address = 2;
    port_data[port_address] = 2;
    port_data_write = port_data[port_address];
    cout << "Escritura a Puerto: " << "|[@" << port_address << "]|" << " Dato: " << "|[@" << port_data_write << "]|" << " en T: " << "|[" << sc_time_stamp() << "]|" << endl;


    sc_core::wait(500, SC_NS);
    port_address = 3;
    port_data[port_address] = 3;
    port_data_write = port_data[port_address];
    cout << "Escritura a Puerto: " << "|[@" << port_address << "]|" << " Dato: " << "|[@" << port_data_write << "]|" << " en T: " << "|[" << sc_time_stamp() << "]|" << endl;

//  Lectura de puertos
    sc_core::wait(1000, SC_NS);
    port_address = 1;
    port_data_read = port_data[port_address];
    cout << "Lectura a Puerto: " << "|[@" << port_address << "]|" << " Dato: " << "|[@" << port_data_read << "]|" << " en T: " << "|[" << sc_time_stamp() << "]|" << endl;

}

void  transactor::p_CB() {
/** Calcula la bandera s_CB para identificar el ciclo de busqueda.
 *  Tambien calcula la bandera CM.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param s_CB - s_CB señal de ciclo de busqueda.
 * @param s_CM - s_CM señal de ciclo de memoria.
 * @return s_CB - s_CB retorna la bandera de ciclo de busqueda.
 * @return s_CM - s_CM retorna la bandera de ciclo de memoria.
 */

    if (rps_t_i){
        if(s_est_prox == Estado_1){
            s_CB = true;
        }
        else{
            s_CB = false;
        }
    }
    else{
        s_CB = false;
    }
    if (!rps_t_i){
        v_CM = false;
        s_CM = v_CM;
    }
    else if((s_est_prox == Estado_1)&&(s_est_pres == Estado_16)){
        v_CM = true;
        s_CM = v_CM;
        s_CM = true;
    }
    else{
        v_CM = not v_CM;
        s_CM = v_CM;
    }
}

void  transactor::p_LE() {
/** Calcula la bandera rw_t_o, lectura y escritura, la cual se define dependiendo del estado presente.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param rw_t_o - rw_t_o señal de lectura y escritura.
 * @param en_t_o - en_t_o señal de habilitar memoria.
 * @param s_RI - s_RI variable que contiene el codigo de instruccion leido.
 */


    if(!rps_t_i){
        s_LE = true;
        rw_t_o = true;
        
    }
    else {
        switch (s_est_pres) {
            case Estado_0:{
                s_LE = true;
                rw_t_o = true;
                en_t_o = true;
                break;
            }
            case Estado_1:{
                s_LE = true;
                rw_t_o = true;
                en_t_o = true;

                break;
            }
            case Estado_3:{
                switch (s_RI.read().to_uint()) {
                    case PHA_ACU:
                    case PHS_CTR: {
                        s_LE = false;
                        rw_t_o = false;
                        en_t_o = true;
                        break;
                    }
                    case JSR_ABS: {
                        s_LE = false;
                        rw_t_o = false;
                        en_t_o = true;
                        break;
                    }
                    default: {
                        s_LE = true;
                        rw_t_o = true;
                        en_t_o = true;
                        break;
                    }
                }
                break;
            }
            case Estado_5:{
                switch (s_RI.read().to_uint()) {
                    case JSR_ABS:{
                        s_LE = false;
                        rw_t_o = false;
                        en_t_o = true;
                        break;
                    }
                    case OUT_IO:{


                    }
                    default: {
                        s_LE = true;
                        rw_t_o = true;
                        en_t_o = true;
                        break;
                    }
                }
                break;
            }
            case Estado_7:{
                switch (s_RI.read().to_uint()) {
                    case STA_ABS:{
                        s_LE = false;
                        rw_t_o = false;
                        en_t_o = true;
                        break;
                    }
                    default:
                        s_LE = true;
                        rw_t_o = true;
                        en_t_o = true;
                        break;
                }
                break;
            }
            case Estado_11:{
                switch (s_RI.read().to_uint()) {
                    case STA_IND:{
                        s_LE = false;
                        rw_t_o = false;
                        en_t_o = true;
                        break;
                    }
                    default:
                        s_LE = true;
                        rw_t_o = true;
                        en_t_o = true;
                        break;
                }
                break;
            }
            default: {
                s_LE = true;
                rw_t_o = true;
                en_t_o = en_t_o;
                break;
            }
        }
    }
}

void transactor::p_PC(){
/** Calcula el contador de posicion y la direccion de memoria.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param addr_t_o - addr_t_o puerto que contiene la direccion de memoria accesada.
 * @param pc_t_o - pc_t_o puerto que contiene el contador de posicion PC.
 * @param s_RI - s_RI variable que contiene el codigo de instruccion leido.
 */

    if(!rps_t_i){
        v_PC = 0;
        v_addr = 0;
        v_PB = 0;
        s_PB = 0;
    }
    else{
        switch (s_est_pres) {
            case Estado_0:{
                v_PC = 0;
                pc_t_o = v_PC;
                v_addr = 0;
                addr_t_o = v_addr;
                break;
            }
            case Estado_1:{
                pc_t_o = pc_t_o;
                addr_t_o = addr_t_o;
                break;
            }
            case Estado_2:{
                switch (s_RI.read().to_uint()) {
                    case CPA_ACU: case LDA_INM: case ADD_INM:
                    case TAP_CTR: case TPA_CTR: case CLA_ACU:
                    case INA_ACU: case DCA_ACU: case SUB_INM:
                    case AND_INM: case ORA_INM: case INP_IO:
                    case OUT_IO: {
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        break;
                    }
                    case ROL_ACU: case ROR_ACU: case BCC_REL:
                    case BCS_REL: case CLC_IMP: case SEC_IMP:
                    case SEI_IMP: case CLI_IMP: case NOP_CTR:
                    case BNE_REL: case BEQ_REL: case BMI_REL:
                    case BPL_REL: case STA_ABS: case LDA_ABS:
                    case AND_ABS: case SUB_ABS: case ORA_ABS:
                    case ADD_ABS: case JMP_ABS: case BVS_REL:
                    case BVC_REL:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        break;
                    }
                    case LDA_IND: case ADD_IND: case SUB_IND:
                    case AND_IND: case ORA_IND: case STA_IND:
                    case JMP_IND:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        break;
                    }
                    default: {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                }
                break;
            }
            case Estado_3: {
                switch (s_RI.read().to_uint()) {
                    case LDA_INM: case ADD_INM: case SUB_INM:
                    case AND_INM: case ORA_INM: case STA_ABS:
                    case LDA_ABS: case AND_ABS: case SUB_ABS:
                    case ORA_ABS: case ADD_ABS: case JMP_ABS:
                    case PLA_ACU:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                    case INP_IO: {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        v_addr_ports = dat_t_i.read().to_int();
                        cout << "v_addr_ports_INP: " << v_addr_ports << endl;
                        v_data_ports = port_data[v_addr_ports];
                        cout << "v_data_ports_INP: " << v_data_ports << endl;
                        break;
                    }
                    case OUT_IO: {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        v_addr_ports = dat_t_i.read().to_int();
                        cout << "v_addr_ports_OUT: " << v_addr_ports << endl;
                        port_data[v_addr_ports] = acum_t_o ;
                        cout << "v_data_ports_OUT: " << v_data_ports << endl;
                        break;
                    }

                    case BCC_REL: case BCS_REL: case BEQ_REL:
                    case BNE_REL: case BMI_REL: case BPL_REL:
                    case BVC_REL: case BVS_REL:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        addr_t_o = addr_t_o;
                        break;
                    }
                    case STA_IND: case LDA_IND: case AND_IND:
                    case SUB_IND: case ORA_IND: case ADD_IND:
                    case JMP_IND: case RTS_CTR: case RTI_CTR:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                    default: {
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        s_PB = s_PB;
                        break;
                    }
                }
                break;
            }
            case Estado_4: {
                switch (s_RI.read().to_uint()) {
                    case LDA_ABS: case STA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    case JMP_ABS:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        v_PB = dat_t_i.read().to_int();
                        s_PB = v_PB;
                        break;
                    }
                    case INP_IO:{

                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;

//                        v_addr_ports = dat_t_i.read().to_int();
//                        v_data_ports = port_data[v_addr_ports];

                        break;
                    }
                    case OUT_IO:{

                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;

                        v_addr_ports = dat_t_i.read().to_int();

                    break;
                    }
                    case BCC_REL: case BCS_REL: case BEQ_REL:
                    case BNE_REL: case BMI_REL: case BPL_REL:
                    case BVC_REL: case BVS_REL:{
                        switch (s_RI.read().to_uint()) {
                            case BCC_REL: {
                                cout << "BCC_REL v_S_read[0]: " << v_S_read[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[0] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[0] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BCS_REL: {
                                cout << "BCS_REL v_S_read[0]: " << v_S_read[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[0] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[0] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BEQ_REL: {
                                cout << "BEQ_REL v_S_read[1]: " << v_S_read[1] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[1] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[1] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BNE_REL: {
                                cout << "BNE_REL v_S_read[1]: " << v_S_read[1] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[1] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[1] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BMI_REL: {
                                cout << "BMI_REL v_S_read[5]: " << v_S_read[5] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[5] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[5] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BPL_REL: {
                                cout << "BPL_REL v_S_read[5]: " << v_S_read[5] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[5] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[5] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BVC_REL: {
                                cout << "BVC_REL v_S_read[3]: " << v_S_read[3] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[3] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[3] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BVS_REL: {
                                cout << "BVS_REL v_S_read[3]: " << v_S_read[3]  << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[3] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[3] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case LDA_IND: case ADD_IND: case SUB_IND:
                    case AND_IND: case ORA_IND: case STA_IND:
                    case JMP_IND:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        v_PB = dat_t_i.read().to_int();
                        s_PB = v_PB;
                        break;
                    }
                    default: {
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        s_PB = s_PB;
                        break;
                    }
                }
                break;
            }
            case Estado_5: {
                switch (s_RI.read().to_uint()) {
                    case LDA_ABS: case STA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
//                        addr_ports_t_o = addr_ports_t_o;
                        break;
                    }
                    case LDA_IND: case ADD_IND: case SUB_IND:
                    case AND_IND: case ORA_IND: case STA_IND:
                    case JMP_IND:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                    default:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        s_PB = s_PB;
                        break;
                    }
                }
                break;
            }
            case Estado_6: {
                switch (s_RI.read().to_uint()) {
                    case LDA_ABS: case STA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    {
                        cout << "s_RI.read().to_uint(): "<< s_RI.read().to_uint() << endl;
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_PA = dat_t_i.read().to_int();
                        //v_PB = s_PB;
                        cout << "v_PA: "<< v_PA <<" v_PB: "<< v_PB << endl;
                        v_addr = (v_PA,v_PB);
                        cout << "v_addr: "<< v_addr << endl;
                        cout << "dat_t_i: "<< dat_t_i << endl;
                        addr_t_o = v_addr;
                        break;
                    }
                    case LDA_IND: case ADD_IND: case SUB_IND:
                    case AND_IND: case ORA_IND: case STA_IND:
                    case JMP_IND:{
                        cout << "s_RI.read().to_uint(): "<< s_RI.read().to_uint() << endl;
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_PA = dat_t_i.read().to_int();
                        //v_PB = s_PB;
                        cout << "v_PA: "<< v_PA <<" v_PB: "<< v_PB << endl;
                        v_addr = (v_PA,v_PB);
                        cout << "v_addr: "<< v_addr << endl;
                        cout << "dat_t_i: "<< dat_t_i << endl;
                        addr_t_o = v_addr;
                        break;
                    }

                    default:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                }
                break;
            }
            case Estado_7: {
                switch (s_RI.read().to_uint()) {
                    case LDA_ABS: case STA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                    default:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                }
                break;
            }
            case Estado_8: {
                switch (s_RI.read().to_uint()) {
                    case LDA_ABS: case STA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS: {
                        pc_t_o = pc_t_o;
                        v_addr = pc_t_o;
                        addr_t_o = pc_t_o;
                        break;
                    }
                    case LDA_IND: case ADD_IND: case SUB_IND:
                    case AND_IND: case ORA_IND: case STA_IND:
                    case JMP_IND:{
                        pc_t_o = pc_t_o;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        v_PB = dat_t_i.read().to_int();
                        s_PB = v_PB;
                        break;
                    }
                    default:{
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
                        break;
                    }
                }
                break;
            }
            case Estado_9: {
                pc_t_o = pc_t_o;
                addr_t_o = addr_t_o;
                break;
            }
            case Estado_10: {
                switch (s_RI.read().to_uint()) {
                    case JSR_IND: case JSR_ABS: {
                        v_PA = dat_t_i.read().to_int();
                        //v_PB = s_PB;
                        v_PC = (v_PA,v_PB);
                        pc_t_o = pc_t_o;
                        v_addr = (v_PA,v_PB);
                        addr_t_o = v_addr;
                        break;
                    }
                    default:{
                        pc_t_o = pc_t_o;
                        //v_PB = s_PB;
                        v_PA = dat_t_i.read().to_int();
                        cout << "v_PA: "<< v_PA <<" v_PB: "<< v_PB << endl;
                        v_addr = (v_PA,v_PB);
                        cout << "v_addr: "<< v_addr << endl;
                        cout << "dat_t_i: "<< dat_t_i << endl;
                        addr_t_o = v_addr;
                        break;
                    }
                }
                break;
            }
            case Estado_11: {
                pc_t_o = pc_t_o;
                addr_t_o = addr_t_o;
                break;
            }
            case Estado_12: {
                switch (s_RI.read().to_uint()) {
                    case JSR_IND: {
                        pc_t_o = pc_t_o;
                        v_addr = v_addr + 1;
                        addr_t_o = v_addr;
                        v_PB = dat_t_i.read().to_int();
                        s_PB = v_PB;
                        break;
                    }
                    default:{
                        s_PB = s_PB;
                        pc_t_o = pc_t_o;
                        v_addr = pc_t_o;
                        addr_t_o = pc_t_o;
                        break;
                    }
                }
                break;
            }
            default: {
//                v_PC = 0;
//                pc_t_o = pc_t_o;
//                v_addr = 0;
//                addr_t_o = v_addr;
                pc_t_o = pc_t_o;
                pc_t_o = pc_t_o;
                v_addr = addr_t_o;
                addr_t_o = addr_t_o;
                break;
            }
        }
    }
}

void  transactor::p_P() {
/** Proceso que actualiza el puntero de pila.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param addr_t_o - addr_t_o puerto que contiene la direccion de memoria accesada.
 * @param pc_t_o - pc_t_o puerto que contiene el contador de posicion PC.
 * @param s_RI - s_RI variable que contiene el codigo de instruccion leido.
 * @param s_CB - s_CB señal de ciclo de busqueda.
 * @param ri_t_o - ri_t_o puerto que contiene el codigo de instruccion leido.
 */
    if (!rps_t_i){
        v_PP = 0;
        s_PP = v_PP;
    }
    else{
        switch (s_est_pres) {
            case Estado_1:{
                switch (s_RI.read().to_uint()){
                    case TAP_CTR:{
                        s_PP = acum_t_o.read().to_uint();
                        break;
                    }
                    default:{
                        s_PP = s_PP;
                        break;
                    }

                }
                break;
            }
            case Estado_2:{
                switch (s_RI.read().to_uint()){
                    case TAP_CTR:{
                        s_PP = acum_t_o.read().to_uint();
                        break;
                    }
                    case RTS_CTR: case RTI_CTR:{
                        v_PP = v_PP - acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    default:{
                        s_PP = s_PP;
                        break;
                    }
                }
                break;
            }
            case Estado_3:{
                switch (s_RI.read().to_uint()){
                    case JSR_ABS:{
                        v_PP = v_PP + acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    case RTS_CTR:{
                        v_PP = v_PP - acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    default:{
                        s_PP = s_PP;
                        break;
                    }
                }
                break;
            }
            case Estado_4:{
                switch (s_RI.read().to_uint()){
                    case PHA_ACU: case PHS_CTR:{
                        v_PP = v_PP + acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    case PLS_CTR: case PLA_ACU: case RTI_CTR:{
                        v_PP = v_PP - acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    default:{
                        s_PP = s_PP;
                        break;
                    }
                }
                break;
            }
            case Estado_6:{
                switch (s_RI.read().to_uint()){
                    case JSR_ABS:{
                        v_PP = v_PP + acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    case RTS_CTR:{
                        v_PP = v_PP - acum_t_o.read().to_uint();
                        s_PP = v_PP;
                        break;
                    }
                    default:{
                        s_PP = s_PP;
                        break;
                    }
                }
                break;
            }
            case Estado_18:{
                v_PP = v_PP + acum_t_o.read().to_uint();
                s_PP = v_PP;
                break;
            }
            case Estado_21:{
                v_PP = v_PP + acum_t_o.read().to_uint();
                s_PP = v_PP;
                break;
            }
            default:{
                s_PP = s_PP;
                break;
            }
        }
    }

}
void  transactor::p_RI() {
/** Proceso que obtiene el codigo de operacion de la instruccion a ejecutar.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param addr_t_o - addr_t_o puerto que contiene la direccion de memoria accesada.
 * @param pc_t_o - pc_t_o puerto que contiene el contador de posicion PC.
 * @param s_RI - s_RI variable que contiene el codigo de instruccion leido.
 * @param s_CB - s_CB señal de ciclo de busqueda.
 * @param ri_t_o - ri_t_o puerto que contiene el codigo de instruccion leido.
 */
    if (rps_t_i){
        if (s_CB){
            v_RI = dat_t_i.read().to_int(); /**< Se hace fetch de la memoria
            * del codigo de instruccion */
            s_RI = v_RI; /**< Se guarda el valor en una sc_signal */
            ri_t_o = v_RI; /**< Se escribe al puerto de registro de instruccion */
        }
        else{
            s_RI = s_RI;  /**< Si no es ciclo de busqueda se mantienen los valores */
            v_RI = v_RI;
            ri_t_o = v_RI;
        }
    }
    else{
        v_RI = 0; /**< Si RPS es 0 se asigna 0 al registro de instruccion */
        s_RI = 0;
        ri_t_o = v_RI;
    }
}

void  transactor::p_est_pres() {
/** Proceso que calcula el estado presente.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente
 */

    if (rps_t_i){
        s_est_pres = s_est_prox; /**< Estado presente es proximo estado
 * cuando proximo es actualizado */
    }
    else{
        s_est_pres = Estado_0; /**< Si RPS es 0 estado presente es 0; se reinicia la FSM */
    }
}

void  transactor::p_est_prox() {
/** Proceso que calcula el proximo estado y ejecuta la instruccion respectiva.
 * @param rps_t_i - rps_t_i señal de reposicion.
 * @param s_est_prox - s_est_prox variable que contiene el proximo estado.
 * @param s_est_pres - s_est_pres variable que contiene el estado presente.
 * @param addr_t_o - addr_t_o puerto que contiene la direccion de memoria accesada.
 * @param pc_t_o - pc_t_o puerto que contiene el contador de posicion PC.
 * @param s_RI - s_RI variable que contiene el codigo de instruccion leido.
 * @param s_CB - s_CB señal de ciclo de busqueda.
 */
    if (!rps_t_i){
        s_est_prox = Estado_1;
        acum_t_o = v_A;
    }
    else{
        switch (s_est_pres) {
            case Estado_0:
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_0 << "]|" << endl;
                s_est_prox = Estado_1;
                // Calculo de banderas.
                v_bi_t = 1;
                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                s_t_o = v_S;
                // Fin de calculo de banderas.
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            case Estado_1:
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_1 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_2;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            case Estado_2:{
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_2 << "]|" << endl;
                cout << "==================================================================" << endl;
                cout << "PC actual: " << "|[" << pc_t_o << "]|" <<endl;
                switch (s_RI.read().to_uint()){
                    case TAP_CTR: case TPA_CTR: case CLA_ACU:
                    case INA_ACU: case DCA_ACU: case ROL_ACU:
                    case ROR_ACU: case CLC_IMP: case SEC_IMP:
                    case SEI_IMP: case CLI_IMP: case NOP_CTR:
                    case CPA_ACU:{// Inicio switch inst 1 palabra/
                        switch (s_RI.read().to_uint()) {
                            case TAP_CTR:
                                cout << "Instruccion TAP_CTR RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                break;
                            case TPA_CTR:
                                cout << "Instruccion TPA_CTR RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                break;
                            case CLA_ACU:
                                cout << "Instruccion INA_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Colocar el acumulador en 0.
                                v_A = 0;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case INA_ACU:
                                cout << "Instruccion INA_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Incrementar acumulador en 1 y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A + 1;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t? 0:v_A[5]; // Bandera V para INA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case DCA_ACU:
                                cout << "Instruccion DCA_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Incrementar acumulador en 1 y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A - 1;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t? not v_A[5]: 1; // Bandera V para DCA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case ROL_ACU:
                                cout << "Instruccion ROL_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Incrementar acumulador en 1 y actualizar BC.
                                v_bt2_t = v_A[5];
                                // Rotacion hacia la izquierda.
                                v_A = (v_A[4],v_A[3],v_A[2],v_A[1],v_A[0],v_bc_t);
                                // Acutalizacion de la bandera BC.
                                v_bc_t = v_bt2_t;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case ROR_ACU:
                                cout << "Instruccion ROR_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Incrementar acumulador en 1 y actualizar BC.
                                v_bt2_t = v_A[0];
                                // Rotacion hacia la derecha.
                                v_A = (v_bc_t, v_A[5],v_A[4],v_A[3],v_A[2],v_A[1]);
                                // Acutalizacion de la bandera BC.
                                v_bc_t = v_bt2_t;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case CLC_IMP:
                                cout << "Instruccion CLC_IMP RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Poner en bajo la bandera de acarreo BC.
                                // Calculo de banderas.
                                v_bc_t = 0;
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case SEC_IMP:
                                cout << "Instruccion SEC_IMP RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Poner en alto la bandera de acarreo BC.
                                // Calculo de banderas.
                                v_bc_t = 1;
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case SEI_IMP:
                                cout << "Instruccion SEI_IMP RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Poner en alto la bandera de interrupcion BI.
                                // Calculo de banderas.
                                v_bi_t = 1;
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case CLI_IMP:
                                cout << "Instruccion CLI_IMP RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Poner en bajo la bandera de interrupcion BI.
                                // Calculo de banderas.
                                v_bi_t = 0;
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case CPA_ACU:
                                cout << "Instruccion CPA_ACU RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Complementar el acumulador.
                                v_A = ~v_A;
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case NOP_CTR:
                                cout << "Instruccion NOP_CTR RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                break;
                            default:
                                cout << "RI Invalido: Default " << "|[" << s_RI  << "]|" << endl;
                                sc_stop();
                                break;
                        }
                        break;
                    }// Fin switch inst 1 palabra/
                    case LDA_INM: case ADD_INM: case SUB_INM:
                    case AND_INM: case ORA_INM: case BCC_REL:
                    case BCS_REL: case BEQ_REL: case BNE_REL:
                    case BMI_REL: case BPL_REL: case PHA_ACU:
                    case PLS_CTR: case BVC_REL: case BVS_REL:{// Inicio switch inst 2 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_3;
                        break;
                    }// Fin switch inst 2 palabras.
                    case STA_ABS: case LDA_ABS: case AND_ABS:
                    case SUB_ABS: case ORA_ABS: case ADD_ABS:
                    case JMP_ABS: case PLA_ACU: case PHS_CTR:
                    case JSR_ABS: case JSR_IND: case INP_IO:
                    case OUT_IO:{// Inicio switch inst 3 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_3;
                        break;
                    }// Fin switch inst 3 palabras.
                    case STA_IND: case LDA_IND: case AND_IND:
                    case SUB_IND: case ORA_IND: case ADD_IND:
                    case JMP_IND: case RTS_CTR: case RTI_CTR:{// Inicio switch inst 3 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_3;
                        break;
                    }// Fin switch inst 3 palabras.
                    case HLT_CTR:{// Inicio switch inst HLT.
                        cout << "Instruccion HLT_CTR RI: " << "|[" << s_RI << "]|" << endl;
                        s_est_prox = Estado_30;
                        break;
                    }// Fin switch inst HLT.
                    default: {
                        cout << "RI Invalido: Default " << "|[" << s_RI << "]|" << endl;
                        s_est_prox = Estado_31;
                        break;
                    }
                }
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_3: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_3 << "]|" << endl;
                cout << "==================================================================" << endl;

                s_est_prox = Estado_4;

                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_4: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_4 << "]|" << endl;
                cout << "==================================================================" << endl;
                switch (s_RI.read().to_uint()) {

                    case LDA_INM: case ADD_INM: case SUB_INM:
                    case AND_INM: case ORA_INM: case PHA_ACU:
                    case PLS_CTR:{// Inicio switch inst 2 palabras.
                        switch (s_RI.read().to_uint()){
                            case LDA_INM:
                                cout << "Instruccion LDA_INM RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Cargar valor de memoria en acumulador.
                                v_A = dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case ADD_INM:
                                cout << "Instruccion ADD_INM RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                v_A = acum_t_o;
                                // Sumar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A + dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_bv_t = v_bt1_t ? 0 : v_A[5]; // Bandera V para INA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case SUB_INM:
                                cout << "Instruccion SUB_INM RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                v_A = acum_t_o;
                                // Restar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A - dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t ? not v_A[5] : 1; // Bandera V para DCA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case AND_INM:
                                cout << "Instruccion AND_INM RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                v_A = acum_t_o;
                                // Operacion logica AND bit a bit entre acumulador y argumento.
                                v_A = v_A & dat_t_i.read().to_int();
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                cout << "acum_t_o: " << acum_t_o << endl;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            case ORA_INM:
                                cout << "Instruccion ORA_INM RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                v_A = acum_t_o;
                                // Operacion logica OR bit a bit entre acumulador y argumento.
                                v_A = v_A | dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                        }
                        break;
                    }// Fin switch inst 2 palabras.

                    case INP_IO:{
                        cout << "Instruccion INP_IO RI: " << "|[" << s_RI << "]|" << endl;
                        // Actualizar proximo estado.
                        s_est_prox = Estado_1;
                        // Cargar valor de memoria en acumulador.
                        v_A = v_data_ports;
                        cout << "v_A: " << v_A << endl;
                        //Actualizacion del acumulador.
                        acum_t_o = v_A;
                        // Calculo de banderas.
                        v_bn_t = v_A[5];
                        v_bz_t = v_A.nor_reduce();
                        v_S = (v_bn_t, "1", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                        s_t_o = v_S;
                        // Fin de calculo de banderas.
                        break;
                    }
                    case OUT_IO:{
                        cout << "Instruccion OUT_IO RI: " << "|[" << s_RI << "]|" << endl;
                        // Actualizar proximo estado.
                        s_est_prox = Estado_1;
                        //Actualizacion de los puertos.
//                        ports_t_o = acum_t_o;
                        break;
                    }

//                    case INP_IO:{
//                        cout << "Instruccion INP_IO RI: " << "|[" << s_RI << "]|" << endl;
//                        // Actualizar proximo estado.
//                        s_est_prox = Estado_5;
//                        // Cargar valor de memoria en acumulador.
//                        //dat_t_o = ports_t_i.read().to_int();
//                        break;
//                    }
//
////                    case OUT_IO:{
////                        cout << "Instruccion OUT_IO RI: " << "|[" << s_RI << "]|" << endl;
////                        // Actualizar proximo estado.
////                        s_est_prox = Estado_1;
////                        //Actualizacion de los puertos.
////                        ports_t_o = acum_t_o;
////                        break;
////                    }
                    case STA_ABS: case LDA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    case JMP_ABS: case JSR_ABS: case JSR_IND:
                    case RTS_CTR:{// Inicio switch inst 3 palabras.
                        s_est_prox = Estado_5;
                        break;
                    }// Fin switch inst 3 palabras.
                    case STA_IND: case LDA_IND: case AND_IND:
                    case SUB_IND: case ORA_IND: case ADD_IND:
                    case JMP_IND: case RTI_CTR:{// Inicio switch inst 3 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_5;
                        break;
                    }// Fin switch inst 3 palabras.
                    default: {
                        // Proximo estado 1. Termina instruccion.
                        s_est_prox = Estado_1;
                        acum_t_o = acum_t_o;
                        break;
                    }
                }
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_5: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_5 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_6;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_6: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_6 << "]|" << endl;
                cout << "==================================================================" << endl;
                switch (s_RI.read().to_uint()) {
                    case JMP_ABS: case RTS_CTR: case RTI_CTR:{
                        switch (s_RI.read().to_uint()) {
//                            case INP_IO:{
//                                cout << "Instruccion INP_IO RI: " << "|[" << s_RI << "]|" << endl;
//                                // Actualizar proximo estado.
//                                s_est_prox = Estado_1;
//                                // Cargar valor de memoria en acumulador.
//                                v_A = ports_t_i.read().to_int();
//                                //Actualizacion del acumulador.
//                                acum_t_o = v_A;
//                                // Calculo de banderas.
//                                v_bn_t = v_A[5];
//                                v_bz_t = v_A.nor_reduce();
//                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//                                s_t_o = v_S;
//                                // Fin de calculo de banderas.
//                                break;
//                            }
//                            case OUT_IO:{
//                                cout << "Instruccion OUT_IO RI: " << "|[" << s_RI << "]|" << endl;
//                                // Actualizar proximo estado.
//                                s_est_prox = Estado_1;
//                                //Actualizacion de los puertos.
//                                ports_t_o = acum_t_o;
//                                break;
//                            }

                            default:{
                                s_est_prox = Estado_1;
                                break;
                            }
                        }
                        break;

                    }
//                    case INP_IO:{
//                        cout << "Instruccion INP_IO RI: " << "|[" << s_RI << "]|" << endl;
//                        // Actualizar proximo estado.
//                        s_est_prox = Estado_1;
//                        // Cargar valor de memoria en acumulador.
//
////                        cout << "Puerto Dato leido: " <<port_data_write << endl;
//                        v_A = v_data_ports;
//
//                        cout << "v_A: " << v_A << endl;
////                        cout << "ports_t_i.read().: " << ports_t_i.read() << endl;
//                        //Actualizacion del acumulador.
//                        acum_t_o = v_A;
//
//                        // Calculo de banderas.
//                        v_bn_t = v_A[5];
//                        v_bz_t = v_A.nor_reduce();
//                        v_S = (v_bn_t, "1", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//                        s_t_o = v_S;
//                        // Fin de calculo de banderas.
//                        break;
//                    }
//                    case OUT_IO:{
//                        cout << "Instruccion OUT_IO RI: " << "|[" << s_RI << "]|" << endl;
//                        // Actualizar proximo estado.
//                        s_est_prox = Estado_1;
//                        //Actualizacion de los puertos.
////                        ports_t_o = acum_t_o;
//                        break;
//                    }
                    default: {
                        s_est_prox = Estado_7;
                        break;
                    }
                }
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_7: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_7 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_8;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_8: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_8 << "]|" << endl;
                cout << "==================================================================" << endl;
                switch (s_RI.read().to_uint()){
                    case STA_ABS: case LDA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    case JMP_ABS:{
                        switch (s_RI.read().to_uint()){
                            case STA_ABS: {
                                cout << "Instruccion STA_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Cargar valor de memoria en acumulador.
                                cout << "acum_t_o: "<< acum_t_o << endl;
                                //Actualizacion del acumulador.
                                dat_t_o = acum_t_o;
                                break;
                            }
                            case LDA_ABS: {
                                cout << "Instruccion LDA_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Cargar valor de memoria en acumulador.
                                cout << "dat_t_i: "<< dat_t_i << endl;
                                v_A = dat_t_i.read().to_int();
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case ADD_ABS:{
                                cout << "Instruccion ADD_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Sumar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A + dat_t_i.read().to_int();
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t ? 0 : v_A[5]; // Bandera V para INA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case SUB_ABS:{
                                cout << "Instruccion SUB_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Restar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A - dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t ? not v_A[5] : 1; // Bandera V para DCA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case AND_ABS:{
                                cout << "Instruccion AND_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Operacion logica AND bit a bit entre acumulador y argumento.
                                v_A = v_A & dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case ORA_ABS:{
                                cout << "Instruccion ORA_ABS RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Operacion logica OR bit a bit entre acumulador y argumento.
                                v_A = v_A | dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            default:{
                                s_est_prox = Estado_1;
                                break;
                            }
                        }
                        break;
                    }
                    case STA_IND: case LDA_IND: case AND_IND:
                    case SUB_IND: case ORA_IND: case ADD_IND:
                    case JMP_IND:{// Inicio switch inst 3 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_9;
                        break;
                    }// Fin switch inst 3 palabras.
                    case JSR_ABS: case JSR_IND:{// Inicio switch inst 3 palabras.
                        // Actualizar proximo estado.
                        s_est_prox = Estado_9;
                        break;
                    }// Fin switch inst 3 palabras.
                    default:{
                        s_est_prox = Estado_1;
                        break;
                    }
                }
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_9: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_9 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_10;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_10: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_10 << "]|" << endl;
                cout << "==================================================================" << endl;
                switch (s_RI.read().to_uint()){
                    case JMP_IND: case JSR_ABS:{
                        s_est_prox = Estado_1;
                        break;
                    }
                    default:{
                        s_est_prox = Estado_11;
                        break;
                    }
                }
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_11: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_11 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_12;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_12: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_12 << "]|" << endl;
                cout << "==================================================================" << endl;
                switch (s_RI.read().to_uint()){
                    case STA_IND: case LDA_IND: case ADD_IND:
                    case SUB_IND: case AND_IND: case ORA_IND:
                    case JMP_IND: {
                        switch (s_RI.read().to_uint()){
                            case STA_IND: {
                                cout << "Instruccion STA_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Cargar valor de memoria en acumulador.
                                cout << "acum_t_o: "<< acum_t_o << endl;
                                //Actualizacion del acumulador.
                                dat_t_o = acum_t_o;
                                break;
                            }
                            case LDA_IND: {
                                cout << "Instruccion LDA_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Cargar valor de memoria en acumulador.
                                cout << "dat_t_i: "<< dat_t_i << endl;
                                v_A = dat_t_i.read().to_int();
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case ADD_IND:{
                                cout << "Instruccion ADD_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Sumar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A + dat_t_i.read().to_int();
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t ? 0 : v_A[5]; // Bandera V para INA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case SUB_IND:{
                                cout << "Instruccion SUB_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Restar al acumulador el argumento y actualizar BC.
                                v_bt1_t = v_A[5];
                                (v_bc_t, v_A) = v_A - dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                s_bv_t = v_bt1_t ? not v_A[5] : 1; // Bandera V para DCA.
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case AND_IND:{
                                cout << "Instruccion AND_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Operacion logica AND bit a bit entre acumulador y argumento.
                                v_A = v_A & dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            case ORA_IND:{
                                cout << "Instruccion ORA_IND RI: " << "|[" << s_RI << "]|" << endl;
                                // Actualizar proximo estado.
                                s_est_prox = Estado_1;
                                // Operacion logica OR bit a bit entre acumulador y argumento.
                                v_A = v_A | dat_t_i.read().to_int();
                                s_A = v_A;
                                //Actualizacion del acumulador.
                                acum_t_o = v_A;
                                // Calculo de banderas.
                                v_bn_t = v_A[5];
                                v_bz_t = v_A.nor_reduce();
                                v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                                s_t_o = v_S;
                                // Fin de calculo de banderas.
                                break;
                            }
                            default:{
                                s_est_prox = Estado_1;
                                break;
                            }
                        }
                        break;
                    }
                    case JSR_IND:{
                        s_est_prox = Estado_13;
                        break;
                    }
                    default:{
                        s_est_prox = Estado_1;
                        break;
                    }
                }

                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_13: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_13 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_14;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_14: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_14 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_1;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_30: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_30 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_30;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            case Estado_31: {
                cout << "\n##################################################################" << endl;
                cout << "======================INICIO DE ESTADO============================" << endl;
                cout << "Estado actual: " << "|[" << Estado_31 << "]|" << endl;
                cout << "==================================================================" << endl;
                s_est_prox = Estado_31;
                cout << "=======================FIN DE ESTADO==============================" << endl;
                cout << "##################################################################\n" << endl;
                break;
            }
            default: {
                cout << "Estado actual: " << "|[" << "default" << "]|" << endl;
                s_est_prox = Estado_0;
                break;
            }
        }
    }
}