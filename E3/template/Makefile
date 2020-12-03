CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: exam soln

exam: exam.cpp *.h
	$(CXX) $(CXXFLAGS) exam.cpp  $(GTKFLAGS) -o exam

soln: soln.cpp *.h
	$(CXX) $(CXXFLAGS) soln.cpp  $(GTKFLAGS) -o soln

clean:
	rm -f *.o *.gch soln exam
