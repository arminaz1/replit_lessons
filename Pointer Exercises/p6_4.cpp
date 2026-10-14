#include <iostream>

int main () { 
  double values[3] = {1.5, 2.5, 3.5};
  double* dp{values};
  
  std::cout << ""<< dp << std::endl;
  std::cout << "" << sizeof(double) << " |||| " << dp+1 << std::endl; //apart equal to sizeof(double)
  std::cout << ""<< *(dp) << std::endl;
  std::cout << "" << *(dp+2) << std::endl;
  int readings[5] = {11, 34, 64, 88, 22};
  int* p{readings};
  std::cout << "" << sizeof(readings) << " |||| " <<  sizeof(p) << std::endl;
  std::cout << "" << sizeof(readings)/sizeof(readings[0]) << std::endl;
  return 0;
}

/*0x7ffd32e2fe50
8 |||| 0x7ffd32e2fe58
1.5
8 |||| 3.5
20 |||| 8
5*/