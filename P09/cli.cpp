#include "store.h"
#include <iostream>
#include <vector>

std::string get_string(std::string prompt) {
    std::string s;
    std::cout << prompt;
    std::getline(std::cin, s);
    return s;
}

double get_double(std::string prompt) {
    while(true) {
        try {
            return std::stod(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}

int get_int(std::string prompt) {
    while(true) {
        try {
            return std::stoi(get_string(prompt));
        } catch(std::exception& e) {
            std::cerr << "ERROR: " << e.what() << std::endl;
        }
    }
}

Exposure get_exposure() {
    while(true) {
        switch (get_int("Select Exposure (1) Shade (2) Part Sun (3) Sun? ")) {
            case 1: return Exposure::SHADE;
            case 2: return Exposure::PARTSUN;
            case 3: return Exposure::SUN;
            default: std::cerr << "INVALID SELECTION\n" << std::endl;
        }
    }
}        
        
Material get_material() {
    while(true) {
        switch (get_int("Select Material (1) Rubber (2) Pine (3) Cedar (4) Hardwood? ")) {
            case 1: return Material::RUBBER;
            case 2: return Material::PINE;
            case 3: return Material::CEDAR;
            case 4: return Material::HARDWOOD;
            default: std::cerr << "INVALID SELECTION\n" << std::endl;
        }
    }
}        

int main() {
    std::vector<Product*> products;
    
    while(true) {
        switch (get_int("Create new (1) Tool (2) Plant (3) Mulch or (0) Exit? ")) {
            case 0: exit(0);
            case 1: products.push_back(new Tool(get_string("Name? "), get_double("Price? "), get_string("Description? "))); break;
            case 2: products.push_back(new Plant(get_string("Name? "), get_double("Price? "), get_string("Description? "),
                        get_string("Species? "), get_exposure())); break;
            case 3: products.push_back(new Mulch(get_string("Name? "), get_double("Price? "), get_string("Description? "),
                        get_int("Volume (ft³)? "), get_material())); break;
            default: std::cerr << "ERROR: Invalid option\n";
        }
        std::cout << "\nCurrent Catalog\n===============\n";
        for(auto product : products) std::cout << *product << "\n\n";
    }
}
