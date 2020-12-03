#include "linear.h"

Linear::Linear(double a, double b) : _a{a}, _b{b} { } // of form ax+b=0
Solution Linear::solve() {
    Solution s;
    s.push_back(-_b / _a);
    return s;
}
std::string Linear::to_string() const {
    return dtos(_a) + "x" + dtos(_b);
}

