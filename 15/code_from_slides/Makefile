CXXFLAGS += --std=c++17

all: read reading write manipulators binary_buffers binary_bytes stringstreams chars

# Build with the debug option
debug: CXXFLAGS += -g
debug: all

read: read.o 
	$(CXX) $(CXXFLAGS) -o read read.o
reading: reading.o 
	$(CXX) $(CXXFLAGS) -o reading reading.o
write: write.o 
	$(CXX) $(CXXFLAGS) -o write write.o
manipulators: manipulators.o 
	$(CXX) $(CXXFLAGS) -o manipulators manipulators.o
binary_buffers: binary_buffers.o 
	$(CXX) $(CXXFLAGS) -o binary_buffers binary_buffers.o
binary_bytes: binary_bytes.o 
	$(CXX) $(CXXFLAGS) -o binary_bytes binary_bytes.o
stringstreams: stringstreams.o 
	$(CXX) $(CXXFLAGS) -o stringstreams stringstreams.o
chars: chars.o 
	$(CXX) $(CXXFLAGS) -o chars chars.o

read.o: read.cpp 
	$(CXX) $(CXXFLAGS) -c read.cpp
reading.o: reading.cpp 
	$(CXX) $(CXXFLAGS) -c reading.cpp
write.o: write.cpp 
	$(CXX) $(CXXFLAGS) -c write.cpp
manipulators.o: manipulators.cpp 
	$(CXX) $(CXXFLAGS) -c manipulators.cpp
binary_buffers.o: binary_buffers.cpp 
	$(CXX) $(CXXFLAGS) -c binary_buffers.cpp
binary_bytes.o: binary_bytes.cpp 
	$(CXX) $(CXXFLAGS) -c binary_bytes.cpp
stringstreams.o: stringstreams.cpp 
	$(CXX) $(CXXFLAGS) -c stringstreams.cpp
chars.o: chars.cpp 
	$(CXX) $(CXXFLAGS) -c chars.cpp

clean:
	-rm -f *.o *.gch *~ a.out read reading write manipulators binary_buffers binary_bytes stringstreams chars

