#include "and.h"
#include "or.h"
#include "xor.h"

#include <iostream>
#include <vector>

typedef std::vector<Signal> Testvector;
typedef std::vector<Testvector> Testvectors;

int main() {

    int result = 0;
    int testnum = 1;

    Testvectors tvec;

    // Test 1 - AND
    {
        And a;
        tvec.clear();
        tvec = {{0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 1}};
        for (Testvector t : tvec) {
            a.input(1, t[0]);
            a.input(2, t[1]);
            if(a.output() != t[2]) {
                result |= testnum;
                std::cerr << "FAIL on AND: " << t[0] << " & " << t[1] 
                          << " = " << t[2] << " not " << a.output() << std::endl;
            }
        }
    }
    testnum <<= 1;

    // Test 2 - OR
    {
        Or a;
        tvec.clear();
        tvec = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1}};
        for (Testvector t : tvec) {
            a.input(1, t[0]);
            a.input(2, t[1]);
            if(a.output() != t[2]) {
                result |= testnum;
                std::cerr << "FAIL on OR: " << t[0] << " | " << t[1] 
                          << " = " << t[2] << " not " << a.output() << std::endl;
            }
        }
    }
    testnum <<= 1;
    
    // Test 3 - XOR
    {
        Xor a;
        tvec.clear();
        tvec = {{0, 0, 0}, {0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
        for (Testvector t : tvec) {
            a.input(1, t[0]);
            a.input(2, t[1]);
            if(a.output() != t[2]) {
                result |= testnum;
                std::cerr << "FAIL on XOR: " << t[0] << " ^ " << t[1] 
                          << " = " << t[2] << " not " << a.output() << std::endl;
            }
        }
    }
    testnum <<= 1;
    
    // Test 3 - AND or AND
    {
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

        tvec.clear();
        tvec = {{0, 0, 0, 0, 0}, {0, 0, 1, 0, 1}, {0, 1, 0, 0, 1}, {0, 1, 1, 1, 0},
                {1, 0, 0, 0, 1}, {1, 0, 1, 1, 0}, {1, 1, 0, 1, 0}, {1, 1, 1, 1, 1},
        };
        for (Testvector t : tvec) {
            xl.input(1, t[2]); b.input(1, t[2]); // A
            xl.input(2, t[1]); b.input(2, t[1]); // B
            xr.input(2, t[0]); a.input(2, t[0]); // Cin

            if((c.output() != t[3]) || (xr.output() != t[4])) {
                result |= testnum;
                std::cerr << "FAIL on Full Adder: (" 
                          << t[0] << " + " << t[1] << " + " << t[2] << " = " << t[3] << " " << t[4]
                          << " not " << c.output() << " " << xr.output() << std::endl;
            }
        }
    }
    testnum <<= 1;
    
    if (result) std::cerr << "\nFAILED: Return code is " << result << std::endl;
    return result;
}


