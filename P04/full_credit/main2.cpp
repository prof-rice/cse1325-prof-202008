#include "modulo.h"
#include <iomanip>

int main() {
    Modulo hours{12, 0, 1};    // US hours are modulo 12 with offset 1 (i.e., values are 1 to 12)
    std::cout << "Initial value of hours?   ";
    std::cin >> hours;

    Modulo minutes{60};        // Minutes are modulo 60
    std::cout << "Initial value of minutes? ";
    std::cin >> minutes;

    Modulo seconds{60};         // Seconds are modulo 60
    std::cout << "Initial value of seconds? ";
    std::cin >> seconds;
    
    seconds.set_nmsd(&minutes); // Next most significant digit from seconds is minutes, so xx:15:11 o'clock
    minutes.set_nmsd(&hours);   // Next most significant digit from minutes is hours, so 10:15:11 o'clock

    int step; 
    std::cout << "Step by how many seconds per tic? ";
    std::cin  >> step;
    
    int iterations;
    std::cout << "How many iterations? ";
    std::cin >> iterations;
    
    std::cout << "\nFrom " << hours << ':' << minutes << ':' << seconds << " counting by " << step << " seconds for " << iterations << " iterations\n\n";

    Modulo columns{10};  // Newline every 10 times - look, another use for Modulo!
    
    std::cout << std::setfill('0'); // Use leading 0s to keep time display consistent
    while(iterations--) {
        // The carry from seconds will roll to minutes; the carry from minutes will roll to hours; hours will roll back to 1
        seconds += step; 
        std::cout << std::setw(2) << hours << ':' << std::setw(2) << minutes << ':' << std::setw(2) << seconds << ", ";
        if (++columns == 0) std::cout << '\n'; // Newline every 10 times
    }
    std::cout << std::endl;
}
