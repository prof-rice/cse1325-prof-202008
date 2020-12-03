#include "linear.h"
#include "quadratic.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::vector<Polynomial*> poly;
    
    // Push polynomial constants   
    poly.push_back(new Linear{5,10});
    poly.push_back(new Quadratic{1,-2, -3});
    
    // Load polynomials from a file
    std::string s;
    std::ifstream ifs{"poly.txt"};
    while(std::getline(ifs, s)) {
        std::istringstream iss{s};
        double a, b, c;
        iss >> a >> b;
        if(iss >> c) poly.push_back(new Quadratic{a,b, c});
        else poly.push_back(new Linear{a,b});
    }
    
    // Solve all polynomials in vector poly
    for (Polynomial* p : poly) {
        std::cout << "For " << *p << ", x = ";
        for(double s : p->solve()) std::cout << s << ' ';
        std::cout << std:: endl;
    }
}
