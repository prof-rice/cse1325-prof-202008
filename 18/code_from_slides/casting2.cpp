#include <iostream>
#include <vector>

int main() {
    std::vector<std::string>* v = new std::vector<std::string>
        {"This", "will", "end", "bady"};

    // C-style (unsafe) cast – compiles but ends badly
    std::string* s = (std::string*)(v);
    std::cout << *s << std::endl;

    // C++-style static cast - generates a compile error, avoiding disaster
    // std::string* s2 = static_cast<std::string*>(v);

    // Evading C++-style static_cast's protection with void* (BAD idea!)
    void* v3 = v;
    std::string* s3 = static_cast<std::string*>(v3);
    std::cout << *s3 << std::endl;
}
