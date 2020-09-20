#ifndef __CHECKOUT_H
#define __CHECKOUT_H

#include "book.h"
#include "patron.h"

class Checkout {
  public:
    Checkout(Patron& patron, Book& book);
  private:
    Patron& _patron;
    Book& _book;
};
#endif
