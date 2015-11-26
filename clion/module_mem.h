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

    // Declaracion de puertos.
    sc_in < sc_lv <6> > dat_m_i; /**< Puerto de entrada de datos a memoria de 6 bits */
    sc_out < sc_lv <6> > dat_m_o; /**< Puerto de salida de datos a memoria de 6 bits */
    sc_in < sc_lv <12> > addr_m_i; /**< Puerto de entrada de direccion de memoria de 12 bits */
    sc_in < sc_lv<1> > rw_m_i; /**< Puerto de entrada de escritura o lectura de memoria de 1 bit */
    sc_in < sc_lv<1> > en_m_i; /**< Puerto de entrada habilitacion de memoria de 1 bit */

    // Declaracion de señales internas.
    sc_signal< sc_uint<6> > ramdata[MEMORY_H_]; /**< Arreglo interno de memoria de 4096 posiciones */

    void entry(); /**< Metodo de escritura y lectura de la memoria */

    void memdump(){
        cout << "Dumping memory" << endl;
        FILE *fp = fopen("memdump.txt","w");
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

    SC_CTOR(memory):dat_m_i("dat_m_i"),dat_m_o("dat_m_o"){
        SC_METHOD(entry);
//        dont_initialize();
        sensitive << dat_m_i << addr_m_i << rw_m_i <<  en_m_i;

        FILE *fp ;
        fp = fopen("ram_init.txt","r");
        if(!fp)
        {
            perror("error. no se puede encontrar el archivo ram_init.txt.");
        }
        int size=0;
        unsigned int mem_word;
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