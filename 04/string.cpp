#include <iostream>

#include "string.h"

String::String() : String{""} { }

String::String(const char* text) {
    std::cerr << "### String(text)\n";
    _size = strlen(text);
    _text = new char[_size];
    strcpy(_text, text);
}

String::~String() {
    std::cerr << "### ~String()\n";
    delete[] _text;
} 

void String::print() {
    std::cout << _text;
}

int String::size() {
    return _size;
}

