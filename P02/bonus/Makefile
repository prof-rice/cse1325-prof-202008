CXXFLAGS = --std=c++17

all: test dice

dice: main.o die.o *.h
	$(CXX) $(CXXFLAGS) main.o die.o -o dice
test: test.o die.o *.h
	$(CXX) $(CXXFLAGS) test.o die.o -o test

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
test.o: test.cpp *.h
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o
die.o: die.cpp *.h
	$(CXX) $(CXXFLAGS) -c die.cpp -o die.o

die.gch: die.h
	$(CXX) $(CXXFLAGS) -c die.h -o die.gch

clean:
	rm -f *.o *.gch ~* a.out test dice 
