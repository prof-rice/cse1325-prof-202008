CXXFLAGS = --std=c++17

all: gate

gate: main.o gate.o and.o or.o *.h
	$(CXX) $(CXXFLAGS) main.o gate.o and.o or.o -o gate

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
gate.o: gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o
and.o: and.cpp *.h
	$(CXX) $(CXXFLAGS) -c and.cpp -o and.o
or.o: or.cpp *.h
	$(CXX) $(CXXFLAGS) -c or.cpp -o or.o

clean:
	rm -f *.o *.gch ~* a.out gate

