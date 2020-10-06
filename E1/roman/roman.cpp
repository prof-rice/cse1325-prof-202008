#include "roman.h"

/*

0. Must operator<< and operator>> be friends with Roman?

1. Write header file based on class diagram

2. Write Roman::Roman(std::string value)     3. Roman::value() const
         Roman::Roman(int value)                Roman::roman() const
         
4: Write operator<<(std::ostream& ost, const Roman& roman)
         operator>>(std::istream& ist, Roman& roman)
         
*/


Roman::Roman() : Roman(MIN_ROMAN) { }

// ======== 1b & 1c OPTION 1 ========

// Free Response 1b Suggested Solution
Roman::Roman(std::string value) : _value{0} {
     for(char c : value) {
         if(c == 'I') _value += I;
         else if(c == 'V') _value += V;
         else if(c == 'X') _value += X;
         else throw std::out_of_range{"Invalid digit: " + c};
     }
     validate();
}

// Free Response 1c Suggested Solution
int Roman::value() const {return _value;}

// ======== 1b & 1c OPTION 2 ========

// Free Response 1b Suggested Solution
Roman::Roman(int value) : _value{value} {
    validate();
}
void Roman::validate() {
    if(MIN_ROMAN > _value || _value > MAX_ROMAN) 
        throw std::out_of_range{"Invalid value: " + std::to_string(_value)};
}

// Free Response 1c Suggested Solution
std::string Roman::roman() const {
    std::string result;
    int value{_value};
    while(value >= X) {value -= X; result += 'X';}
    while(value >= V) {value -= V; result += 'V';}
    while(value >= I) {value -= I; result += 'I';}
    return result;
}

// ======== 1d OPTION 1 ========

// Free Response 1d Suggested Solution


std::ostream& operator<<(std::ostream& ost, const Roman& roman) {
    ost << roman.roman();
    return ost;
}

// ======== 1d OPTION 2 ========

// Free Response 1d Suggested Solution

std::istream& operator>>(std::istream& ist, Roman& roman) {
    std::string s;
    ist >> s;
    roman = Roman{s};
    return ist;
} 
 
