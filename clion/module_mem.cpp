using namespace std;
 
void memory::entry()
{
    if(enable.read() == 1) {
        std::cout << "@ " << sc_time_stamp() << std::endl;
        if(rw.read() == 1) {            //write
            ramdata[address.read().to_int()].write( data.read() );
            std::cout << "writing data " << data.read() << " at " << address.read() << std::endl;
        } else {                        //read
            data.write(ramdata[address.read().to_int()].read());
            std::cout << "reading data " << data.read() << " at " << address.read() << std::endl;
        }
    } else {
        data.write("zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz");
    }
}