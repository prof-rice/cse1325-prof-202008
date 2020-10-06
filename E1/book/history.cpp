#include "history.h"

History::History(std::string title, int stock_number, int year)
    : Book(title, stock_number), _year{year} { }
std::string History::to_string() {
    return Book::to_string() + " in the year " + std::to_string(_year);
}


