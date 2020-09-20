#include "checkout.h"

Checkout::Checkout(Patron& patron, Book& book)
    : _patron{patron}, _book{book} { }
