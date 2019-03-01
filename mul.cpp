#include <systemc.h>
#include "mul.h"

//sc_bv<8> a, b; // Input register arrays
sc_bv<4> a, b;
sc_bv<8> co; sc_bv<8> so; // Carry-out array and Sum-out array
sc_bv<8> p;	// Output product

void mul :: multiply() {
	// Write in values to a and b 
	a = rA.read(); b = rB.read();
	// Initialize/ reset other variables
	co = "00000000"; so = "00000000"; p = "00000000";

	sc_bit ta, tb; // Temporary variable for holding specific bit index of array a and b
	sc_bit sin, cin; // Temp var for holding the sum-in and carry-in bit
}