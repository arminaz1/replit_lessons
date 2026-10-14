#include <iostream>
void bad_switch(int* slot, int* target);
void switch_sensor(int** slot, int* target);
int main(){
  int front{120}, rear{45};
  int* active{&front};
  std::cout << "start:      *active = " << *active << "\n";
  bad_switch(active, &rear);
  std::cout << "after bad:  *active = " << *active << "\n";
  switch_sensor(&active, &rear);
  std::cout << "after good: *active = " << *active << "\n";
  std::cout << std::boolalpha << "active == &rear? " << (active == &rear) << "\n";
  switch_sensor(nullptr, &front);
  std::cout << "after null: *active = " << *active << "\n";
  return 0;
}

void bad_switch(int* slot, int* target){
  if(slot==nullptr || target == nullptr){
    return;
  }
 slot=target; 
}

void switch_sensor(int** slot, int* target){
  if(slot == nullptr || target == nullptr || *slot == nullptr){
    std::cout << "switch_sensor: no slot\n";
    return;
  }
  *slot = target;
}
