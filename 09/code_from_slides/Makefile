CXXFLAGS += --std=c++17

# This is a menu unique to this particular Makefile
main:
	@echo "  'make all' builds all demos below (except pure_virtual_bad)"
	@echo "  'make debug' builds all demos below for the debugger"
	@echo "  'make clean' deletes all .o, .gch, and executable files"
	@echo " "
	@echo "  'make mi' for simple multiple inheritance example"
	@echo "  'make ta' for multiple inheritance with constructors example"
	@echo "  'make ta_test' for ta with modified delegated constructor parameters"
	@echo "  'make diamond_ambiguous' for the diamond problem"
	@echo "  'make diamond_explicit' for a partial solution to the diamond problem"
	@echo "  'make diamond2_explicit' for the rest of the diamond problem"
	@echo "  'make diamond2_unfixed' for a clever but non-solution to the diamond problem"
	@echo "  'make diamond2' for the full solution to the diamond problem"
	@echo " "
	@echo " "
	@echo "Remember the TAB key!  'make di[TAB]' is quick and easy!"
	@echo " "

all: mi diamond_explicit diamond2 ta ta_test
	@printf "\ndiamond_ambiguous.cpp includes an intentional error.\nType 'make diamond_ambiguous' to see the error\n\n"
	@printf "\ndiamond2_explicit.cpp includes an intentional error.\nType 'make diamond2_explicit' to see the error\n\n"
	@printf "\ndiamond2_unfixed.cpp includes an intentional error.\nType 'make diamond2_unfixed' to see the error\n\n"

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
	-rm -f *.o *.gch *~ a.out mi diamond_explicit diamond2_explicit diamond2_unfixed diamond2 ta ta_test
