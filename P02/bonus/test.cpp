// This main program can be used to test your class.
// The provide Makefile will build it for you if you type 'make test'.

#include "die.h"
#include <iostream>
#include <ctime> // for time

int main() {
    srand (time(NULL));
    for(int sides : {4, 6, 8, 12, 20}) {
        Die die{sides};
        std::cout << "d" << sides << ": ";
        for(int i=0; i<20; ++i) {
            die.roll();
            std::cout << die.value() << ' ';
        }
        std::cout << std::endl;
    }
}
