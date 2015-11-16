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

void  transactor::p_CB() {
    i1++;
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
    i2++;
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
                    case JSR_ABS: case OUT_IO:{
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
    i3++;
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
                    case JMP_IND: case RTS_CTR: case RTI_CTR:
                    case INP_IO: case OUT_IO:{
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
                    case INP_IO: case OUT_IO:{
                        v_PC = v_PC + 1;
                        pc_t_o = v_PC;
                        v_addr = dat_t_i.read().to_int();
                        addr_t_o = v_addr;
                        break;
                    }
                    case BCC_REL: case BCS_REL: case BEQ_REL:
                    case BNE_REL: case BMI_REL: case BPL_REL:
                    case BVC_REL: case BVS_REL:{
                        switch (s_RI.read().to_uint()) {
                            case BCC_REL: {
                                cout << "BCC_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[0] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[0] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BCS_REL: {
                                cout << "BCS_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[0] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[0] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BEQ_REL: {
                                cout << "BEQ_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[1] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[1] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BNE_REL: {
                                cout << "BNE_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[1] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[1] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BMI_REL: {
                                cout << "BMI_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[5] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[5] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BPL_REL: {
                                cout << "BPL_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[5] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[5] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BVC_REL: {
                                cout << "BVC_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[3] == 1) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[3] == 0) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    v_addr = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
                                    addr_t_o = v_addr;
                                }
                                break;
                            }
                            case BVS_REL: {
                                cout << "BVS_REL s_t_o[0]: " << s_t_o[0] << endl;
                                v_S_read = s_t_o;
                                if (v_S_read[3] == 0) {
                                    pc_t_o = pc_t_o;
                                    v_addr = v_addr + 1;
                                    addr_t_o = v_addr;
                                }
                                else if (v_S_read[3] == 1) {
                                    v_PC = pc_t_o.read().to_int() + dat_t_i.read().to_int();
                                    pc_t_o = v_PC;
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
                    case INP_IO: case OUT_IO: {
                        pc_t_o = pc_t_o;
                        addr_t_o = addr_t_o;
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
                    case INP_IO: case OUT_IO:{
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
                        pc_t_o = pc_t_o;
                        addr_t_o = pc_t_o;
                        s_PB = s_PB;
                        break;
                    }
                }
                break;
            }
            default: {
                v_PC = 0;
                pc_t_o = v_PC;
                v_addr = 0;
                addr_t_o = v_addr;
                break;
            }
        }
    }
}

void  transactor::p_RI() {
    i4++;
    if (rps_t_i){
        if (s_CB){
            v_RI = dat_t_i.read().to_int();
            s_RI = v_RI;
            ri_t_o = v_RI;
        }
        else{
            s_RI = s_RI;
            v_RI = v_RI;
            ri_t_o = v_RI;
        }
    }
    else{
        v_RI = 0;
        s_RI = 0;
        ri_t_o = v_RI;
    }
}

void  transactor::p_est_pres() {
    i5++;
    if (rps_t_i){
        s_est_pres = s_est_prox;
    }
    else{
        s_est_pres = Estado_0;
    }
}

void  transactor::p_est_prox() {
    i6++;
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
                        sc_stop();
                        break;
                    }// Fin switch inst HLT.
                    default: {
                        cout << "RI Invalido: Default " << "|[" << s_RI << "]|" << endl;
                        sc_stop();
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
                    case AND_INM: case ORA_INM: case BCC_REL:
                    case BCS_REL: case BEQ_REL: case BNE_REL:
                    case BMI_REL: case BPL_REL: case PHA_ACU:
                    case PLS_CTR: case BVC_REL: case BVS_REL:{// Inicio switch inst 2 palabras.
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
                                s_bv_t = v_bt1_t ? 0 : v_A[5]; // Bandera V para INA.
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
                    case STA_ABS: case LDA_ABS: case ADD_ABS:
                    case SUB_ABS: case AND_ABS: case ORA_ABS:
                    case JMP_ABS: case JSR_ABS: case JSR_IND:
                    case RTS_CTR: case INP_IO: case OUT_IO:{// Inicio switch inst 3 palabras.
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
//                    case JMP_ABS: case RTS_CTR: case INP_IO:
//                    case OUT_IO: case RTI_CTR:{
//                        switch (s_RI.read().to_uint()) {
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
//                                cout << "Instruccion INP_IO RI: " << "|[" << s_RI << "]|" << endl;
//                                // Actualizar proximo estado.
//                                s_est_prox = Estado_1;
//                                //Actualizacion de los puertos.
//                                ports_t_o = acum_t_o;
//                                break;
//                            }
//                            default:{
//                                s_est_prox = Estado_1;
//                                break;
//                            }
//                        }
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
                                cout << "Instruccion LDA_ABS RI: " << "|[" << s_RI << "]|" << endl;
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
                                cout << "Instruccion LDA_IND RI: " << "|[" << s_RI << "]|" << endl;
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
            default: {
                cout << "Estado actual: " << "|[" << "default" << "]|" << endl;
                s_est_prox = Estado_0;
                break;
            }
        }
    }
}

//            case Estado_9: {
//                pc_t_o = pc_t_o;
//                addr_t_o = addr_t_o;
//                break;
//            }
//            case Estado_10: {
//                pc_t_o = pc_t_o;
//                v_addr = dat_t_i.read().to_int();
//                v_addr = (v_addr,v_PB);
//                addr_t_o = v_addr;
//                break;
//            }

//void  transactor::p_acum_a() {
//    i7++;
//    cout << "@ |[" << sc_time_stamp() << " ]| "<< "s_A: " << "|[" << s_A << "]|" << " s_bn_t: " << "|[" << s_bn_t << "]|" <<
//    " s_bv_t: " << "|[" << s_bv_t << "]|" << " s_bi_t: " << "|[" << s_bi_t << "]|" <<
//    " s_bz_t: " << "|[" << s_bz_t << "]|" << " s_bc_t: " << "|[" << s_bc_t << "]|" << "\n" << endl;
//                    cout << "v_A: " << "|[" << v_A << "]|" << " v_bn_t: " << "|[" << v_bn_t << "]|" <<
//                    " v_bv_t: " << "|[" << v_bv_t << "]|" << " v_bi_t: " << "|[" << v_bi_t << "]|" <<
//                    " v_bz_t: " << "|[" << v_bz_t << "]|" << " v_bc_t: " << "|[" << v_bc_t << "]|" << "\n" << endl;

//
//    switch (s_est_pres) {
//        case Estado_0:
//            s_bi_t = 1;
////            s_A = v_A;
////            acum_t_o = v_A;
////
//            // Calculo de bandera Z, con compuerta nor.
////            v_bz_t = v_A.nor_reduce();
//////
////            // Actualizacion de señal de bandera z.
////            s_bz_t = v_bz_t;
////            // Calculo de bandera N, con el MSB de A.
////            v_bn_t = v_A[5];
////            // Actualizacion de señal de bandera N.
////            s_bn_t = v_bn_t;
////            v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
////            s_t_o = v_S;
//            break;
//        case Estado_1:
////            s_A = s_A;
////            acum_t_o = acum_t_o;
//            //v_A = v_A;
//            // Calculo de bandera Z, con compuerta nor.
//            v_bz_t = v_A.nor_reduce();
////            cout << "v_bz_t " << v_bz_t << endl;
//            // Actualizacion de señal de bandera z. // valor se queda revisar
//            s_bz_t = v_bz_t;
//            // Calculo de bandera N, con el MSB de A.
//            v_bn_t = v_A[5];
//            // Actualizacion de señal de bandera N.
//            s_bn_t = v_bn_t;
//            v_bt1_t = v_A[5];
//            if (v_RI == DCA_ACU){
//                s_bv_t = v_bt1_t? ~v_A[5]:1;
//            }
//            if(v_RI == INA_ACU){
//                v_bv_t = v_bt1_t? 1:v_A[5];
//                s_bv_t = v_bt1_t? 1:v_A[5];
//            }
//            v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//            s_t_o = v_S;
//        case Estado_2:
//            switch (s_RI.read().to_uint()){
//                case CLA_ACU:
//                    v_A = 0;
//                    s_A  = 0;
//                    acum_t_o = v_A;
//                    // Calculo de bandera Z, con compuerta nor.
//                    v_bz_t = v_A.nor_reduce();
////                    cout << "v_bz_t " << v_bz_t << endl;
//                    // Actualizacion de señal de bandera z.
//                    s_bz_t = v_bz_t;
//                    // Calculo de bandera N, con el MSB de A.
//                    v_bn_t = v_A[5];
//                    // Actualizacion de señal de bandera N.
//                    s_bn_t = v_bn_t;
//                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//                    s_t_o = v_S;
//                    break;
//                case INA_ACU:
//                    cout << "INA pc_t_o!!!!!!!!!: " << pc_t_o <<endl;
//                    (v_bc_t, v_A) = v_A + 1;
//                    s_bc_t = v_bc_t;
//                    s_A = v_A;
//                    cout << "v_A: " << v_A << endl;
//                    acum_t_o = v_A;
//                    // Calculo de bandera Z, con compuerta nor.
//                    v_bz_t = v_A.nor_reduce();
////                    cout << "v_bz_t " << v_bz_t << endl;
//                    // Actualizacion de señal de bandera z.
//                    s_bz_t = v_bz_t;
//                    // Calculo de bandera N, con el MSB de A.
//                    v_bn_t = v_A[5];
//                    // Actualizacion de señal de bandera N.
//                    s_bn_t = v_bn_t;
//                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//                    s_t_o = v_S;
//                    break;
//                case DCA_ACU:
////                    cout << "v_A: " << v_A << endl;
//                    (v_bc_t, v_A) = v_A - 1;
//                    s_bc_t = v_bc_t;
//                    s_A = v_A;
////                    cout << "v_A: " << v_A << endl;
//                    acum_t_o = v_A;
//                    // Calculo de bandera Z, con compuerta nor.
//                    v_bz_t = v_A.nor_reduce();
//                    cout << "v_bz_t " << v_bz_t << endl;
//                    // Actualizacion de señal de bandera z.
//                    s_bz_t = v_bz_t;
//                    // Calculo de bandera N, con el MSB de A.
//                    v_bn_t = v_A[5];
//                    // Actualizacion de señal de bandera N.
//                    s_bn_t = v_bn_t;
//                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
//                    s_t_o = v_S;
//                    break;
//
//                default:
//                    acum_t_o = v_A;
//                    break;
//                   }// end estado switch
//
//        default:
//
//            break;
//    }//end switch acum global
//    cout << "---------------------------Final de p_acum_a---------------------------\n"<< endl;
//}



//    sc_core::event(rps_t_i);

//
   //  // sc_core::next_trigger(500, SC_NS);

   //  // Inicializacion de la direccion de memoria.
   //  // init_t_o.write(0);

   //  // // addr_t_o.write("000000000000");

   //  // sc_core::wait(500,SC_NS);

   //  // init_t_o.write(1);

  	// cout << "Señal de init activa init_c_s: |[" << init_t_o.read() <<"|]" << endl;


    //modo escritura.

    // rw_t_o.write("1");

    //memoria habilitada

    // en_t_o.write("1");

    // Inicializacion del pc.

    // pc_t_o.write("000000000000");

//}

//void transactor::inst_exec() {
//
//    cout << "-------------------------------------------FSM-------------------------------------------" << endl;
//
//
//}
//    cout << "-------------------------------------------Ejecutor-------------------------------------------" << endl;
//
//
//    cout << "------------------------------------------mem_cont:------------------------------------------\n" <<
//    mem_cont << endl;


//    if (rps_t_i) {
//        string addrx = addr_t_o.read().to_string();
//        string dont_carex = "XXXXXXXXXXXX";
//
//        if (stop == false && addrx != dont_carex) {
//
//            // Leer de memoria.
//            rw_t_o.write(0);
//
//            cout << "rw_t_o: " << rw_t_o << endl;
//
//            // Habilitar memoria.
//            en_t_o.write(1);
//
//            cout << "en_t_o: " << en_t_o << endl;
//
//            // Direccion a leer.
//
//            cout << "mem_cont: " << mem_cont << endl;
//
//            addr_t_o.write(mem_cont);
//
//            cout << "addr_t_o: " << addr_t_o << endl;
//
//            // Ciclo de memoria.
//            mem_data_dec = dat_t_i.read().to_uint();
//
//            mem_data_str = to_string(mem_data_dec);
//
//
//            cout << "!!!!!Mem pos data:!!!!! " << mem_data_dec << endl;
//
//
//            if (fetched == false) {
//
//
//                ri_mem = mem_data_dec;
//
//                addr_mod_str = bitset<6>(ri_mem).to_string();
//
//                cout << "Fetched opcode: " << addr_mod_str << endl;
//
//                //            cout << "ri_mem_bin: " << addr_mod_str << endl;
//
//                addr_mod_str = addr_mod_str.substr(3, 3);
//
//                addr_mod_int = stoi(addr_mod_str, nullptr, 2);
//
//                cout << "addr_mod_bin: " << addr_mod_str << " addr_mod_int: " << addr_mod_int << endl;
//
//                fetched = true;
//
//            }
//
//            if (fetched == true && decode == false) {
//
//
//                //Decodificador de instrucciones
//
//                switch (addr_mod_int) {
//
//
//                    case ABS:
//
//                        cout << "LDA_ABS decoded: " << ri_mem << endl;
//
//                        //                    word_cont = 4;
//
//                        decode = true;
//
//                        break;
//
//                    case INM:
//
//                        cout << "LDA_INM decoded: " << ri_mem << endl;
//
//                        //                    word_cont = 2;
//                        //
//                        //                    decode = true;
//
//                        //                    cout << "2 word instruction: " << ri_mem << endl;
//
//                        if (oper_cont == 0) {
//
//                            oper_cont++;
//                            mem_cont++;
//                            decode = false;
//
//                            execute = false;
//
//                        }
//                        else {
//
//                            word_1 = mem_data_dec;
//
//                            oper_cont = 0;
//
//                            decode = true;
//
//                            execute = true;
//                        }
//
//                        break;
//
//                    case CTR:
//
//                        cout << "HLT_CTR decoded: " << ri_mem << endl;
//
//                        //                    word_cont = 1;
//
//                        //                    cout << "1 word instruction: " << ri_mem << endl;
//
//                        execute = true;
//
//                        decode = true;
//
//                        break;
//
//                    default:
//
//                        cout << "Error en la decodificacion de instruccion, direccionamiento no valido" << endl;
//                        // cout << "Deteniendo el proceso " << endl;
//                        // addr_t_o.write(mem_cont);
//                        // sc_stop();
//
//                        break;
//                }
//            }
//
//            // decoding words.
//
//            //        if (decode == true) {
//            //
//            //            switch (word_cont) {
//            //
//            //
//            //                case 1:
//            //
//            //                    cout << "1 word instruction: " << ri_mem << endl;
//            //
//            //                    execute = true;
//
//            //                    break;
//            //
//            //
//            //                case 2:
//            //
//            //                    cout << "2 word instruction: " << ri_mem << endl;
//            //
//            //                    if (oper_cont == 0) {
//            //
//            //                        oper_cont++;
//            //                        mem_cont++;
//            //                        decode = true;
//            //
//            //                        execute = false;
//            //
//            //                    }
//            //                    else {
//            //
//            //                        word_1 = mem_data_dec;
//            //
//            //                        oper_cont = 0;
//            //
//            //                        decode = false;
//            //
//            //                        execute = true;
//            //                    }
//            //
//            //                    break;
//            //
//            //
//            ////                case 4:
//            ////
//            ////                    cout << "3 word instruction: " << ri_mem << endl;
//            ////
//            ////                    if (oper_cont == 0) {
//            ////
//            ////                        oper_cont++;
//            ////
//            ////                        decode = true;
//            ////
//            ////                        execute = false;
//            ////
//            ////                        mem_cont++;
//            ////
//            ////
//            ////                    }
//            ////                    else if (oper_cont == 1) {
//            ////
//            ////                        word_1 = mem_data_dec;
//            ////
//            ////                        pa_address_ind_ss << hex << word_1; // int decimal_value
//            ////
//            ////                        pa_address_ind = pa_address_ind_ss.str();
//            ////
//            ////                        oper_cont++;
//            ////
//            ////                        decode = true;
//            ////
//            ////                        execute = false;
//            ////
//            ////                        mem_cont++;
//            ////
//            ////                    }
//            ////                    else if (oper_cont == 2) {
//            ////
//            ////                        word_2 = mem_data_dec;
//            ////
//            ////
//            ////                        pb_address_ind_ss << hex << word_2; // int decimal_value
//            ////
//            ////                        pb_address_ind = pb_address_ind_ss.str();
//            ////
//            ////                        address_ind_str = pa_address_ind + pb_address_ind;
//            ////
//            ////                        address_ind_ss << address_ind_str;
//            ////
//            ////                        address_ind_ss >> hex >> address_ind_int; // int decimal_value
//            ////
//            ////                        mem_cont = address_ind_int;
//            ////
//            ////                        oper_cont++;
//            ////
//            ////                        decode = true;
//            ////
//            ////                        execute = false;
//            ////                    }
//            ////
//            ////                    else if(oper_cont == 3){
//            ////
//            ////                        oper_cont = 0;
//            ////
//            ////                        decode = true;
//            ////
//            ////                        execute = true;
//            ////
//            ////                    }
//            ////
//            ////                    break;
//            ////
//            //            }
//            //        }
//            if (execute == true) {
//
//
//                switch (ri_mem) {
//
//
//                    case LDA_ABS:
//
//                        cout << "LDA_ABS executed: " << ri_mem << endl;
//
//                        A = mem_data_dec;
//
//                        cout << "word_1: " << word_1 << endl;
//
//                        cout << "word_2: " << word_2 << endl;
//
//                        cout << "A: " << A << endl;
//
//                        fetched = false;
//
//                        decode = false;
//
//                        mem_cont++;
//
//                        break;
//
//                    case LDA_INM:
//
//                        cout << "LDA_INM executed: " << ri_mem << endl;
//
//                        A = word_1;
//
//
//                        acum_t_o.write(word_1);
//
//                        a_t_s = word_1;
//
//                        bz_t_s = ~(a_t_s | a_t_s);
//
//                        s_t_s = (a_t_s[5], "X", s_t_s[3], s_t_s[2], bz_t_s, s_t_s[0]);
//
//                        s_t_o.write(s_t_s);
//
//                        cout << "a_t_s: " << a_t_s << " s_t_s: " << s_t_s << endl;
//
//                        cout << "A: " << A << endl;
//
//                        fetched = false;
//
//                        decode = false;
//
//                        mem_cont++;
//
//                        break;
//
//                    case ADD_INM:
//
//                        cout << "ADD_INM executed: " << ri_mem << endl;
//
//                        a_t_s = A;
//
//                        bv_t_s = a_t_s[5];
//
//                        A += word_1;
//
//                        (bc_t_s, a_t_s) = A;
//
//                        acum_t_o.write(a_t_s);
//
//
//                        bv_t_s = bv_t_s ^ a_t_s[5] ? bv_t_s ^ a_t_s[5] : 0;
//
//                        bz_t_s = ~(a_t_s | a_t_s);
//
//                        s_t_s = (a_t_s[5], "X", bv_t_s, s_t_s[2], bz_t_s, bc_t_s);
//
//                        s_t_o.write(s_t_s);
//
//                        cout << "a_t_s: " << a_t_s << " s_t_s: " << s_t_s << endl;
//
//                        cout << "A: " << A << endl;
//
//                        fetched = false;
//
//                        decode = false;
//
//                        mem_cont++;
//
//                        break;
//
//                    case HLT_CTR:
//
//                        cout << "HLT_CTR executed: " << ri_mem << endl;
//
//                        stop = true;
//
//                        cout << "stop: " << stop << endl;
//
//                        fetched = false;
//
//                        decode = false;
//
//                        sc_stop();
//
//                        mem_cont++;
//
//                        break;
//
//                    default:
//
//                        cout << "Error en la ejecucion de instruccion" << endl;
//
//                        break;
//                }
//
//
//            }
//
//
//        }
//        else {
//
//            addr_t_o.write(mem_cont);
//            // Leer de memoria.
//            rw_t_o.write(0);
//
//            cout << "rw_t_o: " << rw_t_o << endl;
//
//            // Habilitar memoria.
//            en_t_o.write(1);
//            cout << " Inicializacion de address process " << endl;
//            // sc_stop();
//
//        }
//
//        cnt_m_c++;
//    }
//
//}

