#ifndef MUL_H
#define MUL_H

#include <systemc.h>

void make_mul();

SC_MODULE(mul) {
// PORT DECLARATION
	sc_in<bool> clk;
	sc_inout<sc_bv<4> > rA, rB;
	//sc_inout<sc_bv<8> > rA, rB;
	sc_inout<sc_bv<8> > sout; // 8 bit input registers and sum out
// FUNCTION DECLARATION
	void multiply(); // args?
// CONSTRUCTOR
	SC_CTOR(mul) {

	SC_METHOD(multiply);
	dont_initialize();
	sensitive << clk.pos();
	}
};
#endif