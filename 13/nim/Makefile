CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: mainwin

debug: CXXFLAGS += -g
debug: mainwin

mainwin: main.o mainwin.o nim.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o nim.o $(GTKFLAGS) -o nim

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

nim.o: nim.cpp *.h
	$(CXX) $(CXXFLAGS) -c nim.cpp -o nim.o

clean:
	rm -f *.o *.gch nim
