#include <iostream>

void swap_value(int* first, int* second);
int main(){
  int front{30}, rear{80};
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;
  swap_value(&front, &rear);
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;
  swap_value(&front, nullptr);
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;

}

void swap_value(int* first, int* second){
  if(first == nullptr || second == nullptr){
    return;
  }
  int temp{}; //temp is needed to save the value of *first before changing it and dump it. (there is another way to this function with pointer arthmatic)
  temp = *first;
  *first = *second;
  *second = temp;
  // this function won't work because this way we are giving the address of the variables that we want to change to the funciton while the function itself works with the copy of them, and won't work without pointer
}
/*

front: 30|  rear: 80

front: 80|  rear: 30

front: 80|  rear: 30*/
