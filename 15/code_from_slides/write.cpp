#include <iostream>
#include <fstream>

int main () {
  std::ofstream ofs {"output.txt"};
  if (!ofs) throw std::runtime_error{"can’t open output file output.txt"};

  ofs << "Writing this to a file.\n";
  return 0;
}
