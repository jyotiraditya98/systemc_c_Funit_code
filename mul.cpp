#include "systemc.h"

SC_MODULE(multiplier) {
  sc_in<sc_uint<8>> a; // input a, n-bit wide
  sc_in<sc_uint<8>> b; // input b, n-bit wide
  sc_out<sc_uint<16>> c; // output c, 2n-bit wide
  
  void multiply() {
    c.write(a.read() * b.read()); // multiply a and b, and write result to c
  }
  
  SC_CTOR(multiplier) {
    SC_METHOD(multiply);
    sensitive << a << b;
  }
};
