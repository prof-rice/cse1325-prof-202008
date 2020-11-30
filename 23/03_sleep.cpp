#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <vector>

class Bobbin {
  public:
    void task(char name, std::string msg) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand()%2000));
        std::cout << name << " says: " << msg << "   "; std::cout.flush();
    }
};

int main() {
    const std::string names {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::vector<std::thread*> threads;
    for (char c : names) {
        threads.push_back(new std::thread{[c] {Bobbin b; b.task(c, "Hi!");}});
    }
    for(auto& t : threads) t->join();
    std::cout << std::endl;
}
