#ifndef __PERSON_H
#define __PERSON_H

#include <string>

class Person {
  public:
    Person(std::string name);
  protected:
    std::string _name;
};
#endif
