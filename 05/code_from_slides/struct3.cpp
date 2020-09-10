#include <iostream>
#include <exception>

struct Date {
    int year, month, day;
    Date(int year, int month, int day) {
        if (1 > month || month > 12) throw std::runtime_error{"Invalid month"};
        if (1 > day   ||   day > 31) throw std::runtime_error{"Invalid day"};
        year = year;
        month = month;
        day = day;
    }
};

int main() {
    Date birthday{1950, 12, 30};
    birthday.month = 14;
    std::cout << birthday.month << '/' 
              << birthday.day   << '/' 
              << birthday.year  << std::endl;
}
