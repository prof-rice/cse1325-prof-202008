#include <iostream>
#include "complex.h"

int main() {
    // Instance and output a complex number 
    // with rectangular coords.
    Complex c1{3.0, 4.0};
    std::cout << c1.to_string() << " or ";

    // Instance a complex number with polar coords.
    // Now all output is in polar form.
    Complex c2 = Polar(10.0, 0.6435);
    std::cout << c1.to_string() << '\n'
              << c2.to_string() << " or ";

    // Instance a complex number with
    // rectangular coords, resetting output form.
    Complex::set_polar(false);
    std::cout << c2.to_string() << std::endl;
}
