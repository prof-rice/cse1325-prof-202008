#include "book.h"

Book::Book(int size) {
    Paper p;
    for(int i=0; i<size; ++i) _pages.push_back(p);
}
