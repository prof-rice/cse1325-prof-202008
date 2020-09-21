#include <ostream>
#include "02_student.h"

Student::Student(std::string name, double gpa) : Person{name}, _gpa{gpa} { }

std::string Student::to_string() const {return _name + " (" + std::to_string(_gpa) + ")";}

