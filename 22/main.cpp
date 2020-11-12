#include <iostream>
#include <locale>

int main() {
  std::string s(40, '=');
  std::cout << s << std::endl;

  for(auto loc : {"en_DK.UTF8", "en_IN.UTF8", "en_US.UTF8"}) {
      std::cout.imbue(std::locale(loc));
      std::cout << s.length() << " of " << s.max_size() << std::endl;
  }

/*
  while(true) {
    try {
      std::string l; //"en_us.UTF8"
      std::getline(std::cin, l);
      if(l.empty()) break;
      std::cout.imbue(std::locale(l + ".UTF8"));  
      std::cout << s.length() << " of " << s.max_size() << std::endl;
    } catch(...) {
      std::cout << "Nope!\n";
    }
  }
*/
  s = "Hello, world";
  for(char& c : s) c = std::toupper(c);
  std::cout << s << '\n';
  s.append(20, '!');
  std::cout << s << '\n';
  
  std::cout << s.substr(7,5) << std::endl;
  std::string t{s, 7, 5};
  std::cout << t << std::endl;
  
  const char* c =s.c_str();
  std::cout << c << std::endl;
  
  std::string cs{c};
  std::cout << cs << '\n';
  
  s.insert(0, 5, '>');
  std::cout << s << '\n';
    
}






/*
  for(auto loc : {"en_DK.UTF8", "en_IN.UTF8", "en_US.UTF8"}) {
      std::cout.imbue(std::locale(loc));
*/
