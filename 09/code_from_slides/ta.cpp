#include <iostream>
#include <ostream>

class Person { 
  public: 
    Person(std::string name, int id) : _name{name}, _id{id}  { 
        notify("Person");
    }
    friend std::ostream& operator<<(std::ostream& ost, Person& person);
  protected:
    Person() : Person("", 0) { }
    void notify(std::string classname) {
        std::cout << classname << ' ' << *this << " constructed" << std::endl;
    }
  private:
    std::string _name;
    int _id;
};
std::ostream& operator<<(std::ostream& ost, Person& person) {
    ost << person._name << " (" << person._id << ')';
    return ost;
}
  
class Faculty : virtual public Person { 
    double _salary;
public: 
    Faculty(std::string name, int id, double salary) : Person(name, id), _salary{salary} { 
       notify("Faculty"); 
    } 
}; 
  
class Student : virtual public Person { 
    double _gpa; 
public: 
    Student(std::string name, int id, double gpa) : Person(name, id), _gpa{gpa} { 
        notify("Student");
    }
}; 
  
class TA : public Faculty, public Student  { 
public: 
    TA(std::string name, int id, double salary, double gpa) 
        : Person(name, id), Student(name, id, gpa), Faculty(name, id, salary) { 
        notify("TA");
    } 
}; 
  
int main()  { 
    TA ta("Wang Fang", 100032918, 14.50, 3.92);
    std::cout << "Our TA is " << ta << std::endl;
} 
