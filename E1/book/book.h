#ifndef __BOOK_H
#define __BOOK_H

#include <string>

class Book {
  public:
    Book(std::string title, int stock_number);
    virtual std::string to_string();
  protected:
    std::string _title;
  private:
    int _stock_number;
};


#endif
