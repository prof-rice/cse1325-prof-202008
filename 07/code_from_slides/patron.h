#ifndef __PATRON_H
#define __PATRON_H

#include <vector>
#include "person.h"
#include "library.h"

class Patron : public Person {
  public:
    void add_library(Library& library);
  protected:
    // We *inherit* #name : std::string from Person!
  private:
    std::vector<Library*> _libraries;
};
#endif
