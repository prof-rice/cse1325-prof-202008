CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o mainwin.o imagedialog.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o imagedialog.o $(GTKFLAGS) -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

imagedialog.o: imagedialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c imagedialog.cpp $(GTKFLAGS) -o imagedialog.o

# Test imagedialog

test: test_imagedialog.o imagedialog.o
	$(CXX) $(CXXFLAGS) test_imagedialog.o imagedialog.o $(GTKFLAGS) -o test


test_imagedialog.o: test_imagedialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_imagedialog.cpp $(GTKFLAGS) -o test_imagedialog.o

clean:
	rm -f *.o *.gch main test
