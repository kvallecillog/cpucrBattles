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

        // Declaracion de puertos.
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
        sc_out < sc_lv <6> > addr_ports_t_o;
        sc_out < sc_lv<1> > rw_ports_t_o;
        sc_out < sc_lv<1> > en_ports_t_o;
        sc_out < sc_lv <6> > ri_t_o;
        sc_out < sc_lv<12> > pc_t_o;
        sc_in_clk  clk_t_i;
        sc_out < bool > init_t_o;
        sc_out < int > s_est_pres;
        sc_out < int > s_est_prox;
        sc_out < bool > s_CB;
        sc_out < bool > s_CM;
        sc_out < bool > s_LE;

        // Declaracion de señales internas.
        sc_signal < bool > v_M;
        sc_signal < sc_uint<6> > s_RI;
        sc_signal < sc_uint<6> > s_A;
        sc_signal < sc_uint<1> > s_bn_t;
        sc_signal < sc_uint<1> > s_bv_t;
        sc_signal < sc_uint<1> > s_bi_t;
        sc_signal < sc_uint<1> > s_bz_t;
        sc_signal < sc_uint<1> > s_bc_t;
        sc_signal < sc_int<12> > s_PC;
        sc_signal < sc_uint<12> > s_PP;
        sc_signal < sc_uint<6> > s_PB;

        sc_int<12> v_PC;
        sc_uint<6> v_RI;
        sc_uint<6> v_A;
        sc_uint<1> v_bn_t;
        sc_uint<1> v_bv_t;
        sc_uint<1> v_bi_t;
        sc_uint<1> v_bz_t;
        sc_uint<1> v_bc_t;
        sc_uint<6> v_S;
        sc_uint<6> v_S_read;
        sc_int<12> v_addr;
        sc_uint<6> v_addr_ports;
        sc_uint<6> v_PA;
        sc_uint<6> v_PB;
        sc_uint<12> v_PP;

        // Bits temporales
        sc_uint<1> v_bt1_t;
        sc_uint<1> v_bt2_t;

        int v_dat_t_o;
        int i1, i2, i3, i4, i5, i6, i7;
        bool v_CM;
        void p_CB();
        void p_RI();
        void p_est_pres();
        void p_est_prox();
        void p_LE();
        void p_PC();
        void p_M();
        void p_P();


        SC_CTOR(transactor):acum_t_o("acum_t_o"),s_est_pres("s_est_pres"), s_est_prox("s_est_prox"){

            SC_METHOD(p_CB);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_M);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_P);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_LE);
            en_t_o.initialize("0");
            sensitive << clk_t_i.neg();

            SC_METHOD(p_PC);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_RI);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_est_pres);
            sensitive << clk_t_i.neg();

            SC_METHOD(p_est_prox);
            v_A = 63;
            i1 = i2 = i3 = i4 = i5 = i6 = i7 = 0;
            sensitive << s_est_pres;
//                SC_METHOD(p_acum_a);
//                v_A = "0";
//                i1 = i2 = i3 = i4 = i5 = i6 = i7 = 0;
////                acum_t_o.initialize("0");
////                v_A = "111111";
////                s_A = "111111";
//                sensitive << clk_t_i.neg();
        }

};








