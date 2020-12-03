#ifndef __LINEAR_H
#define __LINEAR_H

#include "polynomial.h"

class Linear : public Polynomial {
  public:
    Linear(double a, double b); // of form ax+b=0
    Solution solve() override;
    std::string to_string() const override;
  private:
    double _a;
    double _b;
};

#endif
