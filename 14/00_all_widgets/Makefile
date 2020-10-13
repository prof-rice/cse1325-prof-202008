CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o mainwin.o mainwin-dialog.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o mainwin-dialog.o $(GTKFLAGS) -o main
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
mainwin-dialog.o: mainwin-dialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin-dialog.cpp $(GTKFLAGS) -o mainwin-dialog.o
clean:
	rm -f *.o *.gch main

