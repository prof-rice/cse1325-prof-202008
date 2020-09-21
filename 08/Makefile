CXXFLAGS += --std=c++17

all:  00_main 01_main 03_main 04_main 10_main 11_main
	@printf "\n02_main.cpp includes an intention error, and has been skipped\nType 'make 02_main' to see the error\n\n"

log: CXXFLAGS += -DLOGGER
log: all

00_main: 00_main.cpp
	-$(CXX) $(CXXFLAGS) 00_*.cpp -o 00_main

01_main: 01_main.cpp
	-$(CXX) $(CXXFLAGS) 01_*.cpp -o 01_main

02_main: 02_main.cpp
	-$(CXX) $(CXXFLAGS) 02_*.cpp -o 02_main

03_main: 03_main.cpp
	-$(CXX) $(CXXFLAGS) 03_*.cpp -o 03_main

04_main: 04_main.cpp
	-$(CXX) $(CXXFLAGS) 04_*.cpp -o 04_main

10_main: 10_main.cpp
	-$(CXX) $(CXXFLAGS) 10_*.cpp -o 10_main

11_main: 11_main.cpp
	-$(CXX) $(CXXFLAGS) 11_*.cpp -o 11_main

clean:
	rm -f *.o *.gch a.out ??_main

