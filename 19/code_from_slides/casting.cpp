class A {};
class B {};

int main() {
  A* a = new A;
  B* b = (B*)(a);
  B* s = static_cast<B*>(a);  // Uncomment to see the error
  B* d = dynamic_cast<B*>(a); // Uncomment to see the error
}
