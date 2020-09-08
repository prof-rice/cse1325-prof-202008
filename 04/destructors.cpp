#include <iostream>
#include "string.h"

int main() {
    std::string s = "Hello, World ";
    for(char a='a'; a<='d'; ++a) {
        s += a;
        String text{s.c_str()};
        text.print();
        std::cout << "\nSize for " << a << " is " << text.size() << std::endl;
    }

    String t;
    t.print();
    std::cout << "\nSize for t is " << t.size() << std::endl;
}

