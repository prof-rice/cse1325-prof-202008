# Makefile for Roving Robots
CXXFLAGS = --std=c++17

test: test_coordinate

debug: CXXFLAGS += -g
debug: test_coordinate

# Main classes
coordinate.o: coordinate.cpp *.h 
	$(CXX) $(CXXFLAGS) -c coordinate.cpp -o coordinate.o

# Test vectors
test_coordinate: test_coordinate.o coordinate.o
	$(CXX) $(CXXFLAGS) test_coordinate.o coordinate.o -o test_coordinate 
	./test_coordinate
test_coordinate.o: test_coordinate.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_coordinate.cpp -o test_coordinate.o

clean:
	-rm -f *.o *.gch *~ a.out test_coordinate
