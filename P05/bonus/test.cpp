#include "and.h"
#include "or.h"

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

    // Test 1 - OR
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
    
    // Test 3 - AND or AND
    {
        And a;
        And b;
        Or c;
        a.connect(c, 1); // connect output of a to pin 1 input of c
        b.connect(c, 2); // connect output of b to pin 2 input of c
        tvec.clear();
        tvec = {{0, 0, 0, 0, 0}, {0, 0, 0, 1, 0}, {0, 0, 1, 0, 0}, {0, 0, 1, 1, 1},
                {0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 1, 1, 0, 0}, {0, 1, 1, 1, 1},
                {1, 0, 0, 0, 0}, {1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}, {1, 0, 1, 1, 1},
                {1, 1, 0, 0, 1}, {1, 1, 0, 1, 1}, {1, 1, 1, 0, 1}, {1, 1, 1, 1, 1}, 
        };
        for (Testvector t : tvec) {
            a.input(1, t[0]);
            a.input(2, t[1]);
            b.input(1, t[2]);
            b.input(2, t[3]);
            if(c.output() != t[4]) {
                result |= testnum;
                std::cerr << "FAIL on AND or AND: (" 
                          << t[0] << " & " << t[1] << ") | (" << t[2] << " & " << t[3]
                          << ") = " << t[4] << " not " << c.output() << std::endl;
            }
        }
    }
    testnum <<= 1;
    
    if (result) std::cerr << "\nFAILED: Return code is " << result << std::endl;
    return result;
}


