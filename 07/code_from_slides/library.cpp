#include "library.h"

void Library::add_book(Book& book) {
    _books.push_back(&book);
}
