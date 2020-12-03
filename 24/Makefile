CXXFLAGS += -std=c++14

all: bitset pool stack stoplight

debug: CXXFLAGS += -g
debug: rebuild

rebuild: clean all

clean:
	-rm -f *.o *.gch *~ a.out bitset pool stack stoplight

