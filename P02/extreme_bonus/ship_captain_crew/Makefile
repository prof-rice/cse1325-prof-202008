CXXFLAGS = --std=c++17

all: scc

scc: main.o die.o *.h
	$(CXX) $(CXXFLAGS) main.o die.o -o scc

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
die.o: die.cpp *.h
	$(CXX) $(CXXFLAGS) -c die.cpp -o die.o

die.gch: die.h
	$(CXX) $(CXXFLAGS) -c die.h -o die.gch

clean:
	rm -f *.o *.gch ~* a.out scc 
