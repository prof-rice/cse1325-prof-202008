#include <iostream>
#include "00_person.h"

int main() {
    Person p{"Professor Rice"};
    std::cout << p.to_string() << std::endl;
}
