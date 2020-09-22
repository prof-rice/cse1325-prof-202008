#ifndef _MODULO_H
#define _MODULO_H

#include <iostream>

class Modulo {
  public:
    Modulo(int modulo = 10, int value = 0, int offset = 0);
    void set_nmsd(Modulo* nmsd); 
    int value();
    Modulo& operator+=(const int rhs);
    Modulo operator+(const int rhs);
    Modulo& operator++();
    Modulo operator++(int);
    inline bool operator==(const int rhs) {return (compare(rhs) == 0);}
    inline bool operator!=(const int rhs) {return (compare(rhs) != 0);}
    inline bool operator< (const int rhs) {return (compare(rhs) <  0);}
    inline bool operator<=(const int rhs) {return (compare(rhs) <= 0);}
    inline bool operator> (const int rhs) {return (compare(rhs) >  0);}
    inline bool operator>=(const int rhs) {return (compare(rhs) >= 0);} 
    friend std::ostream& operator<<(std::ostream& ost, const Modulo& m);
    friend std::istream& operator>>(std::istream& ist, Modulo& m);
  private:
    int compare(const int rhs);  // Perform all comparisons
    
    int _value;
    int _modulo;
    int _offset;
    Modulo* _nmsd;  // Next most  significant digit ("carry")
};
#endif
