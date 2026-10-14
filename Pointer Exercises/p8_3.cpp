#include <iostream>

int main(){
  int front{30}, rear{80}, left{55};
  int* sensors[3] = {&front, &rear, &left};
  for(int i = 0; i < 3 ; ++i){
    std::cout << "sensors[" << i << "] -> " << *sensors[i] << "\n";
  }
  *sensors[1] = 100;
  std::cout << "rear: " << rear << "\n";
  int** cursor{sensors};
  std::cout << "cursor start: " << **cursor << "\n";
  ++cursor;
  std::cout << "cursor index 1: " << **cursor << "\n";
  **cursor = 0;

  
  std::cout << "left: " << left << " rear: " << rear << " front: " << front << "\n";

  int* temp{sensors[0]};
  std::cout << "*: " << std::endl;
  sensors[0] = sensors[2];
  std::cout << "**: " << std::endl;
  sensors[2] = temp;
  std::cout << "front: " << front << " left: " << left << "\n";
  for(int i = 0; i < 3 ; ++i){
    std::cout << "sensors[" << i << "] -> " << *sensors[i] << "\n";
  }
}