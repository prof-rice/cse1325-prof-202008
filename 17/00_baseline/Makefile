CXXFLAGS = -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: main 

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

main: main.o canvas.o point.o shape.o line.o polyline.o polygon.o rectangle.o function.o dfunction.o turtle.o *.h
	$(CXX) $(CXXFLAGS) -o main main.o canvas.o point.o shape.o line.o polyline.o polygon.o rectangle.o function.o dfunction.o turtle.o $(GTKFLAGS)
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp  $(GTKFLAGS)
canvas.o: canvas.cpp *.h
	$(CXX) $(CXXFLAGS) -c canvas.cpp  $(GTKFLAGS)
point.o: point.cpp *.h
	$(CXX) $(CXXFLAGS) -c point.cpp
shape.o: shape.cpp *.h
	$(CXX) $(CXXFLAGS) -c shape.cpp  $(GTKFLAGS)
line.o: line.cpp *.h
	$(CXX) $(CXXFLAGS) -c line.cpp  $(GTKFLAGS)
polyline.o: polyline.cpp *.h
	$(CXX) $(CXXFLAGS) -c polyline.cpp  $(GTKFLAGS)
polygon.o: polygon.cpp *.h
	$(CXX) $(CXXFLAGS) -c polygon.cpp  $(GTKFLAGS)
rectangle.o: rectangle.cpp *.h
	$(CXX) $(CXXFLAGS) -c rectangle.cpp  $(GTKFLAGS)
function.o: function.cpp *.h
	$(CXX) $(CXXFLAGS) -c function.cpp  $(GTKFLAGS)
dfunction.o: dfunction.cpp *.h
	$(CXX) $(CXXFLAGS) -c dfunction.cpp  $(GTKFLAGS)
turtle.o: turtle.cpp *.h
	$(CXX) $(CXXFLAGS) -c turtle.cpp  $(GTKFLAGS)
clean:
	-rm -f *.o *.gch main a.out 
