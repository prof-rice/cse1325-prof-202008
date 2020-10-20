#include <iostream>
#include <fstream>
#include <vector>

class Reading { // a temperature reading
    public:
        Reading(int hour, double temp)
            : _hour{hour}, _temp{temp} {validate();}
        Reading() : Reading(0,0) { }
        int hour() {return _hour;}
        double temp() {return _temp;}
        friend std::istream& operator>>(std::istream  &ist, Reading& reading);
    private:
        void validate() {
          if (_hour < 0 || 23 < _hour) 
              throw std::runtime_error("Invalid hour: " + std::to_string(_hour));
        }
        int _hour;       // 0 to 23 GMT
        double _temp;    // Celsius
};
std::istream& operator>>(std::istream& ist, Reading& reading) {
  ist >> reading._hour >> reading._temp;
  reading.validate();
  return ist;
}

class Readings {
  public:
    Readings(std::istream& ist) {
        Reading reading;
        while(ist >> reading) _readings.push_back(reading);
    }
    int size() {return _readings.size();}
    Reading reading(int index) {return _readings[index];}
    std::string graph() {
        std::string s;
        for(int i=0; i<_readings.size(); ++i) {
            Reading& r = _readings[i];
            s += ((r.hour() < 10) ? "0" : "") + std::to_string(r.hour()) + ' ';
            for (int j=0; j<r.temp()/2; j++) s += '#';
            s += '\n';
        }
        return s;
    }

  private:
    std::vector<Reading> _readings;
};

int main() {
    std::string s;
    std::cout << "Enter the filename for the temperature log: ";
    std::cin >> s;
    std::ifstream ifs{s};
    if (!ifs) throw std::runtime_error{"Invalid filename: " + s};
    Readings readings{ifs};
    std::cout << readings.graph();
}

