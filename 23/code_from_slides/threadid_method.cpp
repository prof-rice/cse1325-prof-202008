#include <iostream>
#include <thread>

class Bobbin {
  public:
    // The method we want to execute on the new thread.
    void method1(std::string msg) {
        std::cout << "method1 says: " << msg << std::endl;
    }
};

int main() {
    // Instances our class
    Bobbin bobbin;

    // Constructs the new thread and runs it.
    std::thread t1{&Bobbin::method1, &bobbin, "Hello"};
    std::cout << "Thread 1 ID is " << std::hex << t1.get_id() << std::endl;

    // Makes the main thread wait for the new thread to finish execution, 
    // therefore blocks its own execution.
    t1.join();

}

