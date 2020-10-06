#ifndef __TRAVEL_H
#define __TRAVEL_H


#include "book.h"

typedef std::string Destination;

class Travel : public Book {
  public:
    Travel(std::string title, int stock_number, std::string destination);
    std::string to_string() override;
  private:
    Destination _destination;
};

#endif
