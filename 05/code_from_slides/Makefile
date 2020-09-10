CXXFLAGS = --std=c++17

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

auto_compare: auto_compare.cpp
	-$(CXX) $(CXXFLAGS) -o auto_compare auto_compare.cpp
	@printf "Now type ./auto_compare to execute the result\n\n"

class: class.cpp
	-$(CXX) $(CXXFLAGS) -o class class.cpp
	@printf "Now type ./class to execute the result\n\n"

enum_class2: enum_class2.cpp
	-$(CXX) $(CXXFLAGS) -o enum_class2 enum_class2.cpp
	@printf "Now type ./enum_class2 to execute the result\n\n"

enum_class_bad: enum_class_bad.cpp
	-$(CXX) $(CXXFLAGS) -o enum_class_bad enum_class_bad.cpp
	@printf "Now type ./enum_class_bad to execute the result\n\n"

enum_class: enum_class.cpp
	-$(CXX) $(CXXFLAGS) -o enum_class enum_class.cpp
	@printf "Now type ./enum_class to execute the result\n\n"

enum_class_map: enum_class_map.cpp
	-$(CXX) $(CXXFLAGS) -o enum_class_map enum_class_map.cpp
	@printf "Now type ./enum_class_map to execute the result\n\n"

enum_class_no_constructor: enum_class_no_constructor.cpp
	-$(CXX) $(CXXFLAGS) -o enum_class_no_constructor enum_class_no_constructor.cpp
	@printf "Now type ./enum_class_no_constructor to execute the result\n\n"

op_overload: op_overload.cpp
	-$(CXX) $(CXXFLAGS) -o op_overload op_overload.cpp
	@printf "Now type ./op_overload to execute the result\n\n"

op_overload2: op_overload2.cpp date.cpp *.h
	-$(CXX) $(CXXFLAGS) -o op_overload2 op_overload2.cpp date.cpp
	@printf "Now type ./op_overload2 to execute the result\n\n"

op_overload3: op_overload3.cpp date.cpp *.h
	-$(CXX) $(CXXFLAGS) -o op_overload3 op_overload3.cpp date.cpp
	@printf "Now type ./op_overload3 to execute the result\n\n"

op_overload4: op_overload4.cpp date_spaceship.cpp *.h
	-$(CXX) $(CXXFLAGS) -o op_overload4 op_overload4.cpp date_spaceship.cpp
	@printf "Now type ./op_overload4 to execute the result\n\n"

struct1: struct1.cpp
	-$(CXX) $(CXXFLAGS) -o struct1 struct1.cpp
	@printf "Now type ./struct1 to execute the result\n\n"

struct2: struct2.cpp
	-$(CXX) $(CXXFLAGS) -o struct2 struct2.cpp
	@printf "Now type ./struct2 to execute the result\n\n"

struct3: struct3.cpp
	-$(CXX) $(CXXFLAGS) -o struct3 struct3.cpp
	@printf "Now type ./struct3 to execute the result\n\n"

test_enums: test_enums.cpp
	-$(CXX) $(CXXFLAGS) -o test_enums test_enums.cpp
	@printf "Now type ./test_enums to execute the result\n\n"

all:  class enum_class2 enum_class enum_class_map enum_class_no_constructor op_overload2 op_overload3 op_overload struct1 struct2 struct3 

clean:
	rm -f *.o *.gch a.out  auto_compare class enum_class2 enum_class enum_class_map enum_class_no_constructor op_overload2 op_overload3 op_overload4 op_overload struct1 struct2 struct3 

