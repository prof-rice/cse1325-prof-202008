#include <iostream>

class Base {
  public:
    Base(std::string s) : _s{s} { }
    friend std::ostream& operator<<(std::ostream& ost, const Base& base);
  private:
    std::string _s;
};

std::ostream& operator<<(std::ostream& ost, const Base& base) {
    ost << base._s;
    return ost;
}

class Derived : public Base {
  public:
    Derived(std::string s, std::string t) : Base{s}, _t{t} { }
    friend std::ostream& operator<<(std::ostream& ost, const Derived& derived);
  private:
    std::string _t;
};

std::ostream& operator<<(std::ostream& ost, const Derived& derived) {
    ost << static_cast<Base>(derived) << ' ' << derived._t;
    return ost;
}

int main() {
    Base b{"Hello"};
    std::cout << b << std::endl;
    Derived d{"Hi", "World"};
    std::cout << d << std::endl;
    Base& br = d;
    std::cout << br << std::endl;
}
