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
    sc_in < sc_lv <6> > dat_m_i;
    sc_out < sc_lv <6> > dat_m_o;
    sc_in < sc_lv <12> >  addr_m_i;
    sc_in < sc_lv<1> > rw_m_i;
    sc_in < sc_lv<1> > en_m_i;
    sc_in_clk  clk_m_i;

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


//    void memdump(){
//        FILE *fp = fopen("memdump","w");
//        int size;
//        fprintf(fp, "--------------\n");
//        fprintf(fp, "|Address|Data|\n");
//        fprintf(fp, "--------------\n");
//        int  data_int = 0;
//
//
//        for (size = 0; size < MEMORY_H_-1; size++) {
//
//            data_int = ramdata[size].read().to_int();
//
//            fprintf(fp, "|@%.4o|::|@%.2o|\n", size, data_int);
//            fprintf(fp, "--------------\n");
//        }
//    }

        SC_CTOR(memory){

            SC_METHOD(entry);
         sensitive << clk_m_i;
//        sensitive << enable_mem << rw_mem << address_mem;


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
        while (fscanf(fp,"%xn", &mem_word) != EOF) {
            ramdata[size].write( mem_word );
            cout << ramdata[size].read() << endl;
            size++;
        }

//        FILE *fp ;
//
//        fp = fopen("ram_init.txt","r");
//        if(!fp)
//        {
//            perror("error. cannot find ram_init.");
//        }
//        int size=0;
//        unsigned int mem_word;
//        // for (size = 0; size < 255; size++) {
//        //     ramdata[size].write(0x0);
//        // }
//        size = 0;
//        while (fscanf(fp,"%xn", &mem_word) != EOF) {
//            ramdata[size].write( mem_word );
//            cout << mem_word << endl;
//            size++;
//        }
//        string line;
//
//        string file_path;
//        file_path = "ram_init_v2.txt";
//        ifstream object_file(file_path);
//
//        // // Lectura linea a linea del archivo objet
//
//        if (!object_file)
//        {
//            cout << "Error opening output file" << endl;
//            system("pause");
//            //        return -1;
//        }
//
//        cout << "\nPath del archivo del codigo objeto: " << file_path << endl;
//        cout << "\nContenido del archivo del codigo objeto: " << file_path << endl;
//
//        int i = 0;
//        int line_input = 0;
//        while (getline(object_file, line)) {
//
////            p_object_vec.push_back(line);
//            line_input = stoi(line);
//            ramdata[i].write(line_input);
////            cout << line << endl;
////            cout << ramdata[i].read() << endl;
//            cout << "Address: "<< i << " Data: " << ramdata[i].read() << endl;
//            i++;
//
//        }
//
//        cout << "Cantidad de instrucciones cargadas: # " << i << endl;



//            FILE *fp ;
//
//            fp = fopen("ram_init_v2.txt","r");
//            if(!fp)
//            {
//                perror("Error. cannot find ram_init.");
//            }
//            int size=0;
//            string mem_word;
////            for (size = 0; size < MEMORY_H_-1; size++) {
////                // Cambiar a numero randomw
////                ramdata[size].write(0x0);
////            }
//            size = 0;
//
//            while (fscanf(fp,"%s", &mem_word) != EOF) {
////                ramdata[size].write(mem_word);
//
////                ramdata_2[size]=mem_word;
//                cout << mem_word << endl;
////                cout << "size: " << size << " mem_word: " <<  ramdata_2[size] << endl;
////                cout << "size: " << size << " mem_word: " <<  ramdata[size].read()<< endl;
//                size++;
//            }
//
//            unsigned int  data_int2 = 0;
//            for (int i = 0; i <MEMORY_H_-1; i++){
//
//                data_int2 = ramdata[i].read().to_uint();
//            cout <<"Address: "<<  i <<" Data: " << data_int2 << endl;
//            }

        }
};


#endif /* MEMORY_H_ */