#include "roman.h"

int main() {
    Roman r;
    int i;
    
    while(true) {
        std::cout << "Enter Roman number (X V I only): ";
        std::cin >> r;
        std::cout << r << " is " << r.value() << " in decimal!" << std::endl;
        
        std::cout << "Enter a decimal number between " << MIN_ROMAN << " and " << MAX_ROMAN << ": ";
        std::cin >> i;
        std::cout << i << " is " << Roman{i} << " in Roman numerals!" << std::endl;
    }
}
