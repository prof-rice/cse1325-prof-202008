CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: paint 

log: CXXFLAGS += -DLOGGER
log: paint

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

paint: main.o mainwin.o canvas.o shape.o line.o point.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o canvas.o shape.o line.o point.o  $(GTKFLAGS) -o paint
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp  $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp  $(GTKFLAGS) -o mainwin.o
canvas.o: canvas.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas.cpp  $(GTKFLAGS) -o canvas.o
point.o: point.cpp *.h
	$(CXX) $(CXXFLAGS) -c point.cpp -o point.o
shape.o: shape.cpp *.h
	$(CXX) $(CXXFLAGS) -c shape.cpp  $(GTKFLAGS) -o shape.o
line.o: line.cpp *.h
	$(CXX) $(CXXFLAGS) -c line.cpp  $(GTKFLAGS) -o line.o
polyline.o: polyline.cpp *.h
	$(CXX) $(CXXFLAGS) -c polyline.cpp  $(GTKFLAGS) -o polyline.o
polygon.o: polygon.cpp *.h
	$(CXX) $(CXXFLAGS) -c polygon.cpp  $(GTKFLAGS) -o polygon.o
rectangle.o: rectangle.cpp *.h
	$(CXX) $(CXXFLAGS) -c rectangle.cpp  $(GTKFLAGS) -o rectangle.o
function.o: function.cpp *.h
	$(CXX) $(CXXFLAGS) -c function.cpp  $(GTKFLAGS) -o function.o
dfunction.o: dfunction.cpp *.h
	$(CXX) $(CXXFLAGS) -c dfunction.cpp  $(GTKFLAGS) -o dfunction.o
turtle.o: turtle.cpp *.h
	$(CXX) $(CXXFLAGS) -c turtle.cpp  $(GTKFLAGS) -o turtle.o
clean:
	rm -f *.o *.gch paint 
