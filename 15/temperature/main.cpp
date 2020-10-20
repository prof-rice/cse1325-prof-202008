#include "readings.h"
#include <iostream>
#include <fstream>

int main() {
    std::string s;
    std::cout << "Enter the filename for the temperature log [temps.txt]: ";
    std::getline(std::cin, s);
    if (s.size() == 0) s = "temps.txt";

    std::ifstream ifs{s};
    if (!ifs) throw std::runtime_error{"Invalid filename: " + s};

    Readings readings{ifs};
    std::cout << readings.graph() << std::endl;
}

