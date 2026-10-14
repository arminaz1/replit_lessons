#include <iostream>

int main(){

  int a{10}, b{20};
  const int* p1{&a};
  int* const p2{&a};
  const int* const p3{&a};
  // *p1 = 99; // not possible
   p1 = &b;
  *p2= 99; 
   // p2 = &b; // not possible
  // p3 = &b; //not possible
  // *p3 = 99; //not possible
  // conclusion :  const int* p1{&a}; makes what is pointing to constant
  // con2 : int* const p2{&a}; makees the address constant
  // con3 : both address and the pointing at of p3 is constant
}


/*p7_1.cpp:13:34: error: assignment of read-only location ‘* p1’
   13 |     if constexpr (requires { *p1 = 99; }) {
      |                              ~~~~^~~~
p7_1.cpp:37:33: error: assignment of read-only variable ‘p2’
   37 |     if constexpr (requires { p2 = &b; }) {
      |                              ~~~^~~~*/