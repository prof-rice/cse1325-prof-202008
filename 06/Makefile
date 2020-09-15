CXXFLAGS = --std=c++17

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

00_foo: 00_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 00_foo 00_foo.cpp
	@printf "Now type ./00_foo to execute the result\n\n"

01_foo: 01_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 01_foo 01_foo.cpp
	@printf "Now type ./01_foo to execute the result\n\n"

02_foo: 02_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 02_foo 02_foo.cpp
	@printf "Now type ./02_foo to execute the result\n\n"

03_foo: 03_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 03_foo 03_foo.cpp
	@printf "Now type ./03_foo to execute the result\n\n"

04_foo: 04_foo.cpp
	-$(CXX) $(CXXFLAGS) -o 04_foo 04_foo.cpp
	@printf "Now type ./04_foo to execute the result\n\n"

init_bad: init_bad.cpp
	@printf "==================================================\n"
	@printf "THIS COMPILE WILL FAIL. Try to understand why. :-)\n"
	@printf "See also init_good\n"
	@printf "==================================================\n\n"
	-$(CXX) $(CXXFLAGS) -o init_bad init_bad.cpp

init_good: init_good.cpp
	-$(CXX) $(CXXFLAGS) -o init_good init_good.cpp
	@printf "Now type ./init_good to execute the result\nSee also init_bad\n\n"

ref_attribute_bad: ref_attribute_bad.cpp
	@printf "==================================================\n"
	@printf "THIS COMPILE WILL FAIL. Try to understand why. :-)\n"
	@printf "See also ref_attribute_good\n"
	@printf "==================================================\n\n"
	-$(CXX) $(CXXFLAGS) -o ref_attribute_bad ref_attribute_bad.cpp

ref_attribute_good: ref_attribute_good.cpp
	-$(CXX) $(CXXFLAGS) -o ref_attribute_good ref_attribute_good.cpp
	@printf "Now type ./ref_attribute_good to execute the result\nSee also ref_attribute_bad\n\n"

all:  00_foo 01_foo 02_foo 03_foo 04_foo ref_attribute_good init_good ref_attribute_bad init_bad

clean:
	rm -f *.o *.gch a.out  00_foo 01_foo 02_foo 03_foo 04_foo ref_attribute_good init_good ref_attribute_bad init_bad

