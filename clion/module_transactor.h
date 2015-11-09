//
// Created by kenneth on 25/10/15.
//

// SystemC library.
//#include </usr/local/systemc-2.3.1/include/systemc>

#include <systemc>

#include <iostream>
#include <bitset>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include "definitions_dec.cpp"

using namespace std;
using namespace sc_core;
using namespace boost;
using namespace sc_dt;
using namespace boost::algorithm;


SC_MODULE(transactor){

        // Port declarations
        sc_in < bool > rps_t_i;
        sc_in < sc_lv <6> > dat_t_i;
        sc_out < sc_lv <6> > dat_t_o;
        sc_out < sc_lv <12> > addr_t_o;
        sc_out < sc_lv<1> > rw_t_o;
        sc_out < sc_lv<1> > en_t_o;
        sc_out < sc_lv <6> > acum_t_o;
        sc_out < sc_lv <6> > s_t_o;
        sc_in < sc_lv <6> > ports_t_i;
        sc_out < sc_lv <6> > ports_t_o;
        sc_out < sc_lv<12> > pc_t_o;
        sc_in_clk  clk_t_i;
        sc_out < bool > init_t_o;

        sc_signal < int > s_est_pres;
        sc_signal < int > s_est_prox;
        sc_signal < bool > s_CB;
        sc_signal < bool > s_CM;
 
        sc_signal < sc_uint<6> > s_RI;
        sc_signal < sc_uint<6> > s_A;
        sc_signal < sc_uint<1> > s_bn_t;
        sc_signal < sc_uint<1> > s_bv_t;
        sc_signal < sc_uint<1> > s_bi_t;
        sc_signal < sc_uint<1> > s_bz_t;
        sc_signal < sc_uint<1> > s_bc_t;

         sc_uint<6> v_RI;
         sc_uint<6> v_A;
         sc_uint<1> v_bn_t;
         sc_uint<1> v_bv_t;
         sc_uint<1> v_bi_t;
         sc_uint<1> v_bz_t;
         sc_uint<1> v_bc_t;

        // Bits temporales
        sc_uint<1> v_bt1_t;
        sc_uint<1> v_bt2_t;

//        int v_dat_t_i = dat_t_i.read().to_int();
        int v_dat_t_o;

        void p_CB();
        void p_RI();
        void p_est_pres();
        void p_est_prox();
        void p_acum_a();


        SC_CTOR(transactor){

                SC_METHOD(p_CB);
                sensitive << clk_t_i.neg();

                SC_METHOD(p_RI);
                sensitive << clk_t_i.neg();

                SC_METHOD(p_est_pres);
                sensitive << clk_t_i.neg();

                SC_METHOD(p_est_prox);
                sensitive << s_est_pres;

                SC_METHOD(p_acum_a);
                v_A = "100000";
//                s_A.initialize("100000");
                sensitive << clk_t_i.neg();

        }

};










//SC_CTOR(transactor):rps_t_i("rps_t_i"){

//sc_uint<6> a_t_s;
//sc_uint<6> s_t_s;
//sc_uint<1> bn_t_s;
//sc_uint<1> bv_t_s;
//sc_uint<1> bi_t_s;
//sc_uint<1> bz_t_s;
//sc_uint<1> bc_t_s;
//sc_uint<12> pc_t_s;

//        int cnt_m_c , word_cont, ri_mem, address_ind_int, oper_cont;
//
//        unsigned int mem_cont, mem_data_dec, addr_mod_int, A, word_1, word_2;
//
//        string addr_mod_str, mem_data_str, operand, address_ind_str, pa_address_ind, pb_address_ind;
//
//        stringstream address_ind_ss, pa_address_ind_ss, pb_address_ind_ss;
//
//        stringstream addr_mod_ss;
//
//        bool stop, decode, fetched, execute;

//        void init_cpucr();
//
//        void inst_exec();
//            SC_METHOD(init_cpucr);
//
//                dat_t_o.initialize("xxxxxx");
//
//                addr_t_o.initialize("xxxxxxxxxxxx");
//
//                rw_t_o.initialize("x");
//
//                en_t_o.initialize("x");
//
//                pc_t_o.initialize("xxxxxxxxxxxx");
//
//                dont_initialize();
//
//                sensitive << rps_t_i.pos();
//
//
//
//            SC_METHOD(inst_exec);
//
//            dont_initialize();
//
//
//
//                sensitive << clk_t_i.neg();
//
//                 mem_cont = 0;
//
//                 stop = false;
//
//                 decode = false;
//
//                 fetched = false;
//
//                 execute = false;
//
//
//
//
////            sensitive_pos << rps_t_i;
//
////            SC_METHOD(inst_exec);
////
////            sensitive_neg << clk_t_i ;
////            sensitive << acum_t_o ;
////            sensitive << clk_t_i << dat_t_o << addr_t_o << rw_t_o << en_t_o;
//
////            cnt_m_c= mem_cont= A= word_1= word_2= word_cont= ri_mem= address_ind_int= oper_cont = 0;
////
//
//
////            dat_t_o.initialize("zzzzzz");
////
////            addr_t_o.initialize("5");
////
////            rw_t_o.initialize("0");
////
////            en_t_o.initialize("1");
//
////
////            FILE *fp ;
////
////            fp = fopen("pc_init.txt","r");
////
////            if(!fp)
////            {
////                perror("error. cannot find pc_file_name.");
////            }
////
////            int size=0;
////
////            unsigned int pc_init;
////
////            // for (size = 0; size < 255; size++) {
////            //     ramdata[size].write(0x0);
////            // }
////            size = 0;
////            while (fscanf(fp,"%xn", &pc_init) != EOF) {
////                pc_t_s = pc_init ;
////                cout << pc_init << endl;
////                size++;
////            }
////            cout << "pc_init" << pc_init << endl;
////            pc_t_o.initialize(pc_t_s);
////            mem_cont = pc_init;
////            addr_t_o.initialize(pc_init);
//        }
//
//};


