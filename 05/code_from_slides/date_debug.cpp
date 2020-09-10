#include "date.h"
#include <map>
#include <vector>
#include <exception>
#include <regex>

Date::Date(int year, Month month, int day) : _year{year}, _month{month}, _day{day} {
    if (1 > day || day > days_in_month(month, year)) 
        throw std::runtime_error{"Invalid day: " + std::to_string(day)};
}
Date::Date() : Date{1970, Month::Jan, 1} { }

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << date._day << " " << date._month << ", " << date._year;
  return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
  is >> date._day; 
  is >> date._month;
  is >> date._year;
  if (1 > date._day || date._day > date.days_in_month(date._month, date._year)) 
      throw std::runtime_error{"Invalid day: " + std::to_string(date._day)};
  return is;
}

Date& Date::operator++() {    // Pre-increment
  ++_day;
  if (_day > days_in_month(_month, _year)) {
    if (_month == Month::Dec) {
      ++_year;
    }
    ++_month;
    _day = 1;
  }
  return *this;
}
Date Date::operator++(int) { // Post-increment (the parameter is ignored)
   Date date{*this};
   ++*this;
   return date;
}

bool Date::operator==(const Date& date) const {
    return (_day == date._day) 
        && (_month == date._month) 
        && (_year == date._year); 
}
bool Date::operator!=(const Date& date) const {
    return !(*this == date);
}

bool Date::operator<(const Date& date) const {
    return  (_year <  date._year) || 
           ((_year == date._year) && (_month <  date._month)) ||
           ((_year == date._year) && (_month == date._month)  && (_day < date._day));
}
bool Date::operator> (const Date& date) const {return  (date < *this);}
bool Date::operator<=(const Date& date) const {return !(date < *this);}
bool Date::operator>=(const Date& date) const {return !(*this < date);}

Date Date::operator+(int n){  // Number of days past the current date
    Date d{*this};
    d += n;
    return d;
}
Date operator+(int n, Date& date) {return date + n;} // Symmetry

Date& Date::operator+=(int n){    // Compound
    for ( ; n>0; --n) ++(*this);  // Horribly inefficient for large n!
    return *this;
}

int Date::days_in_month(Month month, int year) {
  std::map<Month, int> _days_in_month =
  {
     {Month::Jan, 31},
     {Month::Feb, ((year%400==0) || (year%4==0 && year%100!=0)) ? 29 : 28},
     {Month::Mar, 31},
     {Month::Apr, 30},
     {Month::May, 31},
     {Month::Jun, 30},
     {Month::Jul, 31},
     {Month::Aug, 31},
     {Month::Sep, 30},
     {Month::Oct, 31},
     {Month::Nov, 30},
     {Month::Dec, 31},
  };
  return _days_in_month[month];
}
// ///////////////////////////////////////////////////////////
// MONTH
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

// Function converts a regex exception code into English
std::string regex_error(std::regex_constants::error_type etype) {
    switch (etype) {
    case std::regex_constants::error_collate:
        return "error_collate: invalid collating element request";
    case std::regex_constants::error_ctype:
        return "error_ctype: invalid character class";
    case std::regex_constants::error_escape:
        return "error_escape: invalid escape character or trailing escape";
    case std::regex_constants::error_backref:
        return "error_backref: invalid back reference";
    case std::regex_constants::error_brack:
        return "error_brack: mismatched bracket([ or ])";
    case std::regex_constants::error_paren:
        return "error_paren: mismatched parentheses(( or ))";
    case std::regex_constants::error_brace:
        return "error_brace: mismatched brace({ or })";
    case std::regex_constants::error_badbrace:
        return "error_badbrace: invalid range inside a { }";
    case std::regex_constants::error_range:
        return "erro_range: invalid character range(e.g., [z-a])";
    case std::regex_constants::error_space:
        return "error_space: insufficient memory to handle this regular expression";
    case std::regex_constants::error_badrepeat:
        return "error_badrepeat: a repetition character (*, ?, +, or {) was not preceded by a valid regular expression";
    case std::regex_constants::error_complexity:
        return "error_complexity: the requested match is too complex";
    case std::regex_constants::error_stack:
        return "error_stack: insufficient memory to evaluate a match";
    default:
        return "";
    }
}

std::istream& operator>>(std::istream& is, Month& month) {
  class month_record{
    public: 
      std::regex rx;
      Month month; 
  };

  std::vector<month_record> month_records;
  try {
      month_records =  {
          {std::regex{R"(([Jj]an(uary)?(,)?)|1(,)?)"},   Month::Jan},
          {std::regex{R"(([Ff]eb(uary)?(,)?)|2(,)?)"},   Month::Feb},
          {std::regex{R"(([Mm]ar()ch?(,)?)|3(,)?)"},     Month::Mar},
          {std::regex{R"(([Aa]pr(il)?(,)?)|4(,)?)"},     Month::Apr},
          {std::regex{R"(([Mm]ay(,)?)|5(,)?)"},          Month::May},
          {std::regex{R"(([Jj]un(e)?(,)?)|6(,)?)"},      Month::Jun},
          {std::regex{R"(([Jj]ul(y)?(,)?)|7(,)?)"},      Month::Jul},
          {std::regex{R"(([Aa]ug(ust)?(,)?)|8(,)?)"},    Month::Aug},
          {std::regex{R"(([Ss]ep(tember)?(,)?)|9(,)?)"}, Month::Sep},
          {std::regex{R"(([Oo]ct(ober)?(,)?)|10(,)?)"},  Month::Oct},
          {std::regex{R"(([Nn]ov(ember)?(,)?)|11(,)?)"}, Month::Nov},
          {std::regex{R"(([Dd]ec(ember)?(,)?)|12(,)?)"}, Month::Dec},
      };
  } catch (std::regex_error e) {
      std::string regex_error{e.what()};
      throw std::runtime_error("Regex error: " + regex_error 
                                         + ' ' + regex_error(e.code()));
  }
  std::string s; 
  is >> s;
  for(auto mr : month_records) {
      if (std::regex_match(s, mr.rx)) {month = mr.month; s.clear(); break;}
  }
  if (!s.empty()) 
      throw std::runtime_error{"Invalid month: " + s};
  return is;
}

Month& operator++(Month& m) {   // Pre-increment, e.g., ++m
  switch(m) {
    case Month::Jan: m = Month::Feb; break;
    case Month::Feb: m = Month::Mar; break;
    case Month::Mar: m = Month::Apr; break;
    case Month::Apr: m = Month::May; break;
    case Month::May: m = Month::Jun; break;
    case Month::Jun: m = Month::Jul; break;
    case Month::Jul: m = Month::Aug; break;
    case Month::Aug: m = Month::Sep; break;
    case Month::Sep: m = Month::Oct; break;
    case Month::Oct: m = Month::Nov; break;
    case Month::Nov: m = Month::Dec; break;
    case Month::Dec: m = Month::Jan; break;
  }
  return m;
}

Month operator++(Month& m, int) {  // Post-increment, e.g., m++
  Month result{m};
  ++m;
  return result;
}

