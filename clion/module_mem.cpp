#include <iostream>
using namespace std;
 // System C library.
#include </usr/local/systemc-2.3.1/include/systemc>

// memory definitions.
#include "module_mem.h"

// To call basic c++ methods.
using namespace std;
// To call boost methods.    
using namespace sc_core;

using namespace sc_dt;

void memory::entry()
{
    if(enable.read() == 1) {
//        cout << "@ " << sc_time_stamp() << endl;
        if(rw.read() == 1) {            //write
//            write_count++;
            ramdata[address.read().to_uint()].write( data.read() );
            cout << "@ |[" << sc_time_stamp()  << "]| Escritura de datos " <<"|[" <<data.read().to_uint() << "]|" << " en direccion " << "|["<< address.read().to_uint() << "]|" << endl;
        } else {                        //read
            data.write(ramdata[address.read().to_uint()].read());
            cout << "@ |[" << sc_time_stamp()  << "]| Lectura de datos " <<"|["<< data.read().to_uint()<< "]|" << " en direccion " <<"|["<< address.read().to_uint() << "]|" << endl;
        }
    } else {
        data.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    }
}