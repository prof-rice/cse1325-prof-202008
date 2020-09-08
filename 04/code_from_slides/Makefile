CXXFLAGS = --std=c++17

complex: main.o complex.o 
	$(CXX) $(CXXFLAGS) main.o complex.o -o complex

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

complex.o: complex.cpp
	$(CXX) $(CXXFLAGS) -c complex.cpp -o complex.o

clean:
	rm -f *.o *.gch a.out  complex

