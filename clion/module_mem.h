#ifndef MEMORY_H_
#define MEMORY_H_ 4096

 // SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"


// To call basic c++ methods.
using namespace std;
// To call boost methods.    
using namespace sc_core;

using namespace sc_dt;

SC_MODULE(memory){

    sc_inout < sc_lv <6> > data;
    sc_in < sc_lv <12> >  address;
    sc_in < sc_lv<1> > rw;
    sc_in < sc_lv<1> > enable;
    sc_in <bool> clk;

    sc_signal< sc_uint<6> > ramdata[MEMORY_H_-1];
 
    void entry();

    void memdump(){
        FILE *fp = fopen("memdump","w");
        int size;
        fprintf(fp, "--------------\n");
        fprintf(fp, "|Address|Data|\n");
        fprintf(fp, "--------------\n");
        for (size = 0; size < MEMORY_H_-1; size++) {

            int data_int = ramdata[size].read().to_int();

            fprintf(fp, "|@%.4o|::|@%.2o|\n", size, data_int);
            fprintf(fp, "--------------\n");
        }
//        fprintf(fp, "--------------\n");
    }

    SC_CTOR(memory){

        SC_METHOD(entry);

//        sensitive << enable << rw << address ;
        sensitive << clk << enable << rw << address ;
        FILE *fp ;

        fp = fopen("ram_init.txt","r");
        if(!fp)
        {
            perror("error. cannot find ram_init.");
        }
        int size=0;
        int mem_word;
        for (size = 0; size < MEMORY_H_-1; size++) {
            // Cambiar a numero randomw
            ramdata[size].write(0x0);
        }
        size = 0;
        while (fscanf(fp,"%d", &mem_word) != EOF) {
            ramdata[size].write( mem_word );
            size++;
        }


    }
};
 
#endif /* MEMORY_H_ */