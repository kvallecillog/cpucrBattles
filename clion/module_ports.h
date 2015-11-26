#ifndef PORTS_H_
#define PORTS_H_ 64

 // SystemC library.
//#include </usr/local/systemc-2.3.1/include/systemc>
#include <systemc>

// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(ports){

    // Port declarations
    sc_in < sc_lv <6> > dat_p_i;
    sc_out < sc_lv <6> > dat_p_o;
    sc_in < sc_lv <6> > addr_p_i;
    sc_in < sc_lv<1> > rw_p_i;
    sc_in < sc_lv<1> > en_p_i;

    // Signals declarations.
    sc_signal< sc_uint<6> > ramdata[PORTS_H_];

    void entry();
    void memdump(){
        cout << "Dumping ports" << endl;
        FILE *fp = fopen("memdump.txt","w");
        int size;
        fprintf(fp, "--------------\n");
        fprintf(fp, "|Address|Data|\n");
        fprintf(fp, "--------------\n");
        int  data_int = 0;
        for (size = 0; size < PORTS_H_-1; size++) {
            data_int = ramdata[size].read().to_int();
            fprintf(fp, "|@%.4o|::|@%.2o|\n", size, data_int);
            fprintf(fp, "--------------\n");
        }
    }
    SC_CTOR(ports):dat_p_i("dat_p_i"),dat_p_o("dat_p_o"){
        SC_METHOD(entry);
//        dont_initialize();
        sensitive << dat_p_i << addr_p_i << rw_p_i <<  en_p_i;
        FILE *fp ;
        fp = fopen("ports_init.txt","r");
        if(!fp)
        {
            perror("error. no se puede encontrar el archivo ports_init.txt.");
        }
        int size=0;
        unsigned int mem_word;
        size = 0;
        cout << "-------------------------------------" << endl;
        cout << "Cargando valor de puertos por defecto" << endl;
        cout << "-------------------------------------" << endl;
        cout << "|[" << "Address" << "]|::|[" << "Data" << "]|" << endl;
        while (fscanf(fp,"%un", &mem_word) != EOF) {
            ramdata[size].write( mem_word );
            if (size < 64 ){
                cout << "|[" << size << "]|:::::::::|[" << mem_word << "]|" << endl;
                }
            size++;
        }
            cout << "-------------------------------------" << endl;
    }
};

#endif /* PORTS_H_ */