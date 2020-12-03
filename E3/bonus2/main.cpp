#include <iostream>

class Bonus : public std::exception {
  public:
    const char* what() const noexcept override {
        return "Three points!";
    }
};

int main() {
    try {
        throw Bonus();
    } catch(Bonus& e) {
        std::cout << e.what() << std::endl;
    }
}
