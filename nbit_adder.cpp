#include"systemc.h"
//template<int N>

#include <systemc.h>

SC_MODULE(n_bit_adder) {
    sc_in<sc_uint<32>> a; // input operand A
    sc_in<sc_uint<32>> b; // input operand B
    sc_out<sc_uint<32>> sum; // output sum
    
    SC_CTOR(n_bit_adder) {
        SC_METHOD(add);
        sensitive << a << b;
    }
    
    void add() {
        sum.write(a.read()+b.read());
    }
};
