#include <iostream>

enum Color { red, green, blue };                 // plain enum 
enum Currency { dollar, pound, yen };            // plain enum
enum class Horse { pony, clydesdale, mustang};   // enum class
enum class Car { mustang, tesla, model_t};       // enum class

int main() {

    Color color = Color::red;  // OK
    int num = color;           // OK but bad (color is not an int!)
    std::cout << (color == Currency::dollar) << std::endl;  // OK but REALLY bad

    Horse h = Horse::mustang;
    Car c = Car::mustang;

    int i = h;                           // error – h is not an int, but a Horse
    std::cout << (c == h) << std::endl;  // error – c and h are different mustang types
}
