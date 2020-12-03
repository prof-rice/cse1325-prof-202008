# Free Response 1e Suggested Solution

CXXFLAGS += --std=c++17

poly: main.o polynomial.o linear.o quadratic.o *.h
	$(CXX) $(CXXFLAGS) main.o polynomial.o linear.o quadratic.o -o poly
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
polynomial.o: polynomial.cpp *.h
	$(CXX) $(CXXFLAGS) -c polynomial.cpp -o polynomial.o
linear.o: linear.cpp *.h
	$(CXX) $(CXXFLAGS) -c linear.cpp -o linear.o
quadratic.o: quadratic.cpp *.h
	$(CXX) $(CXXFLAGS) -c quadratic.cpp -o quadratic.o

DEBUG: CXXFLAGS += g
DEBUG: poly

clean:
	rm -f *.o *.gch poly

