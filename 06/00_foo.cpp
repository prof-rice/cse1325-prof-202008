#include <iostream>

class Foo {
  public:
    Foo(int value);
    int value();
  private:
    int *_value;
};

Foo::Foo(int value) : _value{new int{value}} { }

int Foo::value() {return *_value;}

int main() {
    Foo foo{3};
    std::cout << &foo << " -> " << foo.value() << std::endl;
    Foo foo2{3};
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

}
