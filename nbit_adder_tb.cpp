#include"systemc.h"
#include"nbit_adder.cpp"


int sc_main(int argc, char *argv[]) {
    sc_signal<sc_uint<32>> a, b, sum;
    int n_bits = 8;
    n_bit_adder adder("adder");
    adder.a(a);
    adder.b(b);
    adder.sum(sum);


    sc_trace_file *pTracefile;

    pTracefile = sc_create_vcd_trace_file("nbit_adder_wave");

    sc_trace(pTracefile, a, "a");
    sc_trace(pTracefile, b, "b");
    sc_trace(pTracefile, sum, "sum");
    //sc_trace(pTracefile, carry, "carry");

    
    // Testbench code
    for (int i = 0; i < (1 << n_bits); i++) {
        a = i;
        b = i;
        sc_start(1, SC_NS);
        cout << "a = " << a << ", b = " << b << ", sum = " << sum << endl;
    }
    
    return 0;
}
