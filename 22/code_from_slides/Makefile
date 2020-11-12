CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: alls

debug: CXXFLAGS += -g
debug: alls

regex: regex.cpp
	-$(CXX) $(CXXFLAGS) regex.cpp -o regex
regex_gtkmm_int: regex_gtkmm_int.cpp
	-$(CXX) $(CXXFLAGS) regex_gtkmm_int.cpp $(GTKFLAGS) -o regex_gtkmm_int
regex_gtkmm_phone: regex_gtkmm_phone.cpp
	-$(CXX) $(CXXFLAGS) regex_gtkmm_phone.cpp $(GTKFLAGS) -o regex_gtkmm_phone

alls:  regex regex_gtkmm_int regex_gtkmm_phone

clean:
	rm -f *.o *.gch a.out  regex regex_gtkmm_int regex_gtkmm_phone

