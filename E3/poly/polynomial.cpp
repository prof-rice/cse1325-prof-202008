#include "polynomial.h"
#include <sstream>
#include <iomanip>

std::ostream& operator<<(std::ostream& ost, const Polynomial& p) {
    ost << p.to_string();
    return ost;
}    
std::string Polynomial::dtos(double d) const {
    std::ostringstream oss;
    oss << std::setprecision(8) << std::noshowpoint << std::showpos << d;
    return oss.str();
}
