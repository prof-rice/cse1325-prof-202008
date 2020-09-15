#include <iostream>

class Foo {
  public:
    Foo(int value);
    int value();
    void set(int value);
  private:
    int *_value;
};

Foo::Foo(int value) : _value{new int{value}} { }

int Foo::value() {return *_value;}

void Foo::set(int value) {*_value = value;}

int main() {
    Foo foo{3};
    std::cout << &foo << " -> " << foo.value() << std::endl;

    // Question: Will this compile (does a copy constructor exist?)?
    // Question: What will be the result?
    Foo foo2{foo};
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

    foo2.set(7);
    std::cout << &foo << " -> " << foo.value() << std::endl;
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;
}
