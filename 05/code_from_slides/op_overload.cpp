#include <iostream>
#include <ostream>
#include <exception>
#include <map>

enum class Month {Jan, Feb, Mar, Apr, May, Jun,
                  Jul, Aug, Sep, Oct, Nov, Dec};

std::ostream& operator<<(std::ostream& ost, const Month& month) {
  std::map<Month, std::string> month_to_str =
  {
     {Month::Jan, "January"},
     {Month::Feb, "February"},
     {Month::Mar, "March"},
     {Month::Apr, "April"},
     {Month::May, "May"},
     {Month::Jun, "June"},
     {Month::Jul, "July"},
     {Month::Aug, "August"},
     {Month::Sep, "September"},
     {Month::Oct, "October"},
     {Month::Nov, "November"},
     {Month::Dec, "December"},
  };
  ost << month_to_str[month];
  return ost;
}

class Date {
  public:
    Date(int year, Month month, int day) : _year{year}, _month{month}, _day{day} {
        if (1 > day || day > 31) throw std::runtime_error{"Invalid day"};
    }
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
  private:
    int _year;
    Month _month;
    int _day;
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date._day << " " << date._month << ", " << date._year;
  return os;
}

int main() {
    Date birthday{1950, Month::Dec, 30};
    std::cout << birthday << std::endl;
}
