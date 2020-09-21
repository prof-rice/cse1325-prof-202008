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
