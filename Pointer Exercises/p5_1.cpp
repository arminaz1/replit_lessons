#include <iostream>
void try_change(int value);
int main(){
  int speed{50};
  std::cout << "\n" << "speed : " << speed << " | &speed : " << &speed << "\n" << std::endl;
  try_change(speed);
  std::cout << "speed : " << speed << " | &speed : " << &speed << "\n" << std::endl;
  
}


void try_change(int value){
  std::cout << "\n↓↓↓↓↓↓↓↓*try_change*↓↓↓↓↓↓↓↓\n" << std::endl;
  value = 999;
  std::cout << "value : " << value << " | &value : " << &value << std::endl;
  std::cout << "\n↑↑↑↑↑↑↑*try_change*↑↑↑↑↑↑↑↑\n" << std::endl;
}

/*
actual
speed : 50 | &speed : 0x7fffe4ff0814


↓↓↓↓↓↓↓↓*try_change*↓↓↓↓↓↓↓↓

value : 999 | &value : 0x7fffe4ff07ec

↑↑↑↑↑↑↑*try_change*↑↑↑↑↑↑↑↑

speed : 50 | &speed : 0x7fffe4ff0814 

*/
// speed did not change since -> we are working with the function, and when calling the function we are calling a copy of the variable, not the variable itself