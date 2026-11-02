#include <iostream>

// BROKEN: returns the address of a local variable.
int* bad_reading() {
  int value{42};   // 'value' is a box on the stack, owned by this function
  return &value;   // we hand out its address...
}                  // ...but the box is discarded HERE, when the function ends.
                   // The caller gets an address that no longer belongs to anyone.

// SAFE (pointer version): the box lives on the heap, so it survives the function.
int* good_reading() {
  return new int{42};   // like make_box in P9: the caller must delete it
}

// SAFEST: when you only need a number back, return the number itself.
int good_value() {
  return 42;   // a copy of the int travels back; a copy can never dangle
}

int main() {
  // --- the bug ---
  int* r{bad_reading()};          // r now holds an address that is already dead
  std::cout << "bad:  " << *r << "\n";   // undefined behavior: may print 42, junk, or crash

  // --- the heap fix ---
  int* g{good_reading()};
  std::cout << "good: " << *g << "\n";
  delete g;           // main owns this box now, so main must return it
  g = nullptr;

  // --- the simple fix ---
  std::cout << "value: " << good_value() << "\n";

  return 0;
}