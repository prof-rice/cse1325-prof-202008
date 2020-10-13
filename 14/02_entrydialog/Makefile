CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

main: main.o mainwin.o entrydialog.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o $(GTKFLAGS) -o main

main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o

mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o

entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

# Test entrydialog

test: test_entrydialog.o entrydialog.o
	$(CXX) $(CXXFLAGS) test_entrydialog.o entrydialog.o $(GTKFLAGS) -o test


test_entrydialog.o: test_entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_entrydialog.cpp $(GTKFLAGS) -o test_entrydialog.o

clean:
	rm -f *.o *.gch main test
