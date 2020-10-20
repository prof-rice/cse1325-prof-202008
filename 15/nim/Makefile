CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: nim

original: CXXFLAGS += -D__ORIGINAL
original: nim

debug: CXXFLAGS += -g
debug: nim

nim: main.o mainwin.o nim.o
	$(CXX) $(CXXFLAGS) main.o mainwin.o nim.o $(GTKFLAGS) -o nim

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

nim.o: nim.cpp *.h
	$(CXX) $(CXXFLAGS) -c nim.cpp -o nim.o

clean:
	rm -f *.o *.gch nim
