#include "mystery.h"

Mystery::Mystery(std::string title, int stock_number, std::string detective)
    : Book(title, stock_number), _detective{detective} { }
std::string Mystery::to_string() {
    return Book::to_string() + " with Detective " + _detective;
}


