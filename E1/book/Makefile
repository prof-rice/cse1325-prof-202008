CXXFLAGS += --std=c++17

book: main.o book.o mystery.o history.o textbook.o travel.o *.h
	$(CXX) $(CXXFLAGS) main.o book.o mystery.o history.o textbook.o travel.o -o book
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
book.o: book.cpp *.h
	$(CXX) $(CXXFLAGS) -c book.cpp -o book.o
mystery.o: mystery.cpp *.h
	$(CXX) $(CXXFLAGS) -c mystery.cpp -o mystery.o
history.o: history.cpp *.h
	$(CXX) $(CXXFLAGS) -c history.cpp -o history.o
textbook.o: textbook.cpp *.h
	$(CXX) $(CXXFLAGS) -c textbook.cpp -o textbook.o
travel.o: travel.cpp *.h
	$(CXX) $(CXXFLAGS) -c travel.cpp -o travel.o

debug: CXXFLAGS += -g
debug: book

clean:
	rm -f *.o *.gch book

