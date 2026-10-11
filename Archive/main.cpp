// #include "hello.h"
// #include "favnum.h"
// // #include "c_in_out.h"
// #include "areaofroom.h"
// #include "primitve_type.h"
// #include "sizeof.h"
// #include "constants_.h"
// #include "Vector_.h"
// #include "rational_opt_conversion.h"
// #include <iostream>
// int main() {
//   // fu_sizeof();
//   // sayHello();
//   // favNum();
//   // c_in_out();
//   // areaRectangle();
//   // primitiveType();
//   // fu_constants();
//   // carpet_cleaning_cost();
//   // vector_example();
//   // rational_opt_conversion();

//   return 0;
// }

#include <iostream>

enum class BunchOfNumber { Zero, One, Three };
// enum BunchOfNumber : char { Zero = '0', One = 'A', Three = '3' };
int main() {
  int x{};
  
  std::cin >> x;
  (x > 5) ? std::cout <<"greater than 5" : std::cout <<"less or equal than 5";

}