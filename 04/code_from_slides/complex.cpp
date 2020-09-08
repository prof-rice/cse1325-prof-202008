#include "complex.h"

#include <string>
#include <cmath>


// The static variable must be define in the .cpp
bool Complex::polar = false;

// Constructor definition (rectangular form)
// Note that we set the static polar to false,
//   so future to_string will be in rectangular form.
Complex::Complex(double re, double im) : _re{re}, _im{im} {
    polar = false;
}

// Empty destructor, since we have no clean up when
//   an object of type Complex is deleted.
// When empty, it is often omitted entirely.
Complex::~Complex() { }

// A factory function is similar to a constructor,
//   in that it instances and returns an object.
// In this case, we convert polar to rectangular form,
//   instance a complex object, and return it.
// We also force the static polar to true,
//   so future to_string will be in polar form.
Complex Polar(double r, Radians theta) {
    Complex c(r * cos(theta), r*sin(theta));
    Complex::polar = true;
    return c;
}

// The to_string method returns the object's string
//   representation in polar or rectangular form,
//   based on the last form used to instance an object.
std::string Complex::to_string() {
  if(polar) {
    double r = sqrt(_re*_re+_im*_im);
    Radians theta = atan(_im/_re);
    return std::to_string(r) + "(cos("
         + std::to_string(theta) + ")+i*sin("
         + std::to_string(theta) + "))";
  } else {
    return std::to_string(_re) + "+" +
           std::to_string(_im) + 'i';
  }      
}

void Complex::set_polar(bool p) {polar = p;}
bool Complex::get_polar() {return polar;}

