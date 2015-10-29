#ifndef MEMORY_H_
#define MEMORY_H_ 4096

 // SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>
// IO c library.
#include "stdio.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(memory){

    // Port declarations
    sc_inout < sc_lv <6> > data_mem;
    sc_in < sc_lv <12> >  address_mem;
    sc_in < sc_lv<1> > rw_mem;
    sc_in < sc_lv<1> > enable_mem;
    sc_in_clk  clk_mem;
    // Signals declarations.
    sc_signal< sc_uint<6> > ramdata[MEMORY_H_-1];
    string ramdata_2[MEMORY_H_-1];
//    void mem_init();
    void entry();

//    void memdump(){
//        FILE *fp = fopen("memdump","w");
//        int size;
//        fprintf(fp, "--------------\n");
//        fprintf(fp, "|Address|Data|\n");
//        fprintf(fp, "--------------\n");
//        for (size = 0; size < MEMORY_H_-1; size++) {
//
//            int data_int = ramdata[size].read().to_int();
//
//            fprintf(fp, "|@%.4o|::|@%.2o|\n", size, data_int);
//            fprintf(fp, "--------------\n");
//        }
////        fprintf(fp, "--------------\n");
//    }

        SC_CTOR(memory){

            SC_METHOD(entry);
            sensitive << clk_mem;

            FILE *fp ;

            fp = fopen("ram_init_v2.txt","r");
            if(!fp)
            {
                perror("Error. cannot find ram_init.");
            }
            int size=0;
            int mem_word;
//            for (size = 0; size < MEMORY_H_-1; size++) {
//                // Cambiar a numero randomw
//                ramdata[size].write(0x0);
//            }
            size = 0;
            while (fscanf(fp,"%d", &mem_word) != EOF) {
                ramdata[size].write( mem_word );
                cout << "size: " << size << " mem_word: " << mem_word << endl;
//                ramdata_2[size]=mem_word;
                size++;
            }
            for (int i = 0; i <MEMORY_H_-1; i++){
            cout <<"Address: "<<  i <<" Data: " << ramdata[i].read() << endl;
            }

        }
};


#endif /* MEMORY_H_ */