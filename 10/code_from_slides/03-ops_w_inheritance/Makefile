# Makefile for Roving Robots
CXXFLAGS = -std=c++17

test: test_coordinate

debug: CXXFLAGS += -g
debug: test_coordinate

# Main classes
coordinate.o: coordinate.cpp *.h 
	$(CXX) $(CXXFLAGS) -c coordinate.cpp

direction.o: direction.cpp *.h 
	$(CXX) $(CXXFLAGS) -c direction.cpp

# Test vectors
test_coordinate: test_coordinate.o coordinate.o direction.o
	$(CXX) $(CXXFLAGS) test_coordinate.o coordinate.o direction.o -o test_coordinate
	./test_coordinate
test_coordinate.o: test_coordinate.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_coordinate.cpp

clean:
	-rm -f *.o *.gch *~ test_coordinate
