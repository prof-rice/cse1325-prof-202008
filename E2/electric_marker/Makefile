CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: fr1

debug: CXXFLAGS += -g
debug: mainwin

fr1: main.o mainwin.o canvas.o 
	$(CXX) $(CXXFLAGS) main.o mainwin.o canvas.o $(GTKFLAGS) -o fr1

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

canvas.o: canvas.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas.cpp $(GTKFLAGS) -o canvas.o

clean:
	rm -f *.o *.gch fr1
