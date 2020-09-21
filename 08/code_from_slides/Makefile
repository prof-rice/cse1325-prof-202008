CXXFLAGS += --std=c++17

# This is a menu unique to this particular Makefile
main:
	@echo "  'make all' builds all demos below (except pure_virtual_bad)"
	@echo "  'make debug' builds all demos below for the debugger"
	@echo "  'make clean' deletes all .o, .gch, and executable files"
	@echo " "
	@echo "  'make barnyard_simple' for generic critter sounds only"
	@echo "  'make barnyard_animals' for custom critter sounds via multiple vectors"
	@echo "  'make barnyard_animals_2' to show the generic critter sound exists in derived classes"
	@echo "  'make barnyard_animals_poly' for custom critter sounds via polymorphism (preview)"
	@echo " "
	@echo "  'make barnyard_animals_op_overload' to show the 'discards qualifiers' error"
	@echo "  'make barnyard_animals_op_overload_fixed' to show the corrected version"
	@echo "  'make barnyard_animals_pure_virtual' for the pure virtual base class"
	@echo " "
	@echo "  'make pure_virtual_bad' for the error of not implementing a pure virtual method"
	@echo "  'make pure_virtual_fixed' for properly implementing a pure virtual method"
	@echo " "
	@echo " "
	@echo "Remember the TAB key!  'make di[TAB]' is quick and easy!"
	@echo " "

all: barnyard_simple barnyard_animals barnyard_animals_2 barnyard_animals_poly barnyard_animals_op_overload_fixed barnyard_animals_pure_virtual pure_virtual_fixed 

# Build all demos with the debug option
debug: CXXFLAGS += -g
debug: all

barnyard_simple: barnyard_simple.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_simple barnyard_simple.o
barnyard_animals: barnyard_animals.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals barnyard_animals.o
barnyard_animals_poly: barnyard_animals_poly.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_poly barnyard_animals_poly.o
barnyard_animals_2: barnyard_animals_2.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_2 barnyard_animals_2.o
barnyard_override: barnyard_override.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_override barnyard_override.o
barnyard_animals_op_overload_fixed: barnyard_animals_op_overload_fixed.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_op_overload_fixed barnyard_animals_op_overload_fixed.o
barnyard_animals_pure_virtual: barnyard_animals_pure_virtual.o *.h
	$(CXX) $(CXXFLAGS) -o barnyard_animals_pure_virtual barnyard_animals_pure_virtual.o
mi: mi.o *.h
	$(CXX) $(CXXFLAGS) -o mi mi.o
ta: ta.o *.h
	$(CXX) $(CXXFLAGS) -o ta ta.o
ta_test: ta_test.o *.h
	$(CXX) $(CXXFLAGS) -o ta_test ta_test.o
diamond2: diamond2.o *.h
	$(CXX) $(CXXFLAGS) -o diamond2 diamond2.o
diamond_ambiguous: diamond_ambiguous.o *.h
	$(CXX) $(CXXFLAGS) -o diamond_ambiguous diamond_ambiguous.o
diamond_explicit: diamond_explicit.o *.h
	$(CXX) $(CXXFLAGS) -o diamond_explicit diamond_explicit.o
diamond2_explicit: diamond2_explicit.o *.h
	$(CXX) $(CXXFLAGS) -o diamond2_explicit diamond2_explicit.o
pure_virtual_fixed: pure_virtual_fixed.o *.h
	$(CXX) $(CXXFLAGS) -o pure_virtual_fixed pure_virtual_fixed.o

# Compile rules

barnyard_simple.o: barnyard_simple.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_simple.cpp
barnyard_animals.o: barnyard_animals.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals.cpp
barnyard_animals_poly.o: barnyard_animals_poly.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_poly.cpp
barnyard_animals_2.o: barnyard_animals_2.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_2.cpp
barnyard_override.o: barnyard_override.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_override.cpp
barnyard_animals_op_overload.o: barnyard_animals_op_overload.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_op_overload.cpp
barnyard_animals_op_overload_fixed.o: barnyard_animals_op_overload_fixed.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_op_overload_fixed.cpp
barnyard_animals_pure_virtual.o: barnyard_animals_pure_virtual.cpp *.h
	$(CXX) $(CXXFLAGS) -c barnyard_animals_pure_virtual.cpp
mi.o: mi.cpp *.h
	$(CXX) $(CXXFLAGS) -c mi.cpp
ta.o: ta.cpp *.h
	$(CXX) $(CXXFLAGS) -c ta.cpp
ta_test.o: ta_test.cpp *.h
	$(CXX) $(CXXFLAGS) -c ta_test.cpp
diamond2.o: diamond2.cpp *.h
	$(CXX) $(CXXFLAGS) -c diamond2.cpp
diamond_ambiguous.o: diamond_ambiguous.cpp *.h
	$(CXX) $(CXXFLAGS) -c diamond_ambiguous.cpp
diamond_explicit.o: diamond_explicit.cpp *.h
	$(CXX) $(CXXFLAGS) -c diamond_explicit.cpp
diamond2_explicit.o: diamond2_explicit.cpp *.h
	$(CXX) $(CXXFLAGS) -c diamond2_explicit.cpp
pure_virtual_bad.o: pure_virtual_bad.cpp *.h
	$(CXX) $(CXXFLAGS) -c pure_virtual_bad.cpp
pure_virtual_fixed.o: pure_virtual_fixed.cpp *.h
	$(CXX) $(CXXFLAGS) -c pure_virtual_fixed.cpp

clean:
	-rm -f *.o *.gch *~ a.out barnyard_simple barnyard_animals barnyard_animals_2 barnyard_animals_poly barnyard_animals_op_overload_fixed barnyard_animals_pure_virtual pure_virtual_bad pure_virtual_fixed
