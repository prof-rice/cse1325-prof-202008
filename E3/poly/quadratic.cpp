#include "quadratic.h"
#include <cmath>

Quadratic::Quadratic(double a, double b, double c) : _a{a}, _b{b}, _c{c} { } // of form ax²+bx+c=0
Solution Quadratic::solve() {
    Solution s;
    double t = sqrt(_b*_b - 4*_a*_c);
    s.push_back((-_b + t) / (2*_a));
    s.push_back((-_b - t) / (2*_a));
    return s;
}
std::string Quadratic::to_string() const {
    return dtos(_a) + "x²" + dtos(_b) + "x" + dtos(_c);
}
