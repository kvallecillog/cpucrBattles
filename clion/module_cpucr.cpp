

//#include </usr/local/systemc-2.3.1/include/systemc>

#include <systemc>

#include "module_cpucr.h"

#include <iostream>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

void cpucr::monitor()
{
    cout << "@:|[" << sc_time_stamp() << "]| data_cpucr :|[" << dat_c_o << "]| address_cpucr: |[" << addr_c_o
    << "]| rw_cpucr :|[" << rw_c_o << "]| enable_cpucr :|[" << en_c_o << "]| clk_cpucr: |[" << clk_c_i <<"]|" << endl;
}