CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: animals hbox

animals: main.o mainwin-grid.o
	$(CXX) $(CXXFLAGS) main.o mainwin-grid.o $(GTKFLAGS) -o animals
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) main.cpp -c $(GTKFLAGS)
mainwin-grid.o: mainwin-grid.cpp *.h
	$(CXX) $(CXXFLAGS) mainwin-grid.cpp -c $(GTKFLAGS)

hbox: main.o mainwin-hbox.o
	$(CXX) $(CXXFLAGS) main.o mainwin-hbox.o $(GTKFLAGS) -o hbox
mainwin-hbox.o: mainwin-hbox.cpp *.h
	$(CXX) $(CXXFLAGS) mainwin-hbox.cpp -c $(GTKFLAGS)

clean:
	rm -f *.o *.gch animals grid hbox

