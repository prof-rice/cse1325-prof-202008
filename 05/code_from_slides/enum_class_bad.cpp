#include <iostream>
#include <exception>

enum class Month {Jan, Feb, Mar, Apr, May, Jun,
                  Jul, Aug, Sep, Oct, Nov, Dec};

class Date {
  public:
    Date(int year, Month month, int day) 
        : _year{year}, _month{month}, _day{day} {
        // This is no longer required - can't supply invalid month!
        // if (1 > month || month > 12) throw std::runtime_error{"Invalid month"};
        if (1 > day   ||   day > 31) throw std::runtime_error{"Invalid day"};
    }
    void print_date() {
        // This no longer works - month is no longer an int!
        std::cout << _month << '/' << _day << '/' << _year << std::endl;
    }
  private:
    int _year;
    Month _month;
    int _day;
};

int main() {
    // Date birthday{1950, 12, 30};  // ERROR: 12 isn't a Month!
    Date birthday{1950, Month::Dec, 30};
    birthday.print_date();
}
