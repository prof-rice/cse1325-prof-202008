CXXFLAGS += --std=c++17

all: match

match: main.o board.o tile.o *.h
	$(CXX) $(CXXFLAGS) main.o board.o tile.o -o match
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
board.o: board.cpp *.h
	$(CXX) $(CXXFLAGS) -c board.cpp -o board.o
tile.o: tile.cpp *.h
	$(CXX) $(CXXFLAGS) -c tile.cpp -o tile.o
clean:
	rm -f *.o *.gch ~* a.out match

