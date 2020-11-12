#include <iostream>

int main() {
    while(std::cin) {

        // Creating a string of repeating characters
        std::string s(40, '='); 
        std::cout << s << "\nEnter any string (Ctrl-d to exit): ";
        std::getline(std::cin, s);
        if(!std::cin) break;

        // Calculating the string size (also called length)
        std::cout << "\nLength: " << s.size()
                  << " of "     << s.max_size() << "\n\n"; // or s.length()

        // Iterating over each char in the string
        std::cout << "Iteration:\n";
        for(char c : s) std::cout << c << ' ';
        std::cout << "\n\n";

        // Extracting substrings using the string constructor
        std::cout << "Substrings:\n\n";
        if (s.size() > 3) {
            std::string sl{s, 0, s.size()/2}; // left side of the string
            std::string sr{s, s.size()/2}; // right side of the string
            std::cout << sl << ".." << sr << '\n';
            for(int i=0, l=s.size() ; i<=s.size()/2; ++i, l -= 2)
                std::cout << std::string(i+1, ' ')
                          << std::string(s, i, l) << '\n';
        }
        std::cout << '\n';

        // Converting to and from C-style strings
        std::cout << "As a C-style string: " << s.c_str() << '\n';
        const char* cp = "I'm a C-style string!";  // the const is required
        std::string sc{cp};
        std::cout << "Converted from a C-style string: " << sc << "\n\n";

        // Appending a string and a repeated char
        s.append(" - so there");
        s.append(20, '!');
        std::cout << "Appending: " << s << "\n\n";

        // Inserting strings or chars inside a string
        s.insert(0, 5, '>');
        for(int i=(s.length()/10)*10; i>0; i-=10) {
            std::string marker = '[' + std::to_string(i) + ']';
            s.insert(i, marker);
        }
        std::cout << "Inserting: " << s << "\n\n";

        // Flush the STDOUT buffer before asking for another string
        std::cout.flush();
    }
    std::cout << std::endl;
}
