#include <iostream>

class Foo {
  public:
    // Only initialization lists can prevent an attempted construction
    //   of a reference with no assignment
  // Foo(int& i) {_i = i; }   // Compile ERROR
     Foo(int& i) : _i{i} { }  // Works!
    int& i() {return _i;}
  private:
    int& _i;
};

int main() {
    int i = 42;
    Foo foo{i};
    std::cout << foo.i() << std::endl;
}
