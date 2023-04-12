#include"systemc.h"

SC_MODULE(full_adder){
	sc_in<bool> a,b, cin;
	sc_out<bool> sum, cout;

void addition{
	bool a_val, b_val, cin_val;

	a_val = a.read();
	b_val = b.read();
	cin_val = cin.read();

	bool sum_val, cout_val;

	sum_val = a_val ^ b_val ^ c_val;
	cout_val = (a_val & b_val) | ((a_val^b_val) & cin_val);

	sum.write(sum_val);
	cout.write(cout_val);

};

SC_CTOR(full_adder){

	SC_METHOD(addition);
	sensitive << a << b << cin;
};
