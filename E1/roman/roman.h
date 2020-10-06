// Free Response 1a Suggested Solution

#ifndef __ROMAN_H
#define __ROMAN_H

#include <iostream>

const int MIN_ROMAN = 1;
const int I = 1;
const int V = 5;
const int X = 10;
const int MAX_ROMAN = 49;

class Roman {
  public:
    Roman();
    Roman(int value);
    Roman(std::string value);
    std::string roman() const; // Const not graded
    int value() const;         // Const not graded
  protected:
    void validate();
  private:
    int _value;
};

// NOT REQUIRED: Not indicated by part A question
std::ostream& operator<<(std::ostream& ost, const Roman& roman);
std::istream& operator>>(std::istream& ost, Roman& roman);
   
#endif
