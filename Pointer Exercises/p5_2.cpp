#include <iostream>
/*Exercise P5.2: Passing the Address

  (Covers: an int* parameter, & at the call site, * inside the function to write)

  Scenario: Same program idea, but now the helper must really change the speed. The only change is what you hand to the function.

  Requirements:

  New program, or edit the old one. In main, declare int speed{50}; and print speed and &speed.
  Write a function set_speed that takes an int* named target and an int named new_value, and returns nothing. Inside it, do three things:
  print target (the address it received)
  write new_value into the box target points to
  print *target
  In main, call set_speed with the address of speed and the value 999. Then print speed and &speed again.
  Add two comments:
  Did speed change this time? What is different from P5.1?
  Is target (printed inside the function) equal to &speed? Compare with what you found for &value in P5.1*/

void set_speed(int* target, int new_value);
int main(){
  int speed{50};
  std::cout << "\n" << "speed : " << speed << " | &speed : " << &speed << "\n" << std::endl;
  set_speed(&speed, 30); //well &speed -> because we should pass the address, the function gets the adress
  std::cout << "\n" << "speed : " << speed << " | &speed : " << &speed << "\n" << std::endl; // the function has got the address &speed, so means goes directly on there, and does not work with local copy that exists in the function that get discarded when stack gets empty, so the speed that was defined inteh main function would be changed for real
  return 0;
}

void set_speed(int* target, int new_value){
  std::cout << "\n↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓\n" << std::endl;
  *target = new_value;
  std::cout << "target : " << target << " | &target : " << &target << std::endl; // target itself is addresss holder, and the &target is the address of this address holder
  std::cout << "\n*target : " << *target << std::endl; 
  
  std::cout << "\n↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑\n" << std::endl;
}

/* actual 
speed : 50 | &speed : 0x7ffcb37e1224


↓↓↓↓↓↓↓↓*set_speed*↓↓↓↓↓↓↓↓

target : 0x7ffcb37e1224 | &target : 0x7ffcb37e11f8

 *target : 30

↑↑↑↑↑↑↑*set_speed*↑↑↑↑↑↑↑↑


speed : 30 | &speed : 0x7ffcb37e1224 
*/