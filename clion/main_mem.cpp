// Basic library c++ set.
#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

// System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_mem.h"
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
    sc_trace(wf, mem.address, "address");
    sc_trace(wf, mem.data, "data");
    sc_trace(wf, mem.enable, "enable");
    sc_trace(wf, mem.rw, "rw");

    sc_signal < sc_lv<1> > enable;
    sc_signal < sc_lv<1> > rw;
    sc_signal < sc_lv <6> > data;
    sc_signal < sc_lv <12> > address;


    string line ;
    vector<string> p_object_vec;


    mem.rw(rw);
    mem.data(data);
    mem.address(address);
    mem.enable(enable);


    enable  = 0;
    data    = 0;
    address = 0;
    rw      = 0;


    ifstream  object_file ("../pycharm/file.obj");
    // // Reading line by line of object file.
    if(!object_file) //Always test the file open.
    {
        cout<<"Error opening output file"<< endl;
        system("pause");
        return -1;
    }
//    int i = 0 ;
    while(getline(object_file,line)){
//        cout<< " Read line: " << line << endl;
        p_object_vec.push_back(line);
//        cout << " My vec data: " << p_object_vec[i] << endl;
//        i++;
    }


//    int ps_clk = 0;
    string data_vec;
    string data_str;
    string operand_pb_vec;
    string operand_pa_vec;
    string opcode_vec;
    string dont_care = "XXXXXX";
    vector<string> tokens;
    int ps_clk = 0;
    string address_vec;
    int address_int = 0;
    int opcode_int = 0;
    int operand_pb_int, operand_pa_int = 0;

    for (unsigned int i = 0 ; i < p_object_vec.size(); i++ ) {

        data_vec=p_object_vec[i];



        split(tokens, data_vec, is_any_of(" "));

        address_vec = tokens[1];
        address_int = stoi(tokens[0]);
        stringstream address_sstream;
        address_sstream << "0x" << hex << address_int;
        string adress_hex = address_sstream.str();

        opcode_vec = tokens[1];
        opcode_int = stoi(tokens[1], nullptr, 2);

        operand_pb_vec=tokens[2].substr(6,6);
        operand_pa_vec=tokens[2].substr(0,6);


        cout << "data_vec: " << data_vec << endl;

        cout << "address_vec: " << address_int << endl;
        cout << "address_int: " << address_int << endl;

        cout << "address_hex: " << adress_hex << endl;

        cout << "opcode_vec: " << opcode_vec << endl;
        cout <<"opcode_int: "<< opcode_int << endl;


        cout << "operand_vec pa : " << operand_pa_vec << endl;
        cout << "operand_vec pb : " << operand_pb_vec << endl;


        if (operand_pb_vec!=dont_care){


            operand_pa_int=stoi(operand_pa_vec, nullptr, 2);
            operand_pb_int=stoi(operand_pb_vec, nullptr, 2);

            cout << "operand_pa_int 1: " <<  operand_pa_int << endl;
            cout << "operand_pb_int 1: " <<  operand_pb_int << endl;


            stringstream operand_pa_sstream;
            stringstream operand_pb_sstream;
            operand_pa_sstream << "0x" << hex << operand_pa_int;
            string operand_pa_hex = operand_pa_sstream.str();
            operand_pb_sstream << "0x" << hex << operand_pb_int;
            string operand_pb_hex = operand_pb_sstream.str();


            cout << "operand_pa_hex 1: " <<  operand_pa_hex << endl;
            cout << "operand_pb_hex 1: " <<  operand_pb_hex << endl;

            sc_start(ps_clk, SC_PS);
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(opcode_int);



            ps_clk=5;
            address_int++;
            sc_start(ps_clk, SC_PS);
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pa_int);



            ps_clk=5;
            address_int++;
            sc_start(ps_clk, SC_PS);
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pb_int);

            ps_clk=5;


        }
        if (operand_pb_vec==dont_care){

            operand_pa_int=stoi(operand_pa_vec, nullptr, 2);

            cout << "operand_pa_int 2: " <<  operand_pa_int << endl;

            stringstream operand_pa_sstream;

            operand_pa_sstream << "0x" << hex << operand_pa_int;
            string operand_pa_hex = operand_pa_sstream.str();


            cout << "operand_pa_hex 2: " <<  operand_pa_hex << endl;

            sc_start(ps_clk, SC_PS);
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(opcode_int);



            ps_clk=5;
            address_int++;
            sc_start(ps_clk, SC_PS);
            rw = 1;
            enable = 1;
            address.write(address_int);
            data.write(operand_pa_int);
            ps_clk=5;


        }


    }

//    sc_start(5, SC_PS);
//    enable  = 0;
//    sc_start(5, SC_PS);
//
//    address.write(0x12);
//    data.write(0x3F);
//
//    enable  = 1;
//    sc_start(5, SC_PS);
//
//    address.write(0x8);
//    data.write(0x3F);
//    sc_start(5, SC_PS);
    ps_clk=5;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    address_int++;
    ps_clk=5;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);
    rw      = 0;
    ps_clk=5;
    address_int++;
    sc_start(ps_clk, SC_PS);

//
//    rw      = 0;
//    address = 0x11;
//    sc_start(5, SC_PS);
//
//    rw      = 0;
//    address = 0x11;
//    sc_start(5, SC_PS);
//
//    rw      = 0;
//    address = 0x12;
//    sc_start(5, SC_PS);
//
//    address = 0x1;
//    sc_start(5, SC_PS);
//
//    address = 0x3;
//    sc_start(5, SC_PS);
//
//    enable  = 0;
//    sc_start(1, SC_PS);

    mem.memdump();
    sc_close_vcd_trace_file(wf);

    return(0);
}