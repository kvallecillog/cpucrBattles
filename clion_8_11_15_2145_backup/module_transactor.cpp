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


void  transactor::init_cpucr(){

//    sc_core::event(rps_t_i);
    cout << "@ |[" << sc_time_stamp()  << "]| " << "Señal de reposicion activa rps_t_i: |[" << rps_t_i.read() <<"|]" << endl;
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

}

void transactor::inst_exec() {
//
   cout << "-------------------------------------------Ejecutor-------------------------------------------" << endl;


   cout << "------------------------------------------mem_cont:------------------------------------------\n"<< mem_cont << endl;


    if (rps_t_i) {
        string addrx = addr_t_o.read().to_string();
        string dont_carex = "XXXXXXXXXXXX";

        if (stop == false && addrx != dont_carex) {

            // Leer de memoria.
            rw_t_o.write(0);

            cout << "rw_t_o: " << rw_t_o << endl;

            // Habilitar memoria.
            en_t_o.write(1);

            cout << "en_t_o: " << en_t_o << endl;

            // Direccion a leer.

            cout << "mem_cont: " << mem_cont << endl;

            addr_t_o.write(mem_cont);

            cout << "addr_t_o: " << addr_t_o << endl;

            // Ciclo de memoria.
            mem_data_dec = dat_t_i.read().to_uint();

            mem_data_str = to_string(mem_data_dec);


            cout << "!!!!!Mem pos data:!!!!! " << mem_data_dec << endl;


            if (fetched == false) {


                ri_mem = mem_data_dec;

                addr_mod_str = bitset<6>(ri_mem).to_string();

                cout << "Fetched opcode: " << addr_mod_str << endl;

                //            cout << "ri_mem_bin: " << addr_mod_str << endl;

                addr_mod_str = addr_mod_str.substr(3, 3);

                addr_mod_int = stoi(addr_mod_str, nullptr, 2);

                cout << "addr_mod_bin: " << addr_mod_str << " addr_mod_int: " << addr_mod_int << endl;

                fetched = true;

            }

            if (fetched == true && decode == false) {


                //Decodificador de instrucciones

                switch (addr_mod_int) {


                    case ABS:

                        cout << "LDA_ABS decoded: " << ri_mem << endl;

                        //                    word_cont = 4;

                        decode = true;

                        break;

                    case INM:

                        cout << "LDA_INM decoded: " << ri_mem << endl;

                        //                    word_cont = 2;
                        //
                        //                    decode = true;

                        //                    cout << "2 word instruction: " << ri_mem << endl;

                        if (oper_cont == 0) {

                            oper_cont++;
                            mem_cont++;
                            decode = false;

                            execute = false;

                        }
                        else {

                            word_1 = mem_data_dec;

                            oper_cont = 0;

                            decode = true;

                            execute = true;
                        }

                        break;

                    case CTR:

                        cout << "HLT_CTR decoded: " << ri_mem << endl;

                        //                    word_cont = 1;

                        //                    cout << "1 word instruction: " << ri_mem << endl;

                        execute = true;

                        decode = true;

                        break;

                    default:

                        cout << "Error en la decodificacion de instruccion, direccionamiento no valido" << endl;
                        // cout << "Deteniendo el proceso " << endl;
                        // addr_t_o.write(mem_cont);
                        // sc_stop();

                        break;
                }
            }

            // decoding words.

            //        if (decode == true) {
            //
            //            switch (word_cont) {
            //
            //
            //                case 1:
            //
            //                    cout << "1 word instruction: " << ri_mem << endl;
            //
            //                    execute = true;

            //                    break;
            //
            //
            //                case 2:
            //
            //                    cout << "2 word instruction: " << ri_mem << endl;
            //
            //                    if (oper_cont == 0) {
            //
            //                        oper_cont++;
            //                        mem_cont++;
            //                        decode = true;
            //
            //                        execute = false;
            //
            //                    }
            //                    else {
            //
            //                        word_1 = mem_data_dec;
            //
            //                        oper_cont = 0;
            //
            //                        decode = false;
            //
            //                        execute = true;
            //                    }
            //
            //                    break;
            //
            //
            ////                case 4:
            ////
            ////                    cout << "3 word instruction: " << ri_mem << endl;
            ////
            ////                    if (oper_cont == 0) {
            ////
            ////                        oper_cont++;
            ////
            ////                        decode = true;
            ////
            ////                        execute = false;
            ////
            ////                        mem_cont++;
            ////
            ////
            ////                    }
            ////                    else if (oper_cont == 1) {
            ////
            ////                        word_1 = mem_data_dec;
            ////
            ////                        pa_address_ind_ss << hex << word_1; // int decimal_value
            ////
            ////                        pa_address_ind = pa_address_ind_ss.str();
            ////
            ////                        oper_cont++;
            ////
            ////                        decode = true;
            ////
            ////                        execute = false;
            ////
            ////                        mem_cont++;
            ////
            ////                    }
            ////                    else if (oper_cont == 2) {
            ////
            ////                        word_2 = mem_data_dec;
            ////
            ////
            ////                        pb_address_ind_ss << hex << word_2; // int decimal_value
            ////
            ////                        pb_address_ind = pb_address_ind_ss.str();
            ////
            ////                        address_ind_str = pa_address_ind + pb_address_ind;
            ////
            ////                        address_ind_ss << address_ind_str;
            ////
            ////                        address_ind_ss >> hex >> address_ind_int; // int decimal_value
            ////
            ////                        mem_cont = address_ind_int;
            ////
            ////                        oper_cont++;
            ////
            ////                        decode = true;
            ////
            ////                        execute = false;
            ////                    }
            ////
            ////                    else if(oper_cont == 3){
            ////
            ////                        oper_cont = 0;
            ////
            ////                        decode = true;
            ////
            ////                        execute = true;
            ////
            ////                    }
            ////
            ////                    break;
            ////
            //            }
            //        }
            if (execute == true) {


                switch (ri_mem) {


                    case LDA_ABS:

                        cout << "LDA_ABS executed: " << ri_mem << endl;

                        A = mem_data_dec;

                        cout << "word_1: " << word_1 << endl;

                        cout << "word_2: " << word_2 << endl;

                        cout << "A: " << A << endl;

                        fetched = false;

                        decode = false;

                        mem_cont++;

                        break;

                    case LDA_INM:

                        cout << "LDA_INM executed: " << ri_mem << endl;

                        A = word_1;


                        acum_t_o.write(word_1);

                        a_t_s = word_1;

                        bz_t_s = ~(a_t_s | a_t_s);

                        s_t_s = (a_t_s[5], "X", s_t_s[3], s_t_s[2], bz_t_s, s_t_s[0]);

                        s_t_o.write(s_t_s);

                        cout << "a_t_s: " << a_t_s << " s_t_s: " << s_t_s << endl;

                        cout << "A: " << A << endl;

                        fetched = false;

                        decode = false;

                        mem_cont++;

                        break;

                    case ADD_INM:

                        cout << "ADD_INM executed: " << ri_mem << endl;

                        a_t_s = A;

                        bv_t_s = a_t_s[5];

                        A += word_1;

                        (bc_t_s, a_t_s) = A;

                        acum_t_o.write(a_t_s);


                        bv_t_s = bv_t_s ^ a_t_s[5] ? bv_t_s ^ a_t_s[5] : 0;

                        bz_t_s = ~(a_t_s | a_t_s);

                        s_t_s = (a_t_s[5], "X", bv_t_s, s_t_s[2], bz_t_s, bc_t_s);

                        s_t_o.write(s_t_s);

                        cout << "a_t_s: " << a_t_s << " s_t_s: " << s_t_s << endl;

                        cout << "A: " << A << endl;

                        fetched = false;

                        decode = false;

                        mem_cont++;

                        break;

                    case HLT_CTR:

                        cout << "HLT_CTR executed: " << ri_mem << endl;

                        stop = true;

                        cout << "stop: " << stop << endl;

                        fetched = false;

                        decode = false;

                        sc_stop();

                        mem_cont++;

                        break;

                    default:

                        cout << "Error en la ejecucion de instruccion" << endl;

                        break;
                }


            }


        }
        else {

            addr_t_o.write(mem_cont);
            // Leer de memoria.
            rw_t_o.write(0);

            cout << "rw_t_o: " << rw_t_o << endl;

            // Habilitar memoria.
            en_t_o.write(1);
            cout << " Inicializacion de address process " << endl;
            // sc_stop();

        }

        cnt_m_c++;
    }

}
