#ifndef __PAPER_H
#define __PAPER_H

#include <string>

class Paper {
  public:
    Paper(std::string text = "");
  private:
    std::string _text;
};
#endif

