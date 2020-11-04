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

Base get_copy() {return Derived{};}
Base& get_ref() {Derived* d = new Derived; return *d;}
Base* get_pointer() {return new Derived;}

int main() {
  Base base1 = get_copy();
  base1.foo();
  Base& base2 = get_ref();
  base2.foo();
  Base* base3 = get_pointer();
  base3->foo();
}
