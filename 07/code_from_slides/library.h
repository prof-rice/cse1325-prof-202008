#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <vector>
#include "book.h"

class Library {
  public:
    void add_book(Book& book);
  private:
    std::vector<Book*> _books;
};
#endif

