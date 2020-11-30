CXXFLAGS = --std=c++17 -pthread

info:
	@echo
	@printf 'Type e.g., "make auto"  to create program "auto"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

3thread: 3thread.cpp
	-$(CXX) $(CXXFLAGS) -o 3thread 3thread.cpp
	@printf "Now type ./3thread to execute the result\n\n"

hw_concur: hw_concur.cpp
	-$(CXX) $(CXXFLAGS) -o hw_concur hw_concur.cpp
	@printf "Now type ./hw_concur to execute the result\n\n"

mixed_thread: mixed_thread.cpp
	-$(CXX) $(CXXFLAGS) -o mixed_thread mixed_thread.cpp
	@printf "Now type ./mixed_thread to execute the result\n\n"

mutex: mutex.cpp
	-$(CXX) $(CXXFLAGS) -o mutex mutex.cpp
	@printf "Now type ./mutex to execute the result\n\n"

no_mutex: no_mutex.cpp
	-$(CXX) $(CXXFLAGS) -o no_mutex no_mutex.cpp
	@printf "Now type ./no_mutex to execute the result\n\n"

phone: phone.cpp
	-$(CXX) $(CXXFLAGS) -o phone phone.cpp
	@printf "Now type ./phone to execute the result\n\n"

test: test.cpp
	-$(CXX) $(CXXFLAGS) -o test test.cpp
	@printf "Now type ./test to execute the result\n\n"

threadid3: threadid3.cpp
	-$(CXX) $(CXXFLAGS) -o threadid3 threadid3.cpp
	@printf "Now type ./threadid3 to execute the result\n\n"

threadid: threadid.cpp
	-$(CXX) $(CXXFLAGS) -o threadid threadid.cpp
	@printf "Now type ./threadid to execute the result\n\n"

threadid_method: threadid_method.cpp
	-$(CXX) $(CXXFLAGS) -o threadid_method threadid_method.cpp
	@printf "Now type ./threadid_method to execute the result\n\n"

threadid_method_lambda: threadid_method_lambda.cpp
	-$(CXX) $(CXXFLAGS) -o threadid_method_lambda threadid_method_lambda.cpp
	@printf "Now type ./threadid_method_lambda to execute the result\n\n"

threadid_new: threadid_new.cpp
	-$(CXX) $(CXXFLAGS) -o threadid_new threadid_new.cpp
	@printf "Now type ./threadid_new to execute the result\n\n"

all:  3thread hw_concur mixed_thread mutex no_mutex phone test threadid3 threadid threadid_method threadid_method_lambda threadid_new

clean:
	rm -f *.o *.gch a.out  3thread hw_concur mixed_thread mutex no_mutex phone test threadid3 threadid threadid_method threadid_method_lambda threadid_new

