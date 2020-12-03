#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

class Grades {
  public:
    Grades(std::string student) : _student{student} { }
    std::string student() {return _student;}
    void add_grade(double grade) {_grades.push_back(grade);}
    
    // Permit grades to be iterated over, e.g., for (auto d : _grades) ...
    typedef std::vector<double>::iterator iterator;
    typedef std::vector<double>::const_iterator  const_iterator;
    iterator begin() {return _grades.begin();}
    iterator end() {return _grades.end();}
  private:
    std::string _student;
    std::vector<double> _grades;
};

// calculate the average of doubles pointed to by iterators (begin, end]
double average(Grades::iterator begin, Grades::iterator end) {
    double sum = 0;
    for(auto it=begin; it<end; ++it) sum += *it;
    return sum / std::distance(begin, end);
}

int main() {
    // This creates a function that returns a double between 60.0 and 100.0
    std::default_random_engine re;
    std::uniform_real_distribution<double> unif(60.0, 100.0);
    
    // Assign Jose between 5 and 15 random grades
    Grades grades{"Jose"};
    std::cout << "Grades added: ";
    int num_grades = 5 + std::rand()%10;
    for(int i=0; i<num_grades; ++i) { 
        double d = unif(re);
        std::cout << d << ' ';
        grades.add_grade(d);
    }
    
    // Calculate straight average (MUST use iterators - it's all you have!)
    std::cout << "\nFor student " << grades.student() << ":\n";
    std::cout << "  Average w/o  drop is " << average(grades.begin(), grades.end()) << std::endl;
        
    // Calculate average with one drop grade
    std::sort(grades.begin(), grades.end());
    std::cout << "  Average with drop is " << average(grades.begin()+1, grades.end()) << std::endl;
}
