#include"systemc.h"

SC_MODULE(andgate){
	sc_in<bool> a;
	sc_in<bool> b;
	sc_out<bool> y;

	void func(){
		y.write(a.read()&b.read());
	};

	SC_CTOR(andgate){
		SC_METHOD(func);
		sensitive<< a;
		sensitive<< b;
	}

};
