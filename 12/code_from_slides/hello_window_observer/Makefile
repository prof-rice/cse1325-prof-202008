CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: hello virtual1 virtual2 

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

hello: main.o hello.o *.h
	$(CXX) $(CXXFLAGS) main.o hello.o  $(GTKFLAGS) -o hello

hello_classic: main.o hello_classic.o *.h
	$(CXX) $(CXXFLAGS) main.o hello_classic.o  $(GTKFLAGS) -o hello_classic

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

hello.o: hello.cpp *.h
	$(CXX) $(CXXFLAGS) -c hello.cpp $(GTKFLAGS) -o hello.o

hello_classic.o: hello_classic.cpp *.h
	$(CXX) $(CXXFLAGS) -c hello_classic.cpp $(GTKFLAGS) -o hello_classic.o

virtual1: virtual1.cpp *.h
	$(CXX) $(CXXFLAGS) -o virtual1 virtual1.cpp

virtual2: virtual2.cpp *.h
	$(CXX) $(CXXFLAGS) -o virtual2 virtual2.cpp 

clean:
	rm -f *.o *.gch *~ hello hello_classic virtual1 virtual2
