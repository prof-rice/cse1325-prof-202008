#include <iostream>
#include <thread>

// The function we want to execute on the new thread.
void task1(std::string msg) {
    std::cout << "task1 says: " << msg << std::endl;
}

int main() {
    // Constructs the new thread and runs it. Does not block execution.
    std::thread t1{task1, "Hello"};
    std::cout << "Thread 1 ID is " << std::hex << t1.get_id() << std::endl;

    // Makes the main thread wait for the new thread to finish execution, 
    // therefore blocks its own execution.
    t1.join();

}

