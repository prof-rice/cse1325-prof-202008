#include "travel.h"

Travel::Travel(std::string title, int stock_number, std::string destination)
    : Book(title, stock_number), _destination{destination} { }
std::string Travel::to_string() {
    return Book::to_string() + " to " + _destination;
}


