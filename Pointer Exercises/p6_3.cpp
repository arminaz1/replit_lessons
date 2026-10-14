#include <iostream>

int main () { 
  int readings[5] = {11, 34, 64, 88, 22};
  int* p{readings};
  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< readings[i] << std::endl;
    std::cout << "&readings["<<  i << "]: "<< &readings[i] << std::endl;
  }
  *(p+2) = 75;

  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< readings[i] << std::endl;
    std::cout << "&readings["<<  i << "]: "<< &readings[i] << std::endl;
    if(i==2 && readings[i] == 75){
      std::cout << "PASSED" << std::endl;
    }
  }
  *(p+4) += 10;
  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< readings[i] << std::endl;
    std::cout << "&readings["<<  i << "]: "<< &readings[i] << std::endl;
    if(i==4 && readings[i] == 32){
      std::cout << "\nPASSED" << std::endl;
    }
  }
  
   std::cout << "*****************" << std::endl;
  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< *(p+i) << std::endl;
  }
  std::cout << "*****************" << std::endl;

  
  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< p[i] << std::endl;
    }
  

   std::cout << "*****************" << std::endl;
  
  
  return 0;
}


/* &readings[0]: 0x7fff72af7520
  readings[1]: 34
  &readings[1]: 0x7fff72af7524
  readings[2]: 64
  &readings[2]: 0x7fff72af7528
  readings[3]: 88
  &readings[3]: 0x7fff72af752c
  readings[4]: 22
  &readings[4]: 0x7fff72af7530
  readings[0]: 11
  &readings[0]: 0x7fff72af7520
  readings[1]: 34
  &readings[1]: 0x7fff72af7524
  readings[2]: 75
  &readings[2]: 0x7fff72af7528
  PASSED
  readings[3]: 88
  &readings[3]: 0x7fff72af752c
  readings[4]: 22
  &readings[4]: 0x7fff72af7530
  readings[0]: 11
  &readings[0]: 0x7fff72af7520
  readings[1]: 34
  &readings[1]: 0x7fff72af7524
  readings[2]: 75
  &readings[2]: 0x7fff72af7528
  readings[3]: 88
  &readings[3]: 0x7fff72af752c
  readings[4]: 32
  &readings[4]: 0x7fff72af7530

  PASSED
  *****************
  readings[0]: 11
  readings[1]: 34
  readings[2]: 75
  readings[3]: 88
  readings[4]: 32
  *****************
  readings[0]: 11
  readings[1]: 34
  readings[2]: 75
  readings[3]: 88
  readings[4]: 32 */
