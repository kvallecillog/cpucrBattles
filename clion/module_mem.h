#ifndef MEMORY_H_
#define MEMORY_H_

 
SC_MODULE(memory)
{
    sc_inout<sc_lv >  data;
    sc_in<sc_lv >     address;
    sc_in             rw;
    sc_in             enable;
 
    sc_signal<sc_uint >        ramdata[256];
 
    void entry();
 
    void memdump()
    {
        FILE *fp = fopen("data/memdump","w");
        int size;
        for (size = 0; size < 255; size++) {
            fprintf(fp, "0x%xn", ramdata[size].read().to_int());
        }
    }
 
    SC_CTOR(memory)
    {
        SC_METHOD(entry);
        sensitive << enable << rw << address;
 
        FILE *fp = fopen("data/ram_init","r");
        if(!fp)
        {
            cout << "error. cannot find ram_init." << endl;
        }
        int size=0;
        int mem_word;
        for (size = 0; size < 255; size++) {
            ramdata[size].write( 0x0 );
        }
        size = 0;
        while (fscanf(fp,"%xn", &mem_word) != EOF) {
            ramdata[size].write( mem_word );
            size++;
        }
    }
};
 
#endif /* MEMORY_H_ */