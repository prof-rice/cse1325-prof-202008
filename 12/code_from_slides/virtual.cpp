#include <iostream>

class Base {
  public:
    Base() {std::cout << "  Base Constructor\n";}
    virtual ~Base() {std::cout << "  Base Destructor\n";}
    virtual void print() {std::cout << "  Base" << std::endl;}
};

class Derived : public Base {
  public:
    Derived() {std::cout << "  Derived Constructor\n";}
    ~Derived() {std::cout << "  Derived Destructor\n";}
    void print() {std::cout << "  Derived" << std::endl;}
};

int main() {
    std::cout << "Base b;\n";
    Base b;
    
    std::cout << "Base* bp = new Derived();\n";
    Base* bp = new Derived();

    std::cout << "b.print();\n";
    b.print();

    std::cout << "bp->print();\n";
    bp->print();
    
    std::cout << "delete bp;\n";
    delete bp;
    
    std::cout << "End of main\n";
}
