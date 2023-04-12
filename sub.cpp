#include "systemc.h"

SC_MODULE(n_bit_subtractor) {
    sc_in< sc_uint<32> > a;
    sc_in< sc_uint<32> > b;
    sc_out< sc_uint<32> > out;

    SC_CTOR(n_bit_subtractor) {
        SC_METHOD(subtract);
        sensitive << a << b;
    }

    void subtract() {
        out.write(a.read() - b.read());
    }
};

