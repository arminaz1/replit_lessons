
#include <iostream>

int main() {
  int *a{new int{5}};

  std::cout << "a: " << *a << "\n";
  // delete a;
  // std::cout << "a: " << *a << "\n";
  a = nullptr;
  delete a;
  std::cout << "a: " << *a << "\n";
  return 0;
}
