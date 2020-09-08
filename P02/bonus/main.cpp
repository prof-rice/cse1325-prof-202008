#include <iostream>
#include <ctime> // for time
#include <vector>
#include "die.h"

int main() {
    srand (time(NULL));
    
    int num_dice;
    int faces;
    int rolls;
    
    std::cout << "Number of dice? ";
    std::cin >> num_dice;
    std::cout << "Number of faces per die? ";
    std::cin >> faces;
    std::cout << "Number of rolls? ";
    std::cin >> rolls;
    
    std::vector<Die> dice;
    for(int i=0; i<num_dice; ++i) dice.push_back(Die{faces});
    
    for(int r=0; r<rolls; ++r) {
        int sum=0;
        std::cout << "Roll " << r << ": ";
        for(Die d : dice) {
            d.roll();
            std::cout << d.value() << ' ';
            sum += d.value();
        }
        std::cout << "Sum: " << sum << std::endl;
    }
}
