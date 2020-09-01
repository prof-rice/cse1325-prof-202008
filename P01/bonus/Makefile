CXXFLAGS = --std=c++17

all: hello hello_getline

hello: hello.cpp
	$(CXX) $(CXXFLAGS) hello.cpp -o hello

hello_getline: hello_getline.cpp
	$(CXX) $(CXXFLAGS) hello_getline.cpp -o hello_getline

clean:
	-rm -f *.o *~ a.out hello hello_getline
