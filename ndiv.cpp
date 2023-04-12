#include "systemc.h"

SC_MODULE(divider) {
    sc_in<sc_uint<8>> numerator;
    sc_in<sc_uint<8>> denominator;
    sc_out<sc_uint<8>> quotient;
    sc_out<sc_uint<8>> remainder;

    void div_process() {
        sc_uint<8> temp_numerator = numerator.read();
        sc_uint<8> temp_denominator = denominator.read();
        sc_uint<8> temp_quotient = 0;
        sc_uint<8> temp_remainder = 0;

        for (int i = 7; i >= 0; i--) {
            temp_remainder = temp_remainder << 1;
            temp_remainder(0, 0) = temp_numerator[i];
            if (temp_remainder >= temp_denominator) {
                temp_remainder -= temp_denominator;
                temp_quotient[i] = 1;
            }
        }

        quotient.write(temp_quotient);
        remainder.write(temp_remainder);
    }

    SC_CTOR(divider) {
        SC_METHOD(div_process);
        sensitive << numerator << denominator;
    }
};
