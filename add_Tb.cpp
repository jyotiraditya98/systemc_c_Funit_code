#include <systemc.h>
#include "nbit_adder.cpp"
//template <int N>

 

int sc_main(int argc, char* argv[]) {
    //const int N = 4; // Set N to the desired number of bits

 

    sc_signal<sc_lv<N>> inp1; // Input a
    sc_signal<sc_lv<N>> inp2; // Input b
    sc_signal<sc_lv<N>> sum; // Output sum
    sc_signal<bool> cout; // Carry out

 

    // Instantiate the adder module
    nadder nadd("nadd", N);

 

    // Connect the signals to the module
    nadd.inp1(inp1);
    nadd.inp2(inp2);
    nadd.sum(sum);
    nadd.cout(cout);

 

    // Generate test stimuli
    for (int i = 0; i < (1 << N); i++) {
        inp1 = i;
        for (int j = 0; j < (1 << N); j++) {
            inp2 = j;

 

            // Wait for some time for the output to settle
            wait(10, SC_NS);

 

            // Check the output
            sc_lv<N> expected_sum = i + j;
            bool expected_carry = expected_sum[N-1];
            if (sum != expected_sum || cout != expected_carry) {
                std::cout << "Error: " << i << " + " << j << " = " << expected_sum << ", " << expected_carry << std::endl;
            }
        }
    }

 

    std::cout << "Test complete." << std::endl;

 

    return 0;
}
