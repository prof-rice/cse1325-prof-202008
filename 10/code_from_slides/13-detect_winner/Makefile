# Makefile for Roving Robots
CXXFLAGS += -std=c++17

all: robots
test: test_vectors test_controller test_coordinate test_robot test_grid

debug: CXXFLAGS += -g
debug: robots show_grid test

# Roving Robots
robots: main.o controller.o view.o grid.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o robots main.o controller.o view.o grid.o robot.o coordinate.o

# Classes (and main)
main.o: main.cpp *.h 
	$(CXX) $(CXXFLAGS) -c main.cpp
controller.o: controller.cpp *.h 
	$(CXX) $(CXXFLAGS) -c controller.cpp
view.o: view.cpp *.h 
	$(CXX) $(CXXFLAGS) -c view.cpp
grid.o: grid.cpp *.h 
	$(CXX) $(CXXFLAGS) -c grid.cpp
robot.o: robot.cpp *.h 
	$(CXX) $(CXXFLAGS) -c robot.cpp
coordinate.o: coordinate.cpp *.h 
	$(CXX) $(CXXFLAGS) -c coordinate.cpp

# Test vectors
test_vectors: robots
	@./robots < test_vectors.txt > test_vectors.out
	@-diff test_vectors.good test_vectors.out
test_controller: CXXFLAGS += -fno-access-control
test_controller: test_controller.o controller.o view.o grid.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_controller test_controller.o controller.o view.o grid.o robot.o coordinate.o
	./test_controller
test_grid: test_grid.o grid.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_grid test_grid.o grid.o robot.o coordinate.o
	./test_grid
test_grid.o: test_grid.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_grid.cpp

show_grid: show_grid.o grid.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o show_grid show_grid.o grid.o robot.o coordinate.o
	./show_grid
show_grid.o: show_grid.cpp *.h
	$(CXX) $(CXXFLAGS) -c show_grid.cpp

test_robot: test_robot.o robot.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_robot test_robot.o robot.o coordinate.o
	./test_robot
test_robot.o: test_robot.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_robot.cpp

test_coordinate: test_coordinate.o coordinate.o *.h
	$(CXX) $(CXXFLAGS) -o test_coordinate test_coordinate.o coordinate.o
	./test_coordinate
test_coordinate.o: test_coordinate.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_coordinate.cpp

clean:
	-rm -f *.o *.gch *~ robots test_controller test_coordinate test_robot test_grid show_grid
