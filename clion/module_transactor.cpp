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
        cout << "v_CM: " << v_CM << endl;
    }
    else if((s_est_prox == Estado_1)&&(s_est_pres == Estado_16)){
        v_CM = true;
        s_CM = v_CM;
        s_CM = true;
        cout << "v_CM: " << v_CM << endl;
    }
    else{
        cout << "v_CM: " << v_CM << endl;
        v_CM = not v_CM;
        s_CM = v_CM;
        cout << "v_CM: " << v_CM << endl;
    }
    cout << "Bandera de busqueda: " << "|[" << s_CB << "]|" << " Bandera de memoria: " << "|[" << s_CM << "]|" << endl;
}

void  transactor::p_LE() {
    if(!rps_t_i){
        cout << "Estado reset: rps_t_i: " << rps_t_i << endl;
        s_LE = true;
        rw_t_o = true;
        cout << "s_LE: " << s_LE << endl;
    }
    else {
        switch (s_est_pres) {
            case Estado_0:
                cout << "Estado actual: " << Estado_0 << endl;
                s_LE = true;
                rw_t_o = true;
                en_t_o = true;
                cout << "s_LE: " << s_LE << endl;
                break;
            case Estado_1:
                cout << "Estado actual: " << Estado_1 << endl;
                s_LE = true;
                rw_t_o = true;
                en_t_o = en_t_o;
                cout << "s_LE: " << s_LE << endl;
                break;
            default:
                cout << "Estado actual: " << "default" << endl;
                s_LE = true;
                rw_t_o = true;
                en_t_o = en_t_o;
                cout << "s_LE: " << s_LE << endl;
                break;
        }
    }
}

void transactor::p_PC(){
    if(!rps_t_i){
        v_PC = 0;
        s_PC = v_PC;
    }
    else{
        switch (s_est_pres) {
            case Estado_0:
                cout << "Estado actual: " << Estado_0 << endl;
                v_PC = 0;
                s_PC = v_PC;
                pc_t_o = v_PC;
                addr_t_o = v_PC;
                cout << "s_PC: " << s_PC << endl;
                break;
            case Estado_1:
                cout << "Estado actual: " << Estado_1 << endl;
                v_PC = v_PC;
                s_PC = s_PC;
                pc_t_o = v_PC;
                addr_t_o = addr_t_o;
                cout << "s_PC: " << s_PC << endl;
                break;
            case Estado_2:
                cout << "Estado actual: " << Estado_2 << endl;
                switch (s_RI.read().to_uint()){
                    case TAP_CTR: case TPA_CTR: case CLA_ACU:
                    case INA_ACU: case DCA_ACU: case ROL_ACU:
                    case ROR_ACU: case CLC_IMP: case SEC_IMP:
                    case SEI_IMP: case CLI_IMP: case NOP_CTR:
                    case CPA_ACU:{
                        cout << "Instruccion 1 palabra: " << s_RI.read().to_uint() << endl;
                        v_PC = v_PC + 1;
                        s_PC = v_PC;
                        pc_t_o = v_PC;
                        addr_t_o = v_PC;
                        cout << "s_PC: " << s_PC << endl;
                        break;
                    }
                    default:
                        cout << "s_RI: " << s_RI.read().to_uint() << endl;
                        v_PC = v_PC;
                        s_PC = s_PC;
                        pc_t_o = v_PC;
                        addr_t_o = addr_t_o;
                        cout << "s_PC: " << s_PC << endl;
                        break;
                }
                break;
            default:
                cout << "Estado actual: " << "default" << endl;
                v_PC = 0;
                s_PC = v_PC;
                pc_t_o = v_PC;
                addr_t_o = addr_t_o;
                cout << "s_PC: " << s_PC << endl;
                break;
        }
    }
}

void  transactor::p_RI() {
    if (rps_t_i){
        if (s_CB){
//            s_RI = INA_ACU;
            v_RI = dat_t_i.read().to_int();
            s_RI = v_RI;
            ports_t_o = v_RI;

            //            s_RI = dat_t_i.read().to_int();
            cout << "Registro de instruccion: " << s_RI << endl;
        }
        else{
            s_RI = s_RI;
            v_RI = v_RI;
            ports_t_o = v_RI;

        }
    }
    else{
        v_RI = 0;
        s_RI = 0;
        ports_t_o = v_RI;

    }
}

void  transactor::p_est_pres() {
    cout << "@ |[" << sc_time_stamp() << "]| " << "s_est_pres: " << "|[" << s_est_pres << "]|"<< " = " << " s_est_prox: " << "|["<< s_est_prox << "]|"<< endl;
    if (rps_t_i){
        s_est_pres = s_est_prox;
//        cout << "Exec, s_est_pres: " << "|[" << s_est_pres << "]|"<< " = " << " s_est_prox: " << "|["<< s_est_prox << "]|"<< endl;
    }
    else{
        s_est_pres = Estado_0;
//        cout << "Init, s_est_pres: " << "|["<< s_est_pres << "]|"<< endl;
    }
}

void  transactor::p_est_prox() {
//    cout << "@ |[" << sc_time_stamp() << "]| " << "Señal de reposicion activa rps_t_i: |[" << rps_t_i.read() << "|]" << endl;
//    cout << "s_est_pres: " << "|[" << s_est_pres << "]|"<< " = " << " s_est_prox: " << "|["<< s_est_prox << "]|"<< endl;
    if (!rps_t_i){
        s_est_prox = Estado_1;
    }
    else{
        switch (s_est_pres) {
            case Estado_0:
                cout << "Estado actual: " << Estado_0 << endl;
                s_est_prox = Estado_1;
                break;
            case Estado_1:
                cout << "Estado actual: " << Estado_1 << endl;
                s_est_prox = Estado_2;
                break;
            case Estado_2:
                cout << "Estado actual: " << Estado_2 << endl;
                switch (s_RI.read().to_uint()){
                    case TAP_CTR: case TPA_CTR: case CLA_ACU:
                    case INA_ACU: case DCA_ACU: case ROL_ACU:
                    case ROR_ACU: case CLC_IMP: case SEC_IMP:
                    case SEI_IMP: case CLI_IMP: case NOP_CTR:
                    case CPA_ACU:{
                        cout << "Instruccion 1 palabra: " << s_RI.read().to_uint() << endl;
//                        cout << "s_RI.read().to_uint(): " << s_RI.read().to_uint() << endl;
                        s_est_prox = Estado_1;
                        break;
                    }
                    default:
                        cout << "s_RI: " << s_RI << endl;
                        break;
                }
                break;
            default:
                s_est_prox = Estado_0;
                break;
        }
    }
}

void  transactor::p_acum_a() {
    cout << "s_A: " << "|[" << s_A << "]|" << " s_bn_t: " << "|[" << s_bn_t << "]|" <<
    " s_bv_t: " << "|[" << s_bv_t << "]|" << " s_bi_t: " << "|[" << s_bi_t << "]|" <<
    " s_bz_t: " << "|[" << s_bz_t << "]|" << " s_bc_t: " << "|[" << s_bc_t << "]|" << "\n" << endl;
//                    cout << "v_A: " << "|[" << v_A << "]|" << " v_bn_t: " << "|[" << v_bn_t << "]|" <<
//                    " v_bv_t: " << "|[" << v_bv_t << "]|" << " v_bi_t: " << "|[" << v_bi_t << "]|" <<
//                    " v_bz_t: " << "|[" << v_bz_t << "]|" << " v_bc_t: " << "|[" << v_bc_t << "]|" << "\n" << endl;

    switch (s_est_pres) {
        case Estado_0:
            s_bi_t = 1;
            s_A = v_A;
            acum_t_o = v_A;
            cout << "v_A " << v_A << endl;
            // Calculo de bandera Z, con compuerta nor.
            v_bz_t = v_A.nor_reduce();
            cout << "v_bz_t " << v_bz_t << endl;
            // Actualizacion de señal de bandera z.
            s_bz_t = v_bz_t;
            // Calculo de bandera N, con el MSB de A.
            v_bn_t = v_A[5];
            // Actualizacion de señal de bandera N.
            s_bn_t = v_bn_t;
            v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
            s_t_o = v_S;
            break;
        case Estado_1:
            s_A = s_A;
            acum_t_o = acum_t_o;
            //v_A = v_A;
            // Calculo de bandera Z, con compuerta nor.
            v_bz_t = v_A.nor_reduce();
            cout << "v_bz_t " << v_bz_t << endl;
            // Actualizacion de señal de bandera z.
            s_bz_t = v_bz_t;
            // Calculo de bandera N, con el MSB de A.
            v_bn_t = v_A[5];
            // Actualizacion de señal de bandera N.
            s_bn_t = v_bn_t;
            v_bt1_t = v_A[5];
            if (s_RI.read().to_uint() == DCA_ACU){
                s_bv_t = v_bt1_t? ~v_A[5]:1;
            }
            if(s_RI.read().to_uint() == INA_ACU){
                v_bv_t = v_bt1_t? 1:v_A[5];
                s_bv_t = v_bt1_t? 1:v_A[5];
            }
            v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
            s_t_o = v_S;
        case Estado_2:
            switch (s_RI.read().to_uint()){
                case CLA_ACU:
                    v_A = 0;
                    s_A  = 0;
                    acum_t_o = v_A;
                    // Calculo de bandera Z, con compuerta nor.
                    v_bz_t = v_A.nor_reduce();
                    cout << "v_bz_t " << v_bz_t << endl;
                    // Actualizacion de señal de bandera z.
                    s_bz_t = v_bz_t;
                    // Calculo de bandera N, con el MSB de A.
                    v_bn_t = v_A[5];
                    // Actualizacion de señal de bandera N.
                    s_bn_t = v_bn_t;
                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                    s_t_o = v_S;
                    break;
                case INA_ACU:
                    cout << "v_A: " << v_A << endl;
                    (v_bc_t, v_A) = v_A + 1;
                    s_bc_t = v_bc_t;
                    s_A = v_A;
                    cout << "v_A: " << v_A << endl;
                    acum_t_o = v_A;
                    // Calculo de bandera Z, con compuerta nor.
                    v_bz_t = v_A.nor_reduce();
                    cout << "v_bz_t " << v_bz_t << endl;
                    // Actualizacion de señal de bandera z.
                    s_bz_t = v_bz_t;
                    // Calculo de bandera N, con el MSB de A.
                    v_bn_t = v_A[5];
                    // Actualizacion de señal de bandera N.
                    s_bn_t = v_bn_t;
                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                    s_t_o = v_S;
                    break;
                case DCA_ACU:
                    cout << "v_A: " << v_A << endl;
                    (v_bc_t, v_A) = v_A - 1;
                    s_bc_t = v_bc_t;
                    s_A = v_A;
                    cout << "v_A: " << v_A << endl;
                    acum_t_o = v_A;
                    // Calculo de bandera Z, con compuerta nor.
                    v_bz_t = v_A.nor_reduce();
                    cout << "v_bz_t " << v_bz_t << endl;
                    // Actualizacion de señal de bandera z.
                    s_bz_t = v_bz_t;
                    // Calculo de bandera N, con el MSB de A.
                    v_bn_t = v_A[5];
                    // Actualizacion de señal de bandera N.
                    s_bn_t = v_bn_t;
                    v_S = (v_bn_t, "X", v_bv_t, v_bi_t, v_bz_t, v_bc_t);
                    s_t_o = v_S;
                    break;

//                case ROL_ACU:
////                    v_bt2_t = v_bc_t;
//                    v_bc_t = s_A[5];
//                    cout << "v_bc_t: " << "|[" << v_bc_t << "]|" << endl;
////                    s_A = (s_A[4], s_A[3], s_A[2], s_A[1], s_A[0], v_bc_t);
////                    s_A = (s_A[5], s_A[5], s_A[5], s_A[5], s_A[5], s_A[5]);
//
//                    //  s_A = s_A.range(4,0), v_bc_t;
//
//                    cout << "s_A: " << "|[" << s_A << "]|" << endl;
//                    break;
            }

    }
}







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

