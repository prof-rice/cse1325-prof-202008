CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: button entry comboboxtext togglebutton checkbutton radiobutton spinbutton scale progressbar

main: main.o mainwin.o mainwin-dialog.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o mainwin-dialog.o $(GTKFLAGS) -o main
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
mainwin-dialog.o: mainwin-dialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin-dialog.cpp $(GTKFLAGS) -o mainwin-dialog.o

button: button.cpp
	$(CXX) $(CXXFLAGS) button.cpp $(GTKFLAGS) -o button
entry: entry.cpp
	$(CXX) $(CXXFLAGS) entry.cpp $(GTKFLAGS) -o entry
comboboxtext: comboboxtext.cpp
	$(CXX) $(CXXFLAGS) comboboxtext.cpp $(GTKFLAGS) -o comboboxtext
togglebutton: togglebutton.cpp
	$(CXX) $(CXXFLAGS) togglebutton.cpp $(GTKFLAGS) -o togglebutton
checkbutton: checkbutton.cpp
	$(CXX) $(CXXFLAGS) checkbutton.cpp $(GTKFLAGS) -o checkbutton
radiobutton: radiobutton.cpp
	$(CXX) $(CXXFLAGS) radiobutton.cpp $(GTKFLAGS) -o radiobutton
spinbutton: spinbutton.cpp
	$(CXX) $(CXXFLAGS) spinbutton.cpp $(GTKFLAGS) -o spinbutton
scale: scale.cpp
	$(CXX) $(CXXFLAGS) scale.cpp $(GTKFLAGS) -o scale
progressbar: progressbar.cpp
	$(CXX) $(CXXFLAGS) progressbar.cpp $(GTKFLAGS) -o progressbar
clean:
	rm -f *.o *.gch main button entry comboboxtext togglebutton checkbutton radiobutton spinbutton scale progressbar

