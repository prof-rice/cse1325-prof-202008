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
  Base base;
  base.foo();
  Derived derived;
  derived.foo();
  base = Derived{};
  base.foo();
}
