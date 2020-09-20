CXXFLAGS = --std=c++17

info:
	@echo
	@printf 'Type       "make all"       to compile every class\n'
	@printf 'Type e.g., "make book.o"    to compile book.cpp\n'
	@printf '    Note: No main function is provided this week\n\n'
	@printf 'Type       "make uml"       to compile every UML diagram*\n'
	@printf 'Type e.g., "make class.png" to compile class.uml*\n\n'
	@printf 'Type       "make clean"     to delete every .o file\n\n'
	@printf '    * Requires Plant UML, installed by default in the VM\n'
	@printf '      Or paste the code at http://plantuml.com/plantuml/png\n\n'


patron.o: patron.cpp *.h
	-$(CXX) $(CXXFLAGS) -c patron.cpp -o patron.o

library.o: library.cpp *.h
	-$(CXX) $(CXXFLAGS) -c library.cpp -o library.o

book.o: book.cpp *.h
	-$(CXX) $(CXXFLAGS) -c book.cpp -o book.o

paper.o: paper.cpp *.h
	-$(CXX) $(CXXFLAGS) -c paper.cpp -o paper.o

person.o: person.cpp *.h
	-$(CXX) $(CXXFLAGS) -c person.cpp -o person.o

checkout.o: checkout.cpp *.h
	-$(CXX) $(CXXFLAGS) -c checkout.cpp -o checkout.o

class.png: class.uml
	@type plantuml >/dev/null 2>&1 || { echo >&2 "plantuml not installed"; exit 1; }
	plantuml class.uml

assoc.png: assoc.uml
	@type plantuml >/dev/null 2>&1 || { echo >&2 "plantuml not installed"; exit 1; }
	plantuml assoc.uml

assoc_class.png: assoc_class.uml
	@type plantuml >/dev/null 2>&1 || { echo >&2 "plantuml not installed"; exit 1; }
	plantuml assoc_class.uml

extend.png: extend.uml
	@type plantuml >/dev/null 2>&1 || { echo >&2 "plantuml not installed"; exit 1; }
	plantuml extend.uml

all:  patron.o library.o book.o paper.o checkout.o

uml:  class.png assoc.png assoc_class.png extend.png

clean:
	rm -f *.o *.gch a.out

