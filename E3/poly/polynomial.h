#ifndef __POLYNOMIAL_H
#define __POLYNOMIAL_H

#include <vector>
#include <ostream>

typedef std::vector<double> Solution;

class Polynomial {
  public:
    virtual Solution solve() = 0;
    virtual std::string to_string() const = 0;
  protected:
    std::string dtos(double d) const;
};

std::ostream& operator<<(std::ostream& ost, const Polynomial& p);

#endif
