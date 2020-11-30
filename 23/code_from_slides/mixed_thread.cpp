#include <iostream>
#include <thread>
#include <chrono>
#include <ctime>
#include <iomanip>

class Bobbin {
  public:
    // The method we want to execute as a thread.
    void method1(std::string msg) {
        std::this_thread::sleep_for(std::chrono::seconds(1));  // wait 1 seconds
        std::cout << "Method1 says:   " << msg << std::endl;
    }
};
// The function we want to execute as a thread
void function1(std::string msg) {
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));  // wait 2 seconds
  std::cout << "Function1 says: " << msg << std::endl;
}
int main() {
  Bobbin bobbin;
  std::thread tf1{function1, "Hello, function!"}; // tf1 now running
  std::cout << std::hex << std::showbase 
            << "Function1 ID: " << tf1.get_id() << std::endl; // Print unique thread ID

  std::thread tm1{[&bobbin] {bobbin.method1("Hello, method!");}}; // method1 now running
  std::cout << "Method1 ID:   " << tm1.get_id() << std::endl; // Print unique thread ID

  tf1.join(); // wait for function1 to exit
  tm1.join(); // wait for method1 to exit
 }
