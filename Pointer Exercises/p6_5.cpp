#include <iostream>


int sum_readings(int* data, size_t n);
int main(){
  size_t count{};
  int readings[5] = {11, 34, 64, 88, 22};
  std::cout << sizeof(readings) << " | " << sizeof(readings[0]); 
  count = sizeof(readings)/sizeof(readings[0]);
  std::cout <<"\n______0________\n" << std::endl;
  std::cout << sum_readings(readings, count);
  std::cout <<"\n______1________\n" << std::endl;
  std::cout << sum_readings(&readings[2], 3);
  std::cout <<"\n_______3_______\n" << std::endl;
  std::cout << sum_readings(nullptr, 5);
  return 0;
}

int sum_readings(int* data, size_t n){
  if(data == nullptr){
    return 0;
  }
  double sum{};
  for(size_t i = 0; i < n; ++i ){
    sum += data[i];
    std::cout << "sum: "<< sum << " | data[" << i <<"]: "<< data[i] << std::endl;
  }
  std::cout << "sizeof(data): " << sizeof(data) << std::endl;
  
  return sum;
  
}

/*20 | 4
______0________

sum: 11 | data[0]: 11
sum: 45 | data[1]: 34
sum: 109 | data[2]: 64
sum: 197 | data[3]: 88
sum: 219 | data[4]: 22
sizeof(data): 8
219
______1________

sum: 64 | data[0]: 64
sum: 152 | data[1]: 88
sum: 174 | data[2]: 22
sizeof(data): 8
174
_______3_______
*/