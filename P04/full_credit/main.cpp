#include "modulo.h"
#include <iomanip>

int main() {
    Modulo minutes{60, 15};   // Minutes are modulo 60, initialize to xx:15 o'clock
    Modulo hours{12, 10, 1};  // US hours are modulo 12, initalize to 10:xx o'clock, add 1 for << (i.e., show 1 .. 12)
    minutes.set_nmsd(&hours); // Next most significant digit from minutes is hours, so 10:15 o'clock

    const int step = 23;         // Count by 23 minutes at a time, modulo 60
    std::cout << "From " << hours << ':' << minutes << " counting by " << step << "\n\n";

    while (hours != 2) {
        minutes += step;             // Count using integers - roll overs will be added to hours
        std::cout << hours << ':' << std::setw(2) << std::setfill('0') << minutes << ", ";
    }
    std::cout << std::endl;
}
