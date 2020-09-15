#include <iostream>

class Foo {
  public:
    // The Java way doesn't work with reference attributes
    Foo(int& i) {_i = i; }    // Compile ERROR
    int& i() {return _i;}
  private:
    int& _i;
};

int main() {
    int i = 42;
    Foo foo{i};
    std::cout << foo.i() << std::endl;
}
