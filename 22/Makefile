CXXFLAGS += --std=c++17

all: alls

debug: CXXFLAGS += -g
debug: alls


main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main
    
00_exception: 00_exception.cpp
	-$(CXX) $(CXXFLAGS) 00_exception.cpp -o 00_exception
01_exception: 01_exception.cpp
	-$(CXX) $(CXXFLAGS) 01_exception.cpp -o 01_exception
02_exception: 02_exception.cpp
	-$(CXX) $(CXXFLAGS) 02_exception.cpp -o 02_exception
03_exception: 03_exception.cpp
	-$(CXX) $(CXXFLAGS) 03_exception.cpp -o 03_exception
04_exception: 04_exception.cpp
	-$(CXX) $(CXXFLAGS) 04_exception.cpp -o 04_exception
05_exception: 05_exception.cpp
	-$(CXX) $(CXXFLAGS) 05_exception.cpp -o 05_exception
10_rot13: 10_rot13.cpp
	-$(CXX) $(CXXFLAGS) 10_rot13.cpp -o 10_rot13
11_custom_except: 11_custom_except.cpp
	-$(CXX) $(CXXFLAGS) 11_custom_except.cpp -o 11_custom_except
string: string.cpp
	-$(CXX) $(CXXFLAGS) string.cpp -o string

alls:  00_exception 01_exception 02_exception 03_exception 04_exception 05_exception 10_rot13 11_custom_except string main

clean:
	rm -f *.o *.gch a.out  00_exception 01_exception 02_exception 03_exception 04_exception 05_exception 10_rot13 11_custom_except string main

