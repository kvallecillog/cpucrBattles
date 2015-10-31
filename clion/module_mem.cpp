//
// Created by kenneth on 25/10/15.
//

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>

 // System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

#include "module_mem.h"


// To call basic c++ methods.
using namespace std;
// To call boost methods.
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


void memory::entry(){
    if(en_m_i.read() == 1) {

        if(rw_m_i.read() == 1) {

            //write
            ramdata[addr_m_i.read().to_uint()].write( dat_m_i.read() );
            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<dat_m_i.read().to_uint() << "]|" << " en direccion " << "|["<< addr_m_i.read().to_uint() << "]|" << endl;

        }
        else {

            //read
            dat_m_o.write(ramdata[addr_m_i.read().to_uint()].read());
            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< dat_m_o.read().to_uint()<< "]|" << " en direccion " <<"|["<< addr_m_i.read().to_uint() << "]|" << endl;

        }
    }
    else {
        dat_m_o.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    }
}

//void memory::mem_init()
//{
//        FILE *fp ;
//
//        fp = fopen("ram_init.txt","r");
//        if(!fp)
//        {
//            perror("error. cannot find ram_init.");
//        }
//        int size=0;
//        int mem_word;
//        for (size = 0; size < MEMORY_H_-1; size++) {
//            // Cambiar a numero randomw
//            ramdata[size].write(0x0);
//        }
//        size = 0;
//        while (fscanf(fp,"%d", &mem_word) != EOF) {
//            ramdata[size].write( mem_word );
//            size++;
//        }
//
//}