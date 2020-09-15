#include <iostream>

class Foo {
  public:
    Foo(int value);
    Foo(Foo& foo);
    ~Foo();
    Foo& operator=(const Foo& rhs);
    int value();
    void set(int value);
  private:
    int *_value;
};

Foo::Foo(int value) : _value{new int{value}} { }

//////////////////////////// Rule of 3 ////////////////////////////
// If you need a custom copy constructor, copy assignment operator,
//   OR destructor, you probably need all 3!
//////////////////////////// Rule of 3 ////////////////////////////

Foo::Foo(Foo& foo) : _value{new int{*(foo._value)}} { }

Foo& Foo::operator=(const Foo& rhs) {
    if (this != &rhs) _value = new int{*(rhs._value)};
    return *this;
}

Foo::~Foo() {delete _value;}

///////////////////////////////////////////////////////////////////

int Foo::value() {return *_value;}

void Foo::set(int value) {*_value = value;}

////////////

int main() {
    Foo foo{3};
    std::cout << &foo << " -> " << foo.value() << std::endl;

    // The CUSTOM copy constructor allocates new heap and copies VALUES
    Foo foo2{foo};
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

    foo2.set(7);
    std::cout << &foo << " -> " << foo.value() << std::endl;
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;

    // Similarly, the custom assignment operator (=) does as well
    Foo foo3{-1};
    foo3 = foo2;
    foo3.set(13); // The custom destructor frees heap when the class destructs
    std::cout << &foo2 << " -> " << foo2.value() << std::endl;
}
