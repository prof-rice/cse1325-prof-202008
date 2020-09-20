#ifndef __BOOK_H
#define __BOOK_H

#include <vector>
#include "paper.h"

class Book {
  public:
    Book(int size);
  private:
    std::vector<Paper> _pages;
};
#endif

