#include "readings.h"
#include <sstream>

Readings::Readings(std::istream& ist) {
    Reading reading;
    ist.exceptions(ist.exceptions() | std::ios_base::badbit); // exception on bad()
    while(ist >> reading) _readings.push_back(reading);
    if (ist.eof()) return;
    // if (ist.bad()) throw std::runtime_error("Cannot read data file");
    if (ist.fail()) {
        ist.clear();          // Clear fail condition
        char c; ist >> c;     // Read the next char
        if (c == 'q') return; // OK - ended with a 'q'
        ist.unget();          // Put the char back into the buffer
        ist.clear(std::ios_base::failbit);  // Set ist back to fail()
        throw std::runtime_error("Invalid character in data file");
    }
}

int Readings::size() {return _readings.size();}
Reading Readings::reading(int index) {return _readings[index];}

/*
// First, naive attempt - can't use Reading::operator<< because we must return a string
std::string Readings::graph() {
    std::string s;
    for(auto r : _readings) {
        s += std::to_string(r.hour()) + ": " 
           + std::to_string(r.temp()) + ' ';
        for (int j=0; j<r.temp()/2; j++) s += '#';
        s += '\n';
    }
    return s;
}

// Second attempt 
std::string Readings::graph() {
    std::string s;
    for(auto r : _readings) {
        std::string h = std::to_string(reading._hour);
        while (h.size() < 2) h = " " + h;
        std::string t = std::to_string(reading._temp);
        while (t.size() < 6) t = " " + t;
        s += h + ": " + ' ';
        for (int j=0; j<r.temp()/2; j++) s += '#';
        s += '\n';
    }
    return s;
}


// Third attempt - just show the (manually formatted) hour
std::string Readings::graph() {
    std::string s;
    for(auto r : _readings) {
        s += ((r.hour() < 10) ? "0" : "") + std::to_string(r.hour()) + ' ';
        for (int j=0; j<r.temp()/2; j++) s += '#';
        s += '\n';
    }
    return s;
}

*/
// Final attempt - works great!
std::string Readings::graph() {
    std::ostringstream oss;
    for(auto r : _readings) {
        oss << r << ' ';
        for (int j=0; j<r.temp()/2; j++) oss << '#';
        oss << '\n';
    }
    return oss.str();
}

