#include <iostream>
#include <ctime> // for time

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
    
    for(int r=0; r<rolls; ++r) {
        int sum=0;
        std::cout << "Roll " << r << ": ";
        for(int d=0; d<num_dice; ++d) {
            int value = 1 + rand()%faces;
            std::cout << value << ' ';
            sum += value;
        }
        std::cout << "Sum: " << sum << std::endl;
    }
}
