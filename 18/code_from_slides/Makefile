CXXFLAGS += -std=c++17

all: box_nonpoly box_override box_poly casting2 dynamic_cast dynamic_cast_verbose mem_layout void_star

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

box_nonpoly: box_nonpoly.cpp
	$(CXX) $(CXXFLAGS) -o box_nonpoly box_nonpoly.cpp
box_override: box_override.cpp
	$(CXX) $(CXXFLAGS)  -o box_override box_override.cpp
box_poly: box_poly.cpp
	$(CXX) $(CXXFLAGS)  -o box_poly box_poly.cpp
casting: casting.cpp
	$(CXX) $(CXXFLAGS)  -o casting casting.cpp
casting2: casting2.cpp
	$(CXX) $(CXXFLAGS)  -o casting2 casting2.cpp
dynamic_cast: dynamic_cast.cpp 
	$(CXX) $(CXXFLAGS)  -o dynamic_cast dynamic_cast.cpp
dynamic_cast_verbose: dynamic_cast_verbose.cpp 
	$(CXX) $(CXXFLAGS)  -o dynamic_cast_verbose dynamic_cast_verbose.cpp
void_star: void_star.cpp
	$(CXX) $(CXXFLAGS)  -o void_star void_star.cpp
mem_layout: mem_layout.cpp
	$(CXX) $(CXXFLAGS)  -o mem_layout mem_layout.cpp
clean:
	-rm -f *.o *.gch *~ a.out box_nonpoly box_override box_poly casting casting2 dynamic_cast dynamic_cast_verbose void_star mem_layout

