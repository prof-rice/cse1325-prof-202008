#include <iostream>

class Base {
  public:
    virtual void foo() {
      std::cout << "Base" << std::endl;
    }
};

class Derived : public Base {
  public:
    void foo() override {
      std::cout << "Derived" << std::endl;
    }
};

int main() {
  Base* base = new Base;
  base->foo();
  Derived* derived = new Derived;
  derived->foo();
  base = new Derived;
  base->foo();
}
