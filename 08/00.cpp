
// ========== person.h

#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>

class Person {
  public:
    Person(std::string name);
    std::string to_string() const;
  private:
    std::string _name;
};
#endif

// ========== person.cpp

#include <ostream>
#include "00_person.h"

Person::Person(std::string name) : _name{name} { }

std::string Person::to_string() const {return _name;}


// ========== main.cpp

#include <iostream>
#include "00_person.h"

int main() {
    Person p{"Professor Rice"};
    std::cout << p.to_string() << std::endl;
}
