CXXFLAGS = --std=c++17 -g

menu:
	@echo "  type 'make all' to make all demos (except bad_code)"
	@echo " "
	@echo "  type 'make cc_and_cao1' to demonstrate copy constructors and operators"
	@echo "  type 'make cc_and_cao2' to demonstrate the problem with defaults"
	@echo " "
	@echo "  type 'make regex' to demonstrate regular expressions"
	@echo "  type 'make good_area' to avoid throwing an exception (return 0)"
	@echo "  type 'make bad_area' to throw exception and report to cerr"
	@echo "  type 'make log_area' to log area calls to cerr"
	@echo "  type 'make bad_area_cout' to throw custom exception and report to cout"
	@echo "  type 'make bad_area_assert' to use the cassert library instead of an exception"
	@echo "  type 'make bad_code' to generate numerous errors from badly written code"
	@echo "  type 'make out_of_range' to demo C++ NOT throwing an exception on invalid vector access"
	@echo "  type 'make int_max' to demo C++ NOT throwing an exception on math overflow"
	@echo "  type 'make test_area' to build regression tests for the Area class"
	@echo "  NOTE: All code is built with 'hooks' for the ddd debugger"

cc_and_cao1: cc_and_cao1.cpp
	$(CXX) $(CXXFLAGS) -o cc_and_cao1 cc_and_cao1.cpp

cc_and_cao2: cc_and_cao2.cpp
	$(CXX) $(CXXFLAGS) -o cc_and_cao2 cc_and_cao2.cpp

good_area: good_area.cpp
	$(CXX) $(CXXFLAGS) -o good_area good_area.cpp

bad_area: bad_area.cpp
	$(CXX) $(CXXFLAGS) -o bad_area bad_area.cpp

log_area: log_area.cpp
	$(CXX) $(CXXFLAGS) -DLOGGER -o log_area log_area.cpp

bad_area_cout: bad_area_cout.cpp
	$(CXX) $(CXXFLAGS) -o bad_area_cout bad_area_cout.cpp

bad_area_assert: bad_area_assert.cpp
	$(CXX) $(CXXFLAGS) -o bad_area_assert bad_area_assert.cpp

bad_code: bad_code.cpp
	$(CXX) $(CXXFLAGS) -o bad_code bad_code.cpp

out_of_range: out_of_range.cpp
	$(CXX) $(CXXFLAGS) -o out_of_range out_of_range.cpp

int_max: int_max.cpp
	$(CXX) $(CXXFLAGS) -o int_max int_max.cpp

regex: regex.cpp
	$(CXX) $(CXXFLAGS) -o regex regex.cpp

test_area: test_area.cpp
	$(CXX) $(CXXFLAGS) -o test_area test_area.cpp

all: cc_and_cao1 cc_and_cao2 good_area bad_area log_area bad_area_cout bad_area_assert out_of_range int_max regex test_area
	
clean:
	-rm -f *.o *~ cc_and_cao1 cc_and_cao2 good_area bad_area log_area bad_area_cout bad_area_assert bad_code out_of_range int_max regex test_area 
