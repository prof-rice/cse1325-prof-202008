#include <iostream>

// /////////// FIRST CLASS ///////////

class First {
  public:
    First(std::string a_string);
    std::string first_string();
  private:
    std::string s;
};

// Proper C++ construction with an intialization list
First::First(std::string a_string) : s{a_string} {}

std::string First::first_string() {
    return s;
}

// /////////// SECOND CLASS ///////////

class Second {
  public:
    Second(First f);
    std::string second_string();
  private:
    First first;
};

//
// IMPORTANT: Here's the "Java-like" constructor initialization
//            How's that working out for you?
Second::Second(First f) {
    first = f;
}

std::string Second::second_string() {return first.first_string();}

// /////////// MAIN FUNCTION ///////////

int main() {
    First f{"Initialization lists are important!\n"};
    Second s{f};
    std::cout << s.second_string() << std::endl;
}
