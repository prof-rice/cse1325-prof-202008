# Makefile for Roving Robots
CXXFLAGS = -std=c++17

test: test_coordinate test_robot

debug: CXXFLAGS += -g
debug: test

# Main classes
robot.o: robot.cpp *.h 
	$(CXX) $(CXXFLAGS) -c robot.cpp
coordinate.o: coordinate.cpp *.h 
	$(CXX) $(CXXFLAGS) -c coordinate.cpp

# Test vectors
test_robot: test_robot.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_robot test_robot.o robot.o coordinate.o
	@./test_robot
test_robot.o: test_robot.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_robot.cpp

test_coordinate: test_coordinate.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_coordinate test_coordinate.o coordinate.o
	@./test_coordinate
test_coordinate.o: test_coordinate.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_coordinate.cpp

clean:
	-rm -f *.o *.gch *~ test_coordinate test_robot
