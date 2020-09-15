 #include <iostream>
 #include <vector>

 int main() {
   std::vector<int> v(10);   // a vector of 10 ints,
                        // each initialized to the default value, 0,
                        // referred to as v[0] .. v[9]
   for (int i = 0; i<v.size(); ++i) v[i] = i; 	// set values
   for (int i = 0; i<=10; ++i)		// print 10 values (???)
	std::cout << "v[" << i << "] == " << v[i] << std::endl;
 }

