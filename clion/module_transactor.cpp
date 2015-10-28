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


using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


/**
*get_obj_file(): Se encarga obtener cada linea del archivo objeto e ingresarla en una posición del vector p_object_vec tipo
*string. Al concluir la ejecución se retorna el p_object_vec con todas instrucciones ensambladas por el preprocesador.
*/

vector <string> transactor::get_obj_file() {

    vector <string> p_object_vec;
    string line;

    string file_path;
    file_path = "../pycharm/file.obj";
    ifstream object_file(file_path);

    // // Lectura linea a linea del archivo objet

    if (!object_file)
    {
        cout << "Error opening output file" << endl;
        system("pause");
    //        return -1;
    }

    cout << "\nPath del archivo del codigo objeto: " << file_path << endl;
    cout << "\nContenido del archivo del codigo objeto: " << file_path << endl;

    int i = 0;
    while (getline(object_file, line)) {

        p_object_vec.push_back(line);
        i++;
        cout << line << endl;
    }

    cout << "Cantidad de instrucciones cargadas: # " << i << endl;

    return p_object_vec;
}

/**
*load_obj_file(): Descompone la instruccion en opcode y argumento, luego carga cada palabra de instruccion la posicion
 * de memoria asignada por el PC.
*/
void transactor::load_obj_file() {


//    vector <string> p_object_vec = get_obj_file();
    vector <string> p_object_vec ;
    //vector <string> p_object_vec = "0 000000 000001XXXXXX";

    vector <string> tokens;
    vector <int> pcs;

    string data_vec;
    string operand_pb_vec;
    string operand_pa_vec;
    string opcode_vec;
    string dont_care = "XXXXXX";
    string address_vec;

    int opcode_int = 0;
    int operand_pb_int, operand_pa_int = 0;
    int write_count = 0;
    int ns_clk = 0;
    unsigned int address_int = 0;

    // Cargando el programa objeto a memoria.

    for (unsigned int i = 0; i < p_object_vec.size(); i++) {

        data_vec = p_object_vec[i];

        split(tokens, data_vec, is_any_of(" "));

        address_vec = tokens[1];
        address_int = stoi(tokens[0]);
        pcs.push_back(address_int);

        opcode_vec = tokens[1];
        opcode_int = stoi(tokens[1], nullptr, 2);

        operand_pb_vec = tokens[2].substr(6, 6);
        operand_pa_vec = tokens[2].substr(0, 6);

        // Escritura en memoria de instrucciones con 3 palabras.
        if ((operand_pa_vec != dont_care) && (operand_pb_vec != dont_care)) {


            operand_pa_int = stoi(operand_pa_vec, nullptr, 2);
            operand_pb_int = stoi(operand_pb_vec, nullptr, 2);

            ns_clk = 20;

            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(opcode_int);
            sc_start(ns_clk, SC_NS);
            write_count++;
            address_int++;

            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(operand_pa_int);
            sc_start(ns_clk, SC_NS);
            write_count++;
            address_int++;

            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(operand_pb_int);
            sc_start(ns_clk, SC_NS);
            write_count++;
            address_int++;

        }


            // Escritura en memoria de instrucciones de 1 palabra.
        else if ((operand_pa_vec == dont_care) && (operand_pb_vec == dont_care)) {
            cout << "LOADING" <<endl;
            ns_clk = 20;

            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(opcode_int);
            sc_start(ns_clk, SC_NS);
            address_int++;
            write_count++;

        }
            // Escritura en memoria de instrucciones de 2 palabras.
        else if ((operand_pa_vec != dont_care) && (operand_pb_vec == dont_care)) {

            operand_pa_int = stoi(operand_pa_vec, nullptr, 2);

            ns_clk = 20;


            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(opcode_int);
            sc_start(ns_clk, SC_NS);
            write_count++;
            address_int++;

            rw_trans.write(1);
            enable_trans.write(1);
            address_trans.write(address_int);
            data_trans.write(operand_pa_int);
            sc_start(ns_clk, SC_NS);
            address_int++;
            write_count++;

        }

    }

}
//
//void loader::word_load(int address_int, int opcode_int, int ns_clk,int write_count ) {
//
//    memory mem("memory");
//
//    mem.rw(rw);
//    mem.data(data);
//    mem.address(address);
//    mem.enable(enable);
//    mem.clk(clk);
//
//    rw = 1;
//    enable = 1;
//    address.write(address_int);
//    data.write(opcode_int);
//    sc_start(ns_clk, SC_NS);
//    write_count++;
//    address_int++;
//
//}
//

//void transactor::inst_exec() {
//
//    cout << "Ejecutor" << endl;
//    unsigned int mem_data_dec;
//    mem_data_dec = 0;
//
//    int mem_cont = pcs[0];
//
//    int A = 0;
//    int word_1 = 0;
//    int word_2 = 0;
//
////    asysc = 0;
////    word_1_SysC = 0;
////    word_2_SysC = 0;
//
//    int word_cont = 0;
//    int opcode_mem = 0;
//
//    string operand;
//    string mem_data_str;
//
//
//    int oper_cont = 0;
//
//    int ns_clk = 20;
//
//    bool stop = false;
//    bool decode = false;
//    bool fetched = false;
//    bool execute = false;
//    enable = 0;

//    while (stop == false) {
//
//// Leer de memoria.
//        rw = 0;
//// Habilitar memoria.
//        enable = 1;
//// Direccion a leer.
//        address = mem_cont;
//// Ciclo de memoria.
//        sc_start(ns_clk, SC_NS);
////wait(1,SC_NS);
//// Datos extraidos, unsigned int.
//        mem_data_dec = data.read().to_uint();
//        mem_data_str = to_string(mem_data_dec);
//
//// Opcode fetch
//
////        if (mem_cont == pc_cont){
////
////        opcode_mem = mem_data_dec;
////        mem_cont++;
////        operand = "";
////        word_cont = 0;
////        fetch = true;
////    }
//
//        if (fetched == false) {
//
//            opcode_mem = mem_data_dec;
//            fetched = true;
//
//        }
//
//        if (fetched == true && decode == false) {
//
//
////Decodificador de instrucciones
//
//            switch (opcode_mem) {
//
//
//                case LDA_ABS:
//
//                    cout << "LDA_ABS decoded: " << opcode_mem << endl;
//
//                    word_cont = 3;
//
//                    decode = true;
//
//                    break;
//
//                case LDA_INM:
//
//                    cout << "LDA_INM decoded: " << opcode_mem << endl;
//
//                    word_cont = 2;
//
//                    decode = true;
//
//                    break;
//
//                case ADD_INM:
//
//                    cout << "ADD_INM decoded: " << opcode_mem << endl;
//
//                    word_cont = 2;
//
//                    decode = true;
//
//                    break;
//
//                case HLT_CTR:
//
//                    cout << "HLT_CTR decoded: " << opcode_mem << endl;
//
//                    word_cont = 1;
//
//                    decode = true;
//
//                    break;
//
//                default:
//
//                    cout << "Error en la decodificacion de instruccion" << endl;
//
//                    break;
//            }
//        }
//
//// decoding words.
//
//        if (decode == true) {
//
//            switch (word_cont) {
//
//
//                case 1:
//
//                    cout << "1 word instruction: " << opcode_mem << endl;
//
//                    mem_cont++;
//
//                    execute = true;
//
//                    break;
//
//
//                case 2:
//
//                    cout << "2 word instruction: " << opcode_mem << endl;
//
//                    mem_cont++;
//
//                    if (oper_cont == 0) {
//
//                        oper_cont++;
//
//                        decode = true;
//
//                        execute = false;
//
//                    }
//                    else {
//
//                        word_1 = mem_data_dec;
//
////                        word_1_SysC = word_1;
////
////                        cout << "word_1: " << word_1 << endl;
////                        cout << "word_1_SysC: " << word_1_SysC << endl;
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
//                case 3:
//
//                    cout << "3 word instruction: " << opcode_mem << endl;
//
//                    mem_cont++;
//
//                    if (oper_cont == 0) {
//
//                        oper_cont++;
//
//                        decode = true;
//
//                        execute = false;
//
//                    }
//                    else if (oper_cont == 1) {
//
//                        word_1 = mem_data_dec;
////                        word_1_SysC = word_1;
//                        oper_cont++;
//
//                        decode = true;
//
//                        execute = false;
//
//                    }
//                    else if (oper_cont == 2) {
//
//                        word_2 = mem_data_dec;
////                        word_2_SysC = word_2;
//                        oper_cont = 0;
//
//                        decode = true;
//
//                        execute = true;
//
//                    }
//
//                    break;
//            }
//        }
//        if (execute == true) {
//
////            asysc = 0;
////            word_1_SysC = 0;
////            word_2_SysC = 0;
//
//            switch (opcode_mem) {
//
//
//                case LDA_ABS:
//
//                    cout << "LDA_ABS executed: " << opcode_mem << endl;
//                    A = word_1 + word_2;
////asysc = word_1_SysC;
////                    asysc.write(A);
//                    cout << "word_1: " << word_1 << endl;
//
//                    cout << "word_2: " << word_2 << endl;
//
//                    cout << "A: " << A << endl;
//
//                    fetched = false;
//
//                    decode = false;
//
//                    break;
//
//                case LDA_INM:
//
//                    cout << "LDA_INM executed: " << opcode_mem << endl;
//                    A = word_1;
////
////                    word_1_SysC = word_1;
////                    asysc =word_1;
////asysc = word_1_SysC;
////                    asysc.write(A);
////
//////asysc = A;
////                    cout << "asysc=A: " << asysc.read().to_uint() << endl;
////
////                    cout << "word_1_SysC: " << word_1_SysC << endl;
//                    cout << "A: " << A << endl;
//
//                    fetched = false;
//
//                    decode = false;
//
//                    break;
//
//                case ADD_INM:
//
//                    cout << "ADD_INM executed: " << opcode_mem << endl;
//                    A += word_1;
////                    word_1_SysC = word_1;
////                    asysc.write(A);
////
//////asysc = A;
////                    cout << "asysc=A: " << asysc.read().to_uint() << endl;
//
////                    asysc = A;
////                    cout << "asysc=A: " << asysc << endl;
////                    cout << "word_1_SysC: " << word_1_SysC << endl;
//                    cout << "A: " << A << endl;
//
//                    fetched = false;
//
//                    decode = false;
//
//                    break;
//
//                case HLT_CTR:
//
//                    cout << "HLT_CTR executed: " << opcode_mem << endl;
//
//                    stop = true;
//
//                    cout << "stop: " << stop << endl;
//
//                    fetched = false;
//
//                    decode = false;
//
//                    break;
//
//                default:
//
//                    cout << "Error en la ejecucion de instruccion" << endl;
//
//                    break;
//            }
//
//
//        }
//
//
//    }
//}