#include <iostream>

int main () { 
  int readings[5] = {11, 34, 64, 88, 22};
  for(int i = 0; i < 5; ++i){
    std::cout << "readings["<<  i << "]: "<< readings[i] << std::endl;
    std::cout << "&readings["<<  i << "]: "<< &readings[i] << std::endl;
  }
  std::cout << "readings=\t" << readings << std::endl;
  std::cout << "&readings[0]=\t" << &readings[0] << std::endl;
  std::cout << "sizeof(int)=\t" << sizeof(int) << std::endl;
  //yes readings and readings0 are same-> since when defining a new list, we are dfining the initial part of the list, the initial part where the list start. 
  //there should be 5*sizeof(int) the initial part and the end  of the list
  return 0;
}


/*readings[0]: 11
&readings[0]: 0x7ffc0d239c00
readings[1]: 34
&readings[1]: 0x7ffc0d239c04
readings[2]: 64
&readings[2]: 0x7ffc0d239c08
readings[3]: 88
&readings[3]: 0x7ffc0d239c0c
readings[4]: 22
&readings[4]: 0x7ffc0d239c10
readings=   0x7ffc0d239c00
&readings[0]=   0x7ffc0d239c00
sizeof(int)=    4*/
