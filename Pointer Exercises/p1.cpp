#include <iostream>



int main() {
  int a{10}, b{20}, c{30};
  int* pointer_a{&a}; // pointer_a should be equal to address of a (pointer_a = &a)
  
  std::cout << " \ta : " << a << " \tb : " << b << " \tc : " << c << std::endl;
  std::cout << " \ta : " << &a << " \tb : " << &b << " \tc : " << &c<< std::endl;
  std::cout << "Pointer_a: " << pointer_a << "       &a: " << &a << std::endl;
  std::cout << "*Pointer_a: " << *pointer_a << std::endl; //equals to value of a

  std::cout << "(address of) &Pointer_a: " << &pointer_a << std::endl; // address of pointer is the location of where the pointer is hold, and inside of it is the address of the variable that points to. same as the real world, the files that hold the adress of all people, has a adress (for example drawer 5 row 5, column 5. then when you open it youhave the addreess of person you are looking for)

  int* pointer_b{&b};
std::cout << "*pointer_b : " << *pointer_b << std::endl; // go to the address which is pointer_b holds and tell me what is inside of it so go to &b and tell me what value holds -> b = 20;

  std::cout << "sizeof(pointer_a): " << sizeof(pointer_a) << " sizeof(a) : " << sizeof(a) << " sizeof(double*) : " << sizeof(double*) << std::endl; 
  
 
  return 0;
}

/* output P1 : 
a : 10  b : 20  c : 30
a : 0x7ffd4fb8997c  b : 0x7ffd4fb89978  c : 0x7ffd4fb89974
it is possible to change the address the second time, depends how replit shell works 


Actual output P1 
std::cout << " \ta : " << a << " \tb : " << b << " \tc : " << c << std::endl;
    std::cout << " \ta : " << &a << " \tb : " << &b << " \tc : " << &c<< std::endl;*/

/* actual result : p2
~/workspace$ g++ -Wall -Wextra -Werror -pedantic p1.cpp -o main && ./main
    a : 10  b : 20  c : 30
    a : 0x7ffdf08aa9d4  b : 0x7ffdf08aa9d8     c : 0x7ffdf08aa9dc
Pointer_a: 0x7ffdf08aa9d4       &a: 0x7ffdf08aa9d4
*Pointer_a: 10
(address of) &Pointer_a: 0x7ffdf08aa9e0
*pointer_b : 20
sizeof(pointer_a): 8 sizeof(a) : 4 sizeof(double*) : 8
~/workspace$ g++ -Wall -Wextra -Werror -pedantic p1.cpp -o main && ./main
    a : 10  b : 20  c : 30
    a : 0x7ffe55e04d04  b : 0x7ffe55e04d08  c : 0x7ffe55e04d0c
Pointer_a: 0x7ffe55e04d04       &a: 0x7ffe55e04d04
*Pointer_a: 10
(address of) &Pointer_a: 0x7ffe55e04d10
*pointer_b : 20
sizeof(pointer_a): 8 sizeof(a) : 4 sizeof(double*) : 8
~/workspace$ ^C
*/