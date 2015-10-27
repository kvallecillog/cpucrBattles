#include <iostream>
using namespace std;
 // System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

// memory definitions.
#include "module_mem.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

void memory::entry()
{
    if(enable_mem.read() == 1) {

        if(rw_mem.read() == 1) {            //write

            ramdata[address_mem.read().to_uint()].write( data_mem.read() );
            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<data_mem.read().to_uint() << "]|" << " en direccion " << "|["<< address_mem.read().to_uint() << "]|" << endl;
        } else {                        //read
            data_mem.write(ramdata[address_mem.read().to_uint()].read());
            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< data_mem.read().to_uint()<< "]|" << " en direccion " <<"|["<< address_mem.read().to_uint() << "]|" << endl;
        }
    } else {
        data_mem.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
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