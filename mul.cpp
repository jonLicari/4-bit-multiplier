#include <systemc.h>
#include "mul.h"

//sc_bv<8> a, b; // Input register arrays
sc_bv<4> a, b;
sc_bv<8> co; sc_bv<8> so; // Carry-out array and Sum-out array
sc_bv<8> p;	// Output product
sc_bit andgt; // stores AND gate output

void csa (sc_bit a, sc_bit b, sc_bit c, sc_bit s, int indexa, int indexb) {}

void mul :: multiply() {
	// Write in values to a and b 
	a = rA.read(); b = rB.read();
	// Initialize/ reset other variables
	co = "00000000"; so = "00000000"; p = "00000000";

	sc_bit ta, tb; // Temporary variable for holding specific bit index of array a and b
	sc_bit sin, cin; // Temp var for holding the sum-in and carry-in bit
	
	printf( "\n4 x 4 Multiplier\n\n" );
	cout << "Reg. A = " << a << endl;
	cout << "Reg. B = " << b << endl; 
	
	for (int m=0; m<4; m++) {
		for (int n=0; n<4; n++) {
			tb = b[m]; ta = a[n]; // Assign current index of a and b to temp value
			cin = co[n]; // Carry in tracks the a array index
			
			if (n == 3) {
				sin = 0;
			}
			else {
				//cout << "Sum In = " << sin << endl;
				sin = so[n+1]; // Sum in is the value of the previous sum of index n+1
				//cout << "Sum In = " << sin << endl;
			}
		//cout << "\n\nm = " << m << endl;
		//cout << "n = " << n << endl;
		//cout << "tA = " << ta << endl;
		//cout << "tb = " << tb << endl;
		//cout << "cin = " << cin << endl;
		//cout << "sin = " << sin << endl;
		csa(ta, tb, cin, sin, n, m);
		}
	}

}