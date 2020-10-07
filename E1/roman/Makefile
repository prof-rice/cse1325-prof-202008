# Free Response 1e Suggested Solution

CXXFLAGS += --std=c++17

roman: main.o roman.o *.h
	$(CXX) $(CXXFLAGS) main.o roman.o -o roman
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
roman.o: roman.cpp *.h
	$(CXX) $(CXXFLAGS) -c roman.cpp -o roman.o

DEBUG: CXXFLAGS += -g
DEBUG: roman

clean:
	rm -f *.o *.gch roman

