#include<iostream>
 
class A {
  public: A() { std::cout << "A's constructor called" << std::endl;}
};
 
class B {
  public: B() {std::cout << "B's constructor called" << std::endl;}
};
 
class C: public A, public B {
  public: C() {std::cout << "C's constructor called" << std::endl;}
};
 
int main() {
    C c;
}
