#ifndef MEMORY_H_
#define MEMORY_H_ 4096

 // SystemC library.
//#include </usr/local/systemc-2.3.1/include/systemc>
#include <systemc>

// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(memory){

    // Port declarations
    sc_in < sc_lv <6> > dat_m_i;
    sc_out < sc_lv <6> > dat_m_o;
    sc_in < sc_lv <12> > addr_m_i;
    sc_in < sc_lv<1> > rw_m_i;
    sc_in < sc_lv<1> > en_m_i;

    // Signals declarations.
    sc_signal< sc_uint<6> > ramdata[MEMORY_H_];

    void entry();

    void memdump()
    {
        FILE *fp = fopen("memdump","w");
        int size;
        fprintf(fp, "--------------\n");
        fprintf(fp, "|Address|Data|\n");
        fprintf(fp, "--------------\n");
        int  data_int = 0;


        for (size = 0; size < MEMORY_H_-1; size++) {

            data_int = ramdata[size].read().to_int();

            fprintf(fp, "|@%.4o|::|@%.2o|\n", size, data_int);
            fprintf(fp, "--------------\n");
        }
    }

        SC_CTOR(memory){

//
        SC_METHOD(entry);

//        dont_initialize();
//        sensitive << dat_m_o << addr_m_i << rw_m_i <<  en_m_i;
        sensitive << dat_m_i << addr_m_i << rw_m_i <<  en_m_i;

        FILE *fp ;

        fp = fopen("ram_init.txt","r");

        if(!fp)
        {
            perror("error. cannot find ram_init.");
        }

        int size=0;

        unsigned int mem_word;

        // for (size = 0; size < 255; size++) {
        //     ramdata[size].write(0x0);
        // }
        size = 0;
        cout << "-------------------------------------" << endl;
        cout << "Cargando el programa objeto a memoria" << endl;
        cout << "-------------------------------------" << endl;
        cout << "|[" << "Address" << "]|::|[" << "Data" << "]|" << endl;
        while (fscanf(fp,"%un", &mem_word) != EOF) {
            ramdata[size].write( mem_word );
            if (size < 30 ){
                cout << "|[" << size << "]|:::::::::|[" << mem_word << "]|" << endl;
                }
            size++;
        }
            cout << "-------------------------------------" << endl;
    }
};

#endif /* MEMORY_H_ */