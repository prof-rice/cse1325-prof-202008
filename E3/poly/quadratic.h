#ifndef __QUADRATIC_H
#define __QUADRATIC_H

#include "polynomial.h"

class Quadratic : public Polynomial {
  public:
    Quadratic(double a, double b, double c); // of form ax²+bx+c=0
    Solution solve() override;
    std::string to_string() const override;
  private:
    double _a;
    double _b;
    double _c;
};

#endif
