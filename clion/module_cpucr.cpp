

#include </usr/local/systemc-2.3.1/include/systemc>
#include "module_cpucr.h"
#include <iostream>

using namespace std;
using namespace sc_core;
using namespace sc_dt;

void cpucr::monitor()
{
    cout << "@" << sc_time_stamp() << " data_cpucr :" << data_cpucr << " address_cpucr :" << address_cpucr
    << " rw_cpucr :" << rw_cpucr << " enable_cpucr :" << enable_cpucr << " clk_cpucr: " << clk_cpucr << endl;
}

