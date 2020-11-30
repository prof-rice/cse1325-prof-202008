#include <iostream>
#include <thread>

class Bobbin {
  public:
    void task(std::string msg) {
        std::cout << "task says: " << msg << std::endl;
    }
};

int main() {
    Bobbin bobbin;
    std::thread t{&Bobbin::task, &bobbin, "Hello"};
    t.join();
}
