#include <ostream>
#include <istream>

enum class Month {Jan, Feb, Mar, Apr, May, Jun,
                  Jul, Aug, Sep, Oct, Nov, Dec};
std::ostream& operator<<(std::ostream& ost, const Month& month);
std::istream& operator>>(std::istream& is, Month& month); 
Month& operator++(Month& m); // Pre-increment
Month  operator++(Month& m, int); // Pre-increment (the parameter is ignored)
// operator== and != are pre-defined for enum classes

class Date {
  public:
    Date(int year, Month month, int day);
    Date();
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
    Date& operator++();    // Pre-increment
    Date  operator++(int); // Post-increment (the parameter is ignored)
    bool  operator==(const Date& date) const;
    bool  operator!=(const Date& date) const;
    bool  operator<(const Date& date) const;
    bool  operator<=(const Date& date) const;
    bool  operator>(const Date& date) const;
    bool  operator>=(const Date& date) const;
    Date  operator+(int n);   // Number of days past the current date
    Date& operator+=(int n);
  private:
    int   days_in_month(Month month, int year);
    int _year;
    Month _month;
    int _day;
};
Date operator+(int n, Date& date);  // Symmetry for Date::operator+(int n)
