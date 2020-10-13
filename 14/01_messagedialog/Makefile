CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: hello 

hello: main.o mainwin.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o $(GTKFLAGS) -o hello
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c $(GTKFLAGS)
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) mainwin.cpp -c $(GTKFLAGS)

clean:
	rm -f *.o *.gch hello

