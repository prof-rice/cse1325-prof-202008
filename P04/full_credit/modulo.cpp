#include "modulo.h"

Modulo::Modulo(int modulo, int value, int offset) 
    : _value{value % modulo}, _modulo{modulo}, _offset{offset}, _nmsd{nullptr} {
    _value = (_value - _offset) % _modulo;
}
void Modulo::set_nmsd(Modulo* nmsd) {
    _nmsd = nmsd;
    // std::cout << "nmsd = " << nmsd << std::endl;
}
int Modulo::value() {return _value + _offset;}

// Operators

Modulo& Modulo::operator+=(const int rhs) {
    int sum = _value + rhs;
    if((sum >= _modulo) && _nmsd) (*_nmsd) += (sum / _modulo);
    _value = sum % _modulo;
    return *this;
}
Modulo Modulo::operator+(const int rhs) {
    Modulo m{*this};
    m += rhs;
    return m;
}
Modulo& Modulo::operator++() {
    *this += 1;
    return *this;
}
Modulo Modulo::operator++(int) {
    Modulo m{*this};
    ++*this;
    return m;
}

int Modulo::compare(const int rhs) {
    int i = _value + _offset; // compare what the caller sees, not internal value
    return (i > rhs) ? 1 : ((i < rhs) ? -1 : 0);
}    

// Input / Output

std::ostream& operator<<(std::ostream& ost, const Modulo& m) {
    ost << (m._value + m._offset);
    return ost;
}
std::istream& operator>>(std::istream& ist, Modulo& m) {
    ist >> m._value;
    m._value = (m._value - m._offset) % m._modulo;
    return ist;
}

