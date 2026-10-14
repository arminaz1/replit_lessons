#include <iostream>


int sum_readings(const int* data, size_t n);
void double_all(int* data, size_t n);
int main(){
  size_t count{};
  int readings[5] = {11, 34, 64, 88, 22};
  std::cout << sizeof(readings) << " | " << sizeof(readings[0]); 
  count = sizeof(readings)/sizeof(readings[0]);
  std::cout <<"\n______0________\n" << std::endl;
  std::cout << sum_readings(readings, count);
  // std::cout <<"\n______1________\n" << std::endl;
  // std::cout << sum_readings(&readings[2], 3);
  // std::cout <<"\n_______2_______\n" << std::endl;
  // std::cout << sum_readings(nullptr, 5);


  std::cout <<"\n______3________\n" << std::endl;
  double_all(readings, count);
  std::cout <<"\n______0________\n" << std::endl;
  std::cout << sum_readings(readings, count);
  const int fixed[3] = {1, 2, 3};
  std::cout << sum_readings(fixed, 3);
  // double_all(fixed, 3); // not possible to change constant
  std::cout << sum_readings(fixed, 3);
  
  // std::cout <<"\n______4________\n" << std::endl;
  // std::cout << duuble_all(&readings[2], 3);
  // std::cout <<"\n_______5_______\n" << std::endl;
  // std::cout << 
    // duuble_all(nullptr, 5);
  return 0;
}

int sum_readings(const int* data, size_t n){
  //data[0] = 0; 
  /*
  error: assignment of read-only location ‘* data’
   37 |   data[0] = 0;
      |   ~~~~~~~~^~~
      */
  /*
  data[0] = 0
  p7_2.cpp:44:11: error: assignment of read-only location ‘* data’
   44 |   data[0] = 0
      |   ~~~~~~~~^~~
  */
  
  if(data == nullptr){
    return 0;
  }
  int sum{};
  for(size_t i = 0; i < n; ++i ){
    sum += data[i];
    std::cout << "sum: "<< sum << " | data[" << i <<"]: "<< data[i] << std::endl;
  }
  std::cout << "sizeof(data): " << sizeof(data) << std::endl;

  return sum;

}

void double_all(int* data, size_t n){
  if(data == nullptr){
    return;
  }
  for(size_t i = 0; i < n; ++i){
    data[i] *= 2;
  }
}

