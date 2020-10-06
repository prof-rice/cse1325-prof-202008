#include "book.h"

Book::Book(std::string title, int stock_number)
    : _title{title}, _stock_number{stock_number} { }
std::string Book::to_string() {
    return _title + " (" + std::to_string(_stock_number) + ")";
}

