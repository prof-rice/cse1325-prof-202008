#ifndef __STRING_H
#define __STRING_H

#include <cstring>

class String {
  public:
    String();
    String(const char* text);
    ~String();  // NOT called on exit()
    void print();
    int size();
  private:
    char* _text;
    int _size;
};

#endif

