//
// Created by kenneth on 25/10/15.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_transactor.h"
#include "definitions_dec.cpp"


using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


void transactor::inst_exec() {
//
    cout << "-------------------------------------------Ejecutor-------------------------------------------" << endl;


    cout << "------------------------------------------mem_cont:------------------------------------------ "<< mem_cont << endl;

////    sc_start(10, SC_NS);
//
//    rw_t_o.write(0);
//// Habilitar memoria.
//    en_t_o.write(1);
//// Direccion a leer.
//    addr_t_o.write(mem_cont);
//
//// Datos extraidos, unsigned int.
//    mem_data_dec = dat_t_i.read().to_uint();
//
//    mem_data_str = to_string(mem_data_dec);



    if (stop == false) {

// Leer de memoria.
        rw_t_o.write(0);
        cout << "rw_t_o: "<< rw_t_o << endl;
// Habilitar memoria.
        en_t_o.write(1);
        cout << "en_t_o: "<< en_t_o << endl;
// Direccion a leer.
        addr_t_o.write(mem_cont);
        cout << "addr_t_o: "<< addr_t_o << endl;
// Ciclo de memoria.

        mem_data_dec = dat_t_i.read().to_uint();

        mem_data_str = to_string(mem_data_dec);

        cout << "!!!!!Mem pos data:!!!!! " << mem_data_dec << endl;


        if (fetched == false) {

            opcode_mem = mem_data_dec;

            fetched = true;

        }

        if (fetched == true && decode == false) {


//Decodificador de instrucciones

            switch (opcode_mem) {


                case LDA_ABS:

                    cout << "LDA_ABS decoded: " << opcode_mem << endl;

                    word_cont = 4;

                    decode = true;

                    break;

                case LDA_INM:

                    cout << "LDA_INM decoded: " << opcode_mem << endl;

                    word_cont = 2;

                    decode = true;

                    break;

                case ADD_INM:

                    cout << "ADD_INM decoded: " << opcode_mem << endl;

                    word_cont = 2;

                    decode = true;

                    break;

                case HLT_CTR:

                    cout << "HLT_CTR decoded: " << opcode_mem << endl;

                    word_cont = 1;

                    decode = true;

                    break;

                default:

                    cout << "Error en la decodificacion de instruccion" << endl;

                    break;
            }
        }

// decoding words.

        if (decode == true) {

            switch (word_cont) {


                case 1:

                    cout << "1 word instruction: " << opcode_mem << endl;

                    execute = true;

                    break;


                case 2:

                    cout << "2 word instruction: " << opcode_mem << endl;

                    if (oper_cont == 0) {

                        oper_cont++;

                        decode = true;

                        execute = false;

                    }
                    else {

                        word_1 = mem_data_dec;

                        oper_cont = 0;

                        decode = false;

                        execute = true;
                    }

                    break;


                case 4:

                    cout << "3 word instruction: " << opcode_mem << endl;

                    if (oper_cont == 0) {

                        oper_cont++;

                        decode = true;

                        execute = false;

                        mem_cont++;


                    }
                    else if (oper_cont == 1) {

                        word_1 = mem_data_dec;

                        pa_address_ind_ss << hex << word_1; // int decimal_value

                        pa_address_ind = pa_address_ind_ss.str();

                        oper_cont++;

                        decode = true;

                        execute = false;

                        mem_cont++;

                    }
                    else if (oper_cont == 2) {

                        word_2 = mem_data_dec;


                        pb_address_ind_ss << hex << word_2; // int decimal_value

                        pb_address_ind = pb_address_ind_ss.str();

                        address_ind_str = pa_address_ind + pb_address_ind;

                        address_ind_ss << address_ind_str;

                        address_ind_ss >> hex >> address_ind_int; // int decimal_value

                        mem_cont = address_ind_int;

                        oper_cont++;

                        decode = true;

                        execute = false;
                    }

                    else if(oper_cont == 3){

                        oper_cont = 0;

                        decode = true;

                        execute = true;

                    }

                    break;

            }
        }
        if (execute == true) {


            switch (opcode_mem) {


                case LDA_ABS:

                    cout << "LDA_ABS executed: " << opcode_mem << endl;

                    A = mem_data_dec;

                    cout << "word_1: " << word_1 << endl;

                    cout << "word_2: " << word_2 << endl;

                    cout << "A: " << A << endl;

                    fetched = false;

                    decode = false;

                    mem_cont++;

                    break;

                case LDA_INM:

                    cout << "LDA_INM executed: " << opcode_mem << endl;

                    A = word_1;

                    cout << "A: " << A << endl;

                    fetched = false;

                    decode = false;

                    mem_cont++;

                    break;

                case ADD_INM:

                    cout << "ADD_INM executed: " << opcode_mem << endl;

                    A += word_1;

                    cout << "A: " << A << endl;

                    fetched = false;

                    decode = false;

                    mem_cont++;

                    break;

                case HLT_CTR:

                    cout << "HLT_CTR executed: " << opcode_mem << endl;

                    stop = true;

                    cout << "stop: " << stop << endl;

                    fetched = false;

                    decode = false;

                    mem_cont++;

                    break;

                default:

                    cout << "Error en la ejecucion de instruccion" << endl;

                    break;
            }


        }


    }
    else{

        cout << " Halt process " << endl;

    }

}