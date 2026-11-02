
// #include <iostream>

// int main() {
//   int *a{new int{5}};

//   std::cout << "a: " << *a << "\n";
//   delete a;
//   // std::cout << "a: " << *a << "\n";
//   a = nullptr;
//   // delete a;
//   std::cout << "a: " << *a << "\n";
//   return 0;
// }
// /*a: 5
// Segmentation fault*/

#include <iostream>

int main() {
  int *b{new int{9}};

  // std::cout << "a: " << *a << "\n";
  delete b;
  // std::cout << "a: " << *a << "\n";
  b = nullptr;
  // delete a;
  std::cout << "b: " << *b << "\n";
  return 0;
}
/*=================================================================
==793==ERROR: LeakSanitizer: detected memory leaks

Direct leak of 4 byte(s) in 1 object(s) allocated from:
    #0 0x7f84d54a4b78 in operator new(unsigned long) (/nix/store/xvzz97yk73hw03v5dhhz3j47ggwf1yq1-gcc-13.2.0-lib/lib/libasan.so.8+0xdcb78)
    #1 0x40110f in main (/home/runner/workspace/main+0x40110f)

SUMMARY: AddressSanitizer: 4 byte(s) leaked in 1 allocation(s).*/