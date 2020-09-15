 #include <iostream>

 int area(int length, int width) {
   if (length<=0 || width<=0) throw std::runtime_error{"Bad area"};
   return length*width;
 }
 int main() {
   try {
     std::cout << area(3, 5) << std::endl;
     std::cout << area(8, 2) << std::endl;
     //std::cout << area(3,-5) << std::endl;
     return 0; // success
   } catch(std::runtime_error e) {
     std::cerr << e.what() << std::endl;
     return 1; // failure
   }
 }

