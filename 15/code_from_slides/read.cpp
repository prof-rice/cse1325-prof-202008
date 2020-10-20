#include <iostream>
#include <fstream>

int main() {
    // Open file read.cpp for reading
    std::ifstream ist{"read.cpp"};	
    if (!ist) throw std::runtime_error{"can’t open input file read.cpp"};

    // Stream the file contents to std::cout
    std::string s;
    while (std::getline(ist, s)) std::cout << s << std::endl;
}
