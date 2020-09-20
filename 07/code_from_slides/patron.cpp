#include "patron.h"

void Patron::add_library(Library& library) {
    _libraries.push_back(&library);
}
