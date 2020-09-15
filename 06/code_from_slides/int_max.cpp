 #include <iostream>
 #include <climits>
 
 int area(int length, int width) {  // calculate area of a rectangle
	// length and width must be positive
    if (length<=0 || width <=0) throw std::runtime_error{"Bad area"};
    return length*width;
 }

 int main() {
    int length1 = 14;
    int width1 = 10;

    std::cout << "Area of " << length1 << " x " << width1 << " is " << area(length1, width1) << std::endl;

    int length2 = INT_MAX;
    int width2 = 2;

    std::cout << "Area of " << length2 << " x " << width2 << " is " << area(length2, width2) << std::endl;
 }

