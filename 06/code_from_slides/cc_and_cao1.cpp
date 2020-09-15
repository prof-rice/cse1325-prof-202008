#include <iostream>

class Foo {
    int* _val;
  public:
    Foo(int val) : _val{new int{val}} {}               // Non-default constructor
    Foo() : Foo(0) {}                                  // Default constructor (delegated)
    Foo(const Foo &rhs) : _val{new int{*rhs.get()}} {} // Copy constructor
    Foo& operator=(const Foo &rhs) {                   // Copy assignment
      if (this != &rhs) _val = new int{*rhs.get()};
      return *this;
    }
    ~Foo() {delete _val;}                              // Destructor
    int* get() const {return _val;}                    // Getter
    void set(int* v) {*_val = *v;}                     // Setter
};

int main() {
    Foo foo1{new int{42}};                             // Non-default constructor
    Foo foo2{foo1};                                    // Copy constructor
    Foo foo3;                                          // Default constructor

    // Test default constructor
    if (*foo3.get() != 0) std::cerr << "foo3 default constructor set value to " 
                                     << *foo3.get() << std::endl;

    foo3 = foo1;                                       // Copy assignment
 
    // Test non-default constructor
    if (*foo1.get() != 42) std::cerr << "foo1 set to 42 but is now " 
                                     << *foo1.get() << std::endl;

    // This shoudl NOT modify foo2 or foo3!
    int i = 17;
    foo1.set(&i);

    // Test copy constructor
    if (*foo2.get() != 42) std::cerr << "foo2 changed from 42 to " 
                                     << *foo2.get() << std::endl;

    // Test copy assignment operator
    if (*foo3.get() != 42) std::cerr << "foo3 changed from 42 to " 
                                     << *foo3.get() << std::endl;
}
