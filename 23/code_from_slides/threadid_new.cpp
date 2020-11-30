#include <iostream>
#include <thread>

class Bobbin {
  public:
    // The method we want to execute on the new thread.
    void method1(std::string msg) {
        std::cout << "method1 says: " << msg << std::endl;
    }
};

// The function we want to execute on the new thread.
void function1(std::string msg) {
    std::cout << "function1 says: " << msg << std::endl;
}

int main() {
    // Instances our class
    Bobbin bobbin;

    // Constructs the new thread and runs it.
    std::thread c1{&Bobbin::method1, &bobbin, "Hello"};
    std::cout << "function1 ID is " << std::hex << c1.get_id() << std::endl;

    // Constructs the new thread and runs it. Does not block execution.
    std::thread f1{function1, "Hello"};
    std::cout << "method1 ID is " << std::hex << f1.get_id() << std::endl;

    // Makes the main thread wait for the new threads to finish execution, 
    // therefore blocks its own execution.
    c1.join();
    f1.join();    
}

