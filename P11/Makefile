CXXFLAGS = --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: manga

debug: CXXFLAGS += -g
debug: manga

manga: main.o mainwin.o entrydialog.o store.o product.o plant.o tool.o mulch.o customer.o item.o order.o *.h
	$(CXX) $(CXXFLAGS) main.o mainwin.o entrydialog.o store.o product.o plant.o tool.o mulch.o customer.o item.o order.o $(GTKFLAGS) -o manga
main.o: main.cpp *.h
	$(CXX) $(CXXFLAGS) -c main.cpp $(GTKFLAGS) -o main.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o
store.o: store.cpp *.h
	$(CXX) $(CXXFLAGS) -c store.cpp -o store.o
product.o: product.cpp *.h
	$(CXX) $(CXXFLAGS) -c product.cpp -o product.o
plant.o: plant.cpp *.h
	$(CXX) $(CXXFLAGS) -c plant.cpp -o plant.o
tool.o: tool.cpp *.h
	$(CXX) $(CXXFLAGS) -c tool.cpp -o tool.o
mulch.o: mulch.cpp *.h
	$(CXX) $(CXXFLAGS) -c mulch.cpp -o mulch.o
customer.o: customer.cpp *.h
	$(CXX) $(CXXFLAGS) -c customer.cpp -o customer.o
item.o: item.cpp *.h
	$(CXX) $(CXXFLAGS) -c item.cpp -o item.o
order.o: order.cpp *.h
	$(CXX) $(CXXFLAGS) -c order.cpp -o order.o

cli: cli.o store.o product.o plant.o tool.o mulch.o *.h
	$(CXX) $(CXXFLAGS) cli.o store.o product.o plant.o tool.o mulch.o -o cli
cli.o: cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c cli.cpp -o cli.o

test_cli: test_cli.o store.o product.o plant.o tool.o mulch.o *.h
	$(CXX) $(CXXFLAGS) test_cli.o store.o product.o plant.o tool.o mulch.o -o test_cli
test_cli.o: test_cli.cpp *.h
	$(CXX) $(CXXFLAGS) -c test_cli.cpp -o test_cli.o

clean:
	rm -f *.o *.gch ~* a.out manga cli test_cli

