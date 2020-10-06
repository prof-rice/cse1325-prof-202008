#ifndef __MYSTERY_H
#define __MYSTERY_H


#include "book.h"

class Mystery : public Book {
  public:
    Mystery(std::string title, int stock_number, std::string detective);
    std::string to_string() override;
  private:
    std::string _detective;
};

#endif
