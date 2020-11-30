#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>

// The function we want to execute on the new thread.
void task1(std::string msg) {
    std::this_thread::sleep_for(std::chrono::milliseconds(200+std::rand()%200));
    std::cout << "task1 says: " << msg << std::endl;
}

int main() {
    std::srand(std::time(NULL));

    std::thread t1(task1, "Hello");
    std::thread t2(task1, "Bonjour");
    std::thread t3(task1, "Hola");

    t1.join();
    t2.join();
    t3.join();
}

