CXXFLAGS += -std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

all: hello_dialog hello_pointer hello_window_label hello_window_button hello_window_callback hello_window_lambda virtual virtual_not

hello_dialog: hello_dialog.cpp 
	$(CXX) $(CXXFLAGS) hello_dialog.cpp  $(GTKFLAGS) -o hello_dialog
hello_pointer: hello_pointer.cpp
	$(CXX) $(CXXFLAGS) hello_pointer.cpp $(GTKFLAGS) -o hello_pointer
hello_window_label: hello_window_label.cpp
	$(CXX) $(CXXFLAGS) hello_window_label.cpp  $(GTKFLAGS) -o hello_window_label
hello_window_button: hello_window_button.cpp
	$(CXX) $(CXXFLAGS) hello_window_button.cpp  $(GTKFLAGS) -o hello_window_button
hello_window_callback: hello_window_callback.cpp
	$(CXX) $(CXXFLAGS) hello_window_callback.cpp  $(GTKFLAGS) -o hello_window_callback
hello_window_lambda: hello_window_lambda.cpp
	$(CXX) $(CXXFLAGS) hello_window_lambda.cpp  $(GTKFLAGS) -o hello_window_lambda
virtual: virtual.cpp
	$(CXX) $(CXXFLAGS) virtual.cpp  $(GTKFLAGS) -o virtual
virtual_not: virtual_not.cpp
	$(CXX) $(CXXFLAGS) virtual_not.cpp  $(GTKFLAGS) -o virtual_not
clean:
	rm -f *.o *.gch a.out hello_dialog hello_pointer hello_window_label hello_window_button hello_window_callback hello_window_lambda virtual virtual_not

