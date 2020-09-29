#include "and.h"
#include "or.h"

#include <iostream>

int main() {
    And a;
    And b;
    Or c;
    a.connect(c, 1); // connect output of a to pin 1 input of c
    b.connect(c, 2); // connect output of b to pin 2 input of c

    std::cout << "A B C D  Q\n= = = =  =\n";
    for(int i=0; i<16; ++i) {
        a.input(1, (i & 8) != 0); std::cout << a.input(1) << " ";
        a.input(2, (i & 4) != 0); std::cout << a.input(2) << " ";
        b.input(1, (i & 2) != 0); std::cout << b.input(1) << " ";
        b.input(2, (i & 1) != 0); std::cout << b.input(2) << "  ";
        std::cout << c.output() << std::endl;
    }
}


