#include "textbook.h"

Textbook::Textbook(std::string title, int stock_number, std::string dept, int aclass)
    : Book(title, stock_number), _dept{dept}, _class{aclass} { }
std::string Textbook::to_string() {
    return Book::to_string() + " for " + _dept + std::to_string(_class);
}


