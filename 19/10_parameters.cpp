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

void print_copy(Base base) {base.foo();}
void print_ref(Base& base) {base.foo();}
void print_pointer(Base* base) {base->foo();}

int main() {
  Base base;
  print_copy(base);
  print_ref(base);
  print_pointer(&base);
  Derived derived;
  print_copy(derived);
  print_ref(derived);
  print_pointer(&derived);
}
