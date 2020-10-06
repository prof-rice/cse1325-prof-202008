#ifndef __HISTORY_H
#define __HISTORY_H


#include "book.h"

class History : public Book {
  public:
    History(std::string title, int stock_number, int year);
    std::string to_string() override;
  private:
    int _year;
};

#endif
