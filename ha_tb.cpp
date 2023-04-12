#include <systemc.h>
#include "ha.cpp"

int sc_main(int argc, char* argv[])
{
    sc_signal<bool> a, b, sum, carry;

    



    sc_trace_file *pTracefile;

    half_adder ha("half_adder");
    ha.a(a);
    ha.b(b);
    ha.sum(sum);
    ha.carry(carry);


    pTracefile = sc_create_vcd_trace_file("ha_wave");

    sc_trace(pTracefile, a, "a");
    sc_trace(pTracefile, b, "b");
    sc_trace(pTracefile, sum, "sum");
    sc_trace(pTracefile, carry, "carry");


    // Stimulus
    a = 0;
    b = 0;
    sc_start(1, SC_NS);

    a = 0;
    b = 1;
    sc_start(1, SC_NS);

    a = 1;
    b = 0;
    sc_start(1, SC_NS);

    a = 0;
    b = 1;
    sc_start(1, SC_NS);

    // Print results
    cout << "a b sum carry" << endl;
    for (int i = 0; i < 4; i++) {
        cout << a.read() << " " << b.read() << " " << sum.read() << " " << carry.read() << endl;
        sc_start(1, SC_NS);
    }
     
  


 
    return 0;
}
