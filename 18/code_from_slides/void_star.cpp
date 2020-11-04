#include <iostream>

void f(void* pv) {
  void* pv2 = pv;
  int* pi_cast = (int*) pv;
  int* pi_static_cast = static_cast<int*>(pv2);
  std::cout << *pi_cast << ' ' << *pi_static_cast << std::endl;
}

int main() {
  int pi = 3;
  f((void*)&pi);
}
