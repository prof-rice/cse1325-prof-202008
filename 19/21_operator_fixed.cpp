#include <iostream>

class Base {
  public:
    Base(std::string s) : _s{s} { }
    virtual std::ostream& print(std::ostream& ost) const;
    friend std::ostream& operator<<(std::ostream& ost, const Base& base);
  private:
    std::string _s;
};

std::ostream& Base::print(std::ostream& ost) const {
    ost << _s;
    return ost;
}

std::ostream& operator<<(std::ostream& ost, const Base& base) {
    return base.print(ost);
}

class Derived : public Base {
  public:
    Derived(std::string s, std::string t) : Base{s}, _t{t} { }
    virtual std::ostream& print(std::ostream& ost) const;
    // friend std::ostream& operator<<(std::ostream& ost, const Derived& derived);
  private:
    std::string _t;
};

std::ostream& Derived::print(std::ostream& ost) const {
    ost << static_cast<Base>(*this) << ' ' << _t;
    return ost;
}

// std::ostream& operator<<(std::ostream& ost, const Derived& derived) {
//    ost << static_cast<Base>(derived) << ' ' << derived._t;
//    return ost;
// }

int main() {
    Base b{"Hello"};
    std::cout << b << std::endl;
    Derived d{"Hi", "World"};
    std::cout << d << std::endl;
    Base& br = d;
    std::cout << br << std::endl;
}
