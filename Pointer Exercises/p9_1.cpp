#include <iostream>

int *make_box(int value);
int main() {
  int local{10};
  int *heap{new int{42}};

  std::cout << "local: " << local << " at " << &local << "\n";
  std::cout << "heap:  " << *heap << " at " << heap << "\n";
  *heap = 100;
  std::cout << "after write: " << *heap << "\n";
  std::cout << std::boolalpha << "heap is null? " << (heap == nullptr) << "\n";
  std::cout << "sizeof(heap): " << sizeof(*heap) << "\n";

  int *box = make_box(7);

  std::cout << "box: " << *box << "\n";
  delete heap;
  heap = nullptr;
  delete box;
  box = nullptr;

  std::cout << std::boolalpha << "heap is null? " << (heap == nullptr) << "\n";

  return 0;
}

int *make_box(int value) {
  int *p{new int{value}};
  return p;
}