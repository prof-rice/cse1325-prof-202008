CXXFLAGS = --std=c++17

all: gate test

gate: main.o gate.o and.o or.o xor.o *.h
	$(CXX) $(CXXFLAGS) main.o gate.o and.o or.o xor.o -o gate

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
gate.o: gate.cpp *.h
	$(CXX) $(CXXFLAGS) -c gate.cpp -o gate.o
and.o: and.cpp *.h
	$(CXX) $(CXXFLAGS) -c and.cpp -o and.o
or.o: or.cpp *.h
	$(CXX) $(CXXFLAGS) -c or.cpp -o or.o
xor.o: xor.cpp *.h
	$(CXX) $(CXXFLAGS) -c xor.cpp -o xor.o

test: test.o gate.o and.o or.o xor.o *.h
	$(CXX) $(CXXFLAGS) test.o gate.o and.o or.o xor.o -o test
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

clean:
	rm -f *.o *.gch ~* a.out gate test

