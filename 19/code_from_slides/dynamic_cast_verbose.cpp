#include <iostream>
class Parent {
public:
  virtual ~Parent() {}  // polymorphic
};

class A : public Parent { };
class B : public Parent { };

int main()
{
  Parent* a = new A;

  B* b1 = (B*)(a);             // Compiles, but nonsense
  if (b1 == nullptr) std::cout << "b1 is null" << std::endl;

  B* b2 = static_cast<B*>(a);  // Compiles, but invalid - A is not a B
  if (b2 == nullptr) std::cout << "b2 is null" << std::endl;

  B* b3 = dynamic_cast<B*>(a); // ERROR - A is not a B
  if (b3 == nullptr) std::cout << "b3 is null" << std::endl;

/*
  Parent* p = &a;  // p points to an 'A' object

  // how dynamic cast works:
  A* dyn_a = dynamic_cast<A*>(p);  // dynamic_cast checks 'p' to make sure it points to an 'A'
     // it does, so this cast is safe.  dynamic_cast succeeds.


  B* dyn_b = dynamic_cast<B*>(p);  // dynamic_cast checks 'p'.  It will see that 'p' does not
    // point to a 'B', so this is a bad cast.  dynamic_cast will fail and dyn_b will be == nullptr


  // how static_cast works
  A* sta_a = static_cast<A*>(p);  // static_cast assumes the cast is good.  No runtime check
    // sta_a will be identical to dyn_a above

  B* sta_b = static_cast<B*>(p);  // static_cast assumes the cast is good... BUT IT ISN'T
    //  'p' does not point to a 'B', so this is a bad cast!  static_cast succeeds, resulting in
    //  'sta_b' being a BAD POINTER.  Dereferencing sta_b has undefined behavior.
*/
}
