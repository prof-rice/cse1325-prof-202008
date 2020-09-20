CXXFLAGS = --std=c++17

all: riddle

riddle: main.o riddle.o *.h
	$(CXX) $(CXXFLAGS) main.o riddle.o -o riddle
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
riddle.o: riddle.cpp *.h
	$(CXX) $(CXXFLAGS) -c riddle.cpp -o riddle.o

clean:
	rm -f *.o *.gch ~* a.out riddle

