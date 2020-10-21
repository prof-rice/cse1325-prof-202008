CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: painting0 painting1 painting2

painting0: main.o mainwin.o canvas_00.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o canvas_00.o $(GTKFLAGS) -o painting0
painting1: main.o mainwin.o canvas_01.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o canvas_01.o $(GTKFLAGS) -o painting1
painting2: main.o mainwin.o canvas_02.o turtle.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o canvas_02.o turtle.o $(GTKFLAGS) -o painting2
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
canvas_00.o: canvas_00.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas_00.cpp $(GTKFLAGS) -o canvas_00.o
canvas_01.o: canvas_01.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas_01.cpp $(GTKFLAGS) -o canvas_01.o
canvas_02.o: canvas_02.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas_02.cpp $(GTKFLAGS) -o canvas_02.o
turtle.o: turtle.cpp *.h
	$(CXX) $(CXXFLAGS) -c turtle.cpp $(GTKFLAGS) -o turtle.o

clean:
	rm -f *.o *.gch painting0 painting1 painting2

