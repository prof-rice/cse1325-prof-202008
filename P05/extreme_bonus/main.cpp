#include "and.h"
#include "or.h"
#include "xor.h"

#include <iostream>

int main() {
    And a;  // Upper AND
    And b;  // Lower AND
    Or c;
    Xor xl; // Left XOR into which A and B are inputs
    Xor xr; // Right XOR which produces S
    
    xl.connect(xr, 1); // connect output of left XOR to pin 1 input of right XOR
    xl.connect( a, 1); // connect output of left XOR to pin 1 input of upper AND
    a.connect(c, 1);   // connect output of upper AND to pin 1 input of OR
    b.connect(c, 2);   // connect output of lower AND to pin 2 input of OR
    // INTERFACE
    // A   should connect to xl pin 1 and b pin 1
    // B   should connect to xl pin 2 and b pin 2
    // Cin should connect to xr pin 2 and a pin 2

    std::cout << "Cin B A  Cout S\n=== = =  ==== =\n";
    for(int i=0; i<8; ++i) {
        int A   = (i & 1);      // Least significant bit is A
        int B   = (i & 2) >> 1; // Next  significant bit is B
        int Cin = (i & 4) >> 2; // Most  significant bit is Cin
        std::cout << "  " << Cin << " " << B << " " << A << "     ";
        xl.input(1, A  ); b.input(1, A  );
        xl.input(2, B  ); b.input(2, B  );
        xr.input(2, Cin); a.input(2, Cin);
        std::cout << c.output() << " " << xr.output() << std::endl;
    }
}


