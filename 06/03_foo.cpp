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

    // The default copy constructor copies values - the *address* of the int
    Foo foo2{foo};
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

    foo2.set(7);
    std::cout << &foo << " -> " << foo.value() << std::endl;
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

    // Similarly, the default assignment operator (=) copies values, as well
    Foo foo3{-1};
    foo3 = foo2;
    foo3.set(13); // And what happens to the memory allocated by the foo3 
                  // constructor at this assignment? LEAKED!
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;
}
