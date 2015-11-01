//
// Created by kenneth on 25/10/15.
//

// SystemC library.
#include </usr/local/systemc-2.3.1/include/systemc>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

SC_MODULE(transactor){

        // Port declarations
        sc_in< sc_lv <6> > dat_t_i;
        sc_out < sc_lv <6> > dat_t_o;
        sc_out < sc_lv <12> > addr_t_o;
        sc_out < sc_lv<1> > rw_t_o;
        sc_out < sc_lv<1> > en_t_o;
        sc_out < sc_lv <6> > acum_t_o;
        sc_out < sc_lv <6> > s_t_o;
        sc_in < sc_lv <6> > ports_t_i;
        sc_out < sc_lv <6> > ports_t_o;
        sc_in < sc_lv<1> > rps_t_i;
        sc_in_clk  clk_t_i;

        sc_out < sc_lv<12> > pc_t_o;

        sc_lv<6> a_t_s;
        sc_lv<6> s_t_s;
        sc_lv<1> bn_t_s;
        sc_lv<1> bv_t_s;
        sc_lv<1> bi_t_s;
        sc_lv<1> bz_t_s;
        sc_lv<1> bc_t_s;
        sc_lv<12> pc_t_s;


    int cnt_m_c , word_cont, ri_mem, address_ind_int, oper_cont;

        unsigned int mem_cont, mem_data_dec, addr_mod_int, A, word_1, word_2;

        string addr_mod_str, mem_data_str, operand, address_ind_str, pa_address_ind, pb_address_ind;

        stringstream address_ind_ss, pa_address_ind_ss, pb_address_ind_ss;

        stringstream addr_mod_ss;

        bool stop, decode, fetched, execute;

    void inst_exec();

        SC_CTOR(transactor){

            SC_METHOD(inst_exec);

            sensitive_neg << clk_t_i ;
//            sensitive << acum_t_o ;
//            sensitive << clk_t_i << dat_t_o << addr_t_o << rw_t_o << en_t_o;

            cnt_m_c= mem_cont= A= word_1= word_2= word_cont= ri_mem= address_ind_int= oper_cont = 0;

//            mem_data_dec = 0;

            stop = false;
            
            decode = false;
            
            fetched = false;
            
            execute = false;

//            dat_t_o.initialize("zzzzzz");
//
//            addr_t_o.initialize("0");
//
            rw_t_o.initialize("0");

            en_t_o.initialize("1");


            FILE *fp ;

            fp = fopen("pc_init.txt","r");

            if(!fp)
            {
                perror("error. cannot find pc_file_name.");
            }

            int size=0;

            unsigned int pc_init;

            // for (size = 0; size < 255; size++) {
            //     ramdata[size].write(0x0);
            // }
            size = 0;
            while (fscanf(fp,"%xn", &pc_init) != EOF) {
                pc_t_s = pc_init ;
                cout << pc_init << endl;
                size++;
            }

            pc_t_o.initialize(pc_t_s);
            mem_cont = pc_init;
            addr_t_o.initialize(pc_init);
        }

};


