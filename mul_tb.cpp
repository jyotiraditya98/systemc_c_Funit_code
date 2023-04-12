#include "systemc.h"

#include "mul.cpp"
int sc_main(int argc, char *argv[]) {
    sc_signal<sc_uint<8>> a, b;
    sc_signal<sc_uint<16>> c;
    int n_bits = 8;
    multiplier mul("multiplication");
    mul.a(a);
    mul.b(b);
    mul.c(c);


    sc_trace_file *pTracefile;

    pTracefile = sc_create_vcd_trace_file("nbit_mul_wave");

    sc_trace(pTracefile, a, "a");
    sc_trace(pTracefile, b, "b");
    sc_trace(pTracefile, c,"c");
    //sc_trace(pTracefile, carry, "carry");

  sc_start();
    // Testbench code
    for (int i = 0; i < (1 << n_bits); i++) {
        a = i;
        b = i;
        sc_start(1, SC_NS);
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
    
    return 0;
}


