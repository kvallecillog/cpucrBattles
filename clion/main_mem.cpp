// Basic library c++ set.
#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

// System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_mem.h"
#include "definitions_dec.cpp"
//#include "module_mem.cpp"

// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;

int sc_main(int argc, char* argv[]) {

    memory mem("memory");
    sc_set_time_resolution(1, SC_PS);

    sc_trace_file *wf = sc_create_vcd_trace_file("memory");
//    wf->set_time_unit(1, SC_NS);
    sc_trace(wf, mem.address, "address");
    sc_trace(wf, mem.data, "data");
    sc_trace(wf, mem.enable, "enable");
    sc_trace(wf, mem.rw, "rw");

    sc_signal < sc_lv<1> > enable;
    sc_signal < sc_lv<1> > rw;
    sc_signal < sc_lv <6> > data;
    sc_signal < sc_lv <12> > address;
    int write_count;

    string line ;
    vector<string> p_object_vec;


    mem.rw(rw);
    mem.data(data);
    mem.address(address);
    mem.enable(enable);
//    mem.write_count(write_count);
    enable  = 0;
    data    = 0;
    address = 0;
    rw      = 0;
    sc_start(0, SC_PS);
    write_count = 0;

    string file_path;
    file_path = "../pycharm/file.obj";
    ifstream  object_file (file_path);
    // // Reading line by line of object file.
    if(!object_file) //Always test the file open.
    {
        cout<<"Error opening output file"<< endl;
        system("pause");
        return -1;
    }

    cout << "\nPath del archivo del codigo objeto: " << file_path << endl;
    cout << "\nContenido del archivo del codigo objeto: " << file_path << endl;
    int i = 0 ;
    while(getline(object_file,line)){

        p_object_vec.push_back(line);
        i++;
        cout << line << endl;
    }

    cout << "Cantidad de instrucciones cargadas: # " << i << endl;


    string data_vec;
    string data_str;
    string operand_pb_vec;
    string operand_pa_vec;
    string opcode_vec;
    string dont_care = "XXXXXX";
    vector<string> tokens;

    vector<int> pcs;
    int ps_clk = 0;
    string address_vec;
    unsigned int address_int = 0;
    int opcode_int = 0;
    int operand_pb_int, operand_pa_int = 0;


    // Loading the object file (aka the program) to memory
    for (unsigned int i = 0 ; i < p_object_vec.size(); i++ ) {

        data_vec=p_object_vec[i];

        split(tokens, data_vec, is_any_of(" "));

        address_vec = tokens[1];
        address_int = stoi(tokens[0]);
        pcs.push_back(address_int);
        stringstream address_sstream;
        address_sstream << "0x" << hex << address_int;
        string adress_hex = address_sstream.str();

        opcode_vec = tokens[1];
        opcode_int = stoi(tokens[1], nullptr, 2);

        operand_pb_vec=tokens[2].substr(6,6);
        operand_pa_vec=tokens[2].substr(0,6);


        if ((operand_pa_vec!=dont_care) && (operand_pb_vec!=dont_care)){


            operand_pa_int=stoi(operand_pa_vec, nullptr, 2);
            operand_pb_int=stoi(operand_pb_vec, nullptr, 2);

            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(opcode_int);

            sc_start(ps_clk, SC_PS);
            write_count++;
            ps_clk=5;
            address_int++;

            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pa_int);

            sc_start(ps_clk, SC_PS);
            write_count++;


            ps_clk=5;
            address_int++;
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pb_int);

            sc_start(ps_clk, SC_PS);
            ps_clk=5;
            write_count++;

        }
        else if ((operand_pa_vec==dont_care) && (operand_pb_vec==dont_care)) {

            ps_clk=5;
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(opcode_int);
            sc_start(ps_clk, SC_PS);
            address_int++;
            write_count++;

        }
        else if ((operand_pa_vec!=dont_care) && (operand_pb_vec == dont_care)) {

            operand_pa_int = stoi(operand_pa_vec, nullptr, 2);

            ps_clk=5;

            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(opcode_int);
            sc_start(ps_clk, SC_PS);

            write_count++;
            address_int++;

            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pa_int);
            sc_start(ps_clk, SC_PS);


            address_int++;
            write_count++;

            }

    }

//
//    unsigned int mem_data_dec ;
//    mem_data_dec = 0;
//    // Here is the vector with the allowed instruction addresses
//
//    int mem_cont = pcs[0];
////    int pc_cont = pcs[0];
//
//    int word_cont = 0;
//    int opcode_mem = 0;
//
//    string operand;
//    string mem_data_str;
//    int A = 0;
//    int word_1 = 0;
//    int word_2 = 0;
//    int oper_cont = 0;
//
//    ps_clk=5;
//
//    bool stop = false;
//    bool decode = false;
////    bool fetch = true;
//    bool fetched = false;
//    bool execute = false;
//
//    while(stop == false) {
//
//        rw = 0;
//        enable = 1;
//        address = mem_cont;
//        sc_start(ps_clk, SC_PS);
//
//
//        mem_data_dec = data.read().to_uint();
//        mem_data_str = to_string(mem_data_dec);
//
//        // Opcode fetch
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
//        if(fetched == false){
//
//            opcode_mem = mem_data_dec;
//            fetched = true;
//
//        }
//
//        if (fetched == true) {
//
//
//            //Decodificador de instrucciones
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
//        // decoding words.
//
//        if (fetched == true && decode == true) {
//
//            switch (word_cont) {
//
//
//                case 1:
//
//                    cout << "1 word instruction: " << opcode_mem << endl;
//                    mem_cont++;
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
//                    if(oper_cont == 0){
//
//                        oper_cont++;
//
//                        fetched = true;
//
//                        decode = true;
//
//                        execute = false;
//
//                    }
//                    else{
//
//                        word_1 = mem_data_dec;
//
//                        oper_cont = 0;
//
////                        fetched = false;
//
//                        decode = false;
//
//                        execute = true;
//                    }
//
//                    break;
//
//
////                case 3:
////
////                    cout << "2 word instruction: " << opcode_mem << endl;
////
////                    if(oper_cont == 0){
////
////                        oper_cont++;
////
////                        execute = false;
////
////                    }
////                    else if(oper_cont == 1){
////
////                        word_1 = mem_data_dec;
////
////                        oper_cont++;
////
////                        fetch = true;
////
////                        decode = true;
////
////                        execute = false;
////
////                    }
////                    else if(oper_cont == 2){
////
////                        word_2 = mem_data_dec;
////
////                        oper_cont = 0;
////
////                        fetch = false;
////
////                        decode = false;
////
////                        execute = true;
////
////                    }
////
////                    break;
//            }
//        }
//        if (execute == true){
//
//            fetched == false;
//
//            switch (opcode_mem) {
//
//
//                case LDA_ABS:
//
//                    A = word_1 + word_2;
//                    cout << "A: " << A << endl;
//                    cout << "LDA_ABS executed: " << opcode_mem << endl;
//
//                    break;
//
//                case LDA_INM:
//
//                    A = word_1;
//                    cout << "A: " << A << endl;
//                    cout << "LDA_INM executed: " << opcode_mem << endl;
//
//                    break;
//
//                case HLT_CTR:
//
//                    stop = true;
//
//                    cout << "HLT_CTR executed: " << opcode_mem << endl;
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
//
//
//    }
//
//

    enable  = 0;
   sc_start(ps_clk, SC_PS);

    mem.memdump();
    sc_close_vcd_trace_file(wf);

    return(0);
}