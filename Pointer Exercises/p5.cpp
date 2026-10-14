#include <iostream>

void try_change(int &value);
void set_speed(int *target, int new_value);
void swap_values(int *ptr_a, int *ptr_b);
void bad_swap(int *a, int *b);
bool read_sensor(int* out_cm);
int main() {\
  int speed{50};
  int *pointer_p1{&speed};
  int front{30};
  int rear{80};
  int distance_cm{500};
  std::cout << "\n\n\n____________________\n\n" << std::endl;
  if(read_sensor(&distance_cm)){
    std::cout << distance_cm << std::endl;
  }else{
    std::cout << " Read Failed " << std::endl;
  }
  std::cout << "\n\n\n____________________\n\n" << std::endl;
  swap_values(&front, &rear);
  
  std::cout << "\n\n\n____________________\n\n" << std::endl;
  bad_swap(&front, &rear);
  
  std::cout << "\n\n\n____________________\n\n" << std::endl;
  try_change(speed);
  set_speed(&speed, 1001);
  std::cout << "&speed: " << &speed << std::endl;
  std::cout << "speed: " << speed << std::endl;

  set_speed(pointer_p1, 1510);
  std::cout << "&speed: " << &speed << std::endl;
  std::cout << "speed: " << speed << std::endl;

  set_speed(nullptr, 1510);
  std::cout << "&speed: " << &speed << std::endl;
  std::cout << "speed: " << speed << std::endl;
  return 0;
}

void try_change(int &value) {
  value = 999;
  std::cout << "&value: " << &value << std::endl;
  std::cout << "value: " << value << std::endl;
}

void set_speed(int *target, int new_value) {
  // target = &new_value;
  if (target == nullptr) {
    std::cout << "!!!!!!!NO TARGET!!!!!! " << std::endl;
  }
  *target = new_value;
  std::cout << "target: " << target << std::endl;
}

void swap_values(int *ptr_a, int *ptr_b) {
  std::cout << "*ptr_b: " << *ptr_b << std::endl;
  std::cout << "*ptr_a: " << *ptr_a << std::endl;
  int temp{};
  temp = *ptr_a;
  *ptr_a = *ptr_b;
  *ptr_b = temp;
  std::cout << "*ptr_b: " << *ptr_b << std::endl;
  std::cout << "*ptr_a: " << *ptr_a << std::endl;
}

void bad_swap(int* a, int* b) {
  std::cout << "*a: " << *a << std::endl;
  std::cout << "*b: " << *b << std::endl;
  int *temp{};
  temp = a;
  a = b;
  b = temp;
  std::cout << "*a: " << *a << std::endl;
  std::cout << "*b: " << *b << std::endl;
}

bool read_sensor(int* out_cm){
  if(out_cm == nullptr){
    return false;
  }else{
    std::cout << "*out_cm: " << *out_cm << std::endl;
    return true;
  }
} 