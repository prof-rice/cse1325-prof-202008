 #include <iostream>
 #include <cassert>

 int area(int length, int width) {
   // if (length<=0 || width<=0) throw std::runtime_error{"Bad area"};  // The exception version
   assert (length>0 && width>0);
   int result = length*width;
   // if (result < 0) throw std::runtime_error{"Bad area"};;            // The exception version
   assert (result > 0);
   return result;
 }
 int main() {
   std::cout << area(3, 5) << std::endl;
   std::cout << area(8, 2) << std::endl;
   std::cout << area(3,-5) << std::endl;
   return 0; // success
 }

