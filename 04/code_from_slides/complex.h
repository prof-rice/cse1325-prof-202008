#ifndef __COMPLEX_H
#define __COMPLEX_H
#include <string>

typedef double Radians;

// Manages complex numbers
class Complex {
  public:
    Complex(double re, double im);
    ~Complex();
    friend Complex Polar(double r, Radians theta);
    std::string to_string();
    static void set_polar(bool p);
    static bool get_polar();
  private:
    double _re, _im;
    static bool polar;
};
// Factory pattern: "Instance" a double with polar coordinates.
// This pattern enables us to define "constructors" for a class
//   with a different name and behavior than a proper constructor.
Complex Polar(double r, Radians theta);

#endif
