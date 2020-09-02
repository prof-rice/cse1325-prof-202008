CXXFLAGS = --std=c++17

info:
	@echo
	@printf 'Type e.g., "make 17_main"  to create program "17_main"\n'
	@printf 'Type       "make all"   to create every program\n'
	@printf 'Type       "make clean" to delete every program\n\n'

01_enum: 01_enum.cpp
	-$(CXX) $(CXXFLAGS) -o 01_enum 01_enum.cpp
	@printf "Now type ./01_enum to execute the result\n\n"

02_named_enum: 02_named_enum.cpp
	-$(CXX) $(CXXFLAGS) -o 02_named_enum 02_named_enum.cpp
	@printf "Now type ./02_named_enum to execute the result\n\n"

03_enum_variables: 03_enum_variables.cpp
	-$(CXX) $(CXXFLAGS) -o 03_enum_variables 03_enum_variables.cpp
	@printf "Now type ./03_enum_variables to execute the result\n\n"

04_enum_to_string: 04_enum_to_string.cpp
	-$(CXX) $(CXXFLAGS) -o 04_enum_to_string 04_enum_to_string.cpp
	@printf "Now type ./04_enum_to_string to execute the result\n\n"

05_enum_to_string_vector: 05_enum_to_string_vector.cpp
	-$(CXX) $(CXXFLAGS) -o 05_enum_to_string_vector 05_enum_to_string_vector.cpp
	@printf "Now type ./05_enum_to_string_vector to execute the result\n\n"

06_enum_to_string_function: 06_enum_to_string_function.cpp
	-$(CXX) $(CXXFLAGS) -o 06_enum_to_string_function 06_enum_to_string_function.cpp
	@printf "Now type ./06_enum_to_string_function to execute the result\n\n"

07_enum_to_string_switch: 07_enum_to_string_switch.cpp
	-$(CXX) $(CXXFLAGS) -o 07_enum_to_string_switch 07_enum_to_string_switch.cpp
	@printf "Now type ./07_enum_to_string_switch to execute the result\n\n"

08_enum_iteration: 08_enum_iteration.cpp
	-$(CXX) $(CXXFLAGS) -o 08_enum_iteration 08_enum_iteration.cpp
	@printf "Now type ./08_enum_iteration to execute the result\n\n"

10_enum_class: 10_enum_class.cpp
	-$(CXX) $(CXXFLAGS) -o 10_enum_class 10_enum_class.cpp
	@printf "Now type ./10_enum_class to execute the result\n\n"

11_enum_class_map: 11_enum_class_map.cpp
	-$(CXX) $(CXXFLAGS) -o 11_enum_class_map 11_enum_class_map.cpp
	@printf "Now type ./11_enum_class_map to execute the result\n\n"

12_struct: 12_struct.cpp
	-$(CXX) $(CXXFLAGS) -o 12_struct 12_struct.cpp
	@printf "Now type ./12_struct to execute the result\n\n"

13_struct_switch: 13_struct_switch.cpp
	-$(CXX) $(CXXFLAGS) -o 13_struct_switch 13_struct_switch.cpp
	@printf "Now type ./13_struct_switch to execute the result\n\n"

14_class: 14_class.cpp
	-$(CXX) $(CXXFLAGS) -o 14_class 14_class.cpp
	@printf "Now type ./14_class to execute the result\n\n"

15_init_list: 15_init_list.cpp
	-$(CXX) $(CXXFLAGS) -o 15_init_list 15_init_list.cpp
	@printf "Now type ./15_init_list to execute the result\n\n"

16_decl_def: 16_decl_def.cpp
	-$(CXX) $(CXXFLAGS) -o 16_decl_def 16_decl_def.cpp
	@printf "Now type ./16_decl_def to execute the result\n\n"

17_date.o: 17_date.cpp
	-$(CXX) $(CXXFLAGS) -c -o 17_date.o 17_date.cpp

17_main.o: 17_main.cpp
	-$(CXX) $(CXXFLAGS) -c -o 17_main.o 17_main.cpp

17_main: 17_main.o 17_date.o
	-$(CXX) $(CXXFLAGS) -o 17_main 17_main.o 17_date.o
	@printf "Now type ./17_main to execute the result\n\n"

20_test_shadow: 20_test_shadow.o 
	-$(CXX) $(CXXFLAGS) -o 20_test_shadow 20_test_shadow.o 
	@printf "Now type ./20_test_shadow to execute the result\n\n"

21_test_shadow: 21_test_shadow.o 
	-$(CXX) $(CXXFLAGS) -o 21_test_shadow 21_test_shadow.o 
	@printf "Now type ./21_test_shadow to execute the result\n\n"

22_test_shadow: 22_test_shadow.o 
	-$(CXX) $(CXXFLAGS) -o 22_test_shadow 22_test_shadow.o 
	@printf "Now type ./22_test_shadow to execute the result\n\n"

23_test_shadow: 23_test_shadow.o 
	-$(CXX) $(CXXFLAGS) -o 23_test_shadow 23_test_shadow.o 
	@printf "Now type ./23_test_shadow to execute the result\n\n"

24_test_shadow: 24_test_shadow.o 
	-$(CXX) $(CXXFLAGS) -o 24_test_shadow 24_test_shadow.o 
	@printf "Now type ./24_test_shadow to execute the result\n\n"

# NOTE: 23_test_shadow intentionally fails to compile to demonstrate a naming conflict
all:  01_enum 02_named_enum 03_enum_variables 04_enum_to_string 05_enum_to_string_vector 06_enum_to_string_function 07_enum_to_string_switch 08_enum_iteration 10_enum_class 11_enum_class_map 12_struct 13_struct_switch 14_class 15_init_list 16_decl_def 17_main 20_test_shadow 21_test_shadow 22_test_shadow 24_test_shadow

clean:
	rm -f *.o *.gch a.out  01_enum 02_named_enum 03_enum_variables 04_enum_to_string 05_enum_to_string_vector 06_enum_to_string_function 07_enum_to_string_switch 08_enum_iteration 10_enum_class 11_enum_class_map 12_struct 13_struct_switch 14_class 15_init_list 16_decl_def 17_main 20_test_shadow 21_test_shadow 22_test_shadow 24_test_shadow

