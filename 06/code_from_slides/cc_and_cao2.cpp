#include <iostream>

class Foo {
    int _val;
  public:
    Foo(int val) : _val{val} {} // Non-default constructor
    Foo() : Foo(0) {}           // Default constructor
    int val() {return _val;}
};

int main() {
  Foo bar0;           // Default constructor
  std::cout << "bar0 = " << bar0.val() << std::endl;
  Foo bar1{1};        // Non-default constructor
  std::cout << "bar1 = " << bar1.val() << std::endl;
  Foo bar2{bar1};     // Default copy constructor for initialization 
  // Foo bar2 = bar1; // Exactly the same thing: bar2 has same values as bar1
  std::cout << "bar2 = " << bar2.val() << std::endl;
  bar0 = bar1;        // Default copy assignment for assignment
  std::cout << "bar0 now = " << bar0.val() << std::endl;
}
