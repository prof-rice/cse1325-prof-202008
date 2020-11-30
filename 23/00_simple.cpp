#include <iostream>
#include <thread>

void task(std::string msg) {
    std::cout << "task says: " << msg << std::endl;
}

int main() {
    std::thread t{task, "Hello"};
    t.join();
}
