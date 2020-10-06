#ifndef __TEXTBOOK_H
#define __TEXTBOOK_H


#include "book.h"

class Textbook : public Book {
  public:
    Textbook(std::string title, int stock_number, std::string dept, int aclass);
    std::string to_string() override;
  private:
    std::string _dept;
    int _class;
};

#endif
