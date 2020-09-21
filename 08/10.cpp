#ifndef __PERSON_H
#define __PERSON_H

#include <ostream>
#include "logger.h"

class Person {
  public:
    Person(std::string name);
    virtual std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& ost, const Person& person);
  protected:
    std::string _name;
};
#endif
#include <ostream>
#include "10_person.h"

Person::Person(std::string name) : _name{name} {LOG("Person::Person(" + name + ")");}

std::string Person::to_string() const {return _name;}

std::ostream& operator<<(std::ostream& ost, const Person& person) {
    ost << person._name;
    return ost;
}

#ifndef __STUDENT_H
#define __STUDENT_H

#include <ostream>
#include "10_person.h"

class Student : public Person {
  public:
    Student(std::string name, double gpa);
    std::string to_string() const override;
    friend std::ostream& operator<<(std::ostream& ost, const Student& student);
  private:
    double _gpa;
};
#endif
#include <ostream>
#include "10_student.h"

Student::Student(std::string name, double gpa) : Person{name}, _gpa{gpa} {
LOG("Student::Student(" + name + "," + std::to_string(gpa) + ")");}

std::string Student::to_string() const {return _name + " (" + std::to_string(_gpa) + ")";}

std::ostream& operator<<(std::ostream& ost, const Student& student) {
    ost << (Person)student << " (" << student._gpa << ")";
    return ost;
}

#include <iostream>
#include "10_student.h"

int main() {
    Person p{"Professor Rice"};
//  std::cout << p.to_string() << std::endl;
    std::cout << p << std::endl;
    Student s{"Encyclopedia Brown", 4.0};
//  std::cout << s.to_string() << std::endl;
    std::cout << s << std::endl;
}
