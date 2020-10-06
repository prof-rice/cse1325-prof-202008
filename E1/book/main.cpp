#include "mystery.h"
#include "textbook.h"
#include "history.h"
#include "travel.h"
#include <iostream>

int main() {
    Mystery m{"The Caves of Steel", 42, "Elijah Baley"};
        std::cout << m.to_string() << std::endl;
    Textbook t{"Programming in C++", 256, "CSE", 1325};
        std::cout << t.to_string() << std::endl;
    History h{"The Killer Angels", 1024, 1863};
        std::cout << h.to_string() << std::endl;
    Travel v{"Paris Travel Guide", 1, "Paris"};
        std::cout << v.to_string() << std::endl;
}
