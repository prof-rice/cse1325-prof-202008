CXXFLAGS = --std=c++17 -pthread

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

00_simple: 00_simple.cpp
	-$(CXX) $(CXXFLAGS) -o 00_simple 00_simple.cpp
	@printf "Now type ./00_simple to execute the result\n\n"

01_method: 01_method.cpp
	-$(CXX) $(CXXFLAGS) -o 01_method 01_method.cpp
	@printf "Now type ./01_method to execute the result\n\n"

02_lambda: 02_lambda.cpp
	-$(CXX) $(CXXFLAGS) -o 02_lambda 02_lambda.cpp
	@printf "Now type ./02_lambda to execute the result\n\n"

03_sleep: 03_sleep.cpp
	-$(CXX) $(CXXFLAGS) -o 03_sleep 03_sleep.cpp
	@printf "Now type ./03_sleep to execute the result\n\n"

04_taskid: 04_taskid.cpp
	-$(CXX) $(CXXFLAGS) -o 04_taskid 04_taskid.cpp
	@printf "Now type ./04_taskid to execute the result\n\n"

10_cores: 10_cores.cpp
	-$(CXX) $(CXXFLAGS) -o 10_cores 10_cores.cpp
	@printf "Now type ./10_cores to execute the result\n\n"

all:  00_simple 01_method 02_lambda 03_sleep 04_taskid 10_cores

clean:
	rm -f *.o *.gch a.out  00_simple 01_method 02_lambda 03_sleep 04_taskid 10_cores

