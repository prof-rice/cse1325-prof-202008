CXXFLAGS = --std=c++17

all: modulo modulo2

modulo: main.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main.o modulo.o -o modulo
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

modulo2: main2.o modulo.o *.h
	$(CXX) $(CXXFLAGS) main2.o modulo.o -o modulo2
main2.o: main2.cpp *.h
	$(CXX) $(CXXFLAGS) -c main2.cpp -o main2.o

modulo.o: modulo.cpp *.h
	$(CXX) $(CXXFLAGS) -c modulo.cpp -o modulo.o
clean:
	rm -f *.o *.gch ~* a.out modulo modulo2

