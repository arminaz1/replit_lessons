#include <iostream>

struct Vehicle{
int speed{0};
int distance_cm{0};
};

int main(){
  Vehicle a;
std::cout << "___1___" << std::endl;
  std::cout << "e-> a: " << 0 << " km/h, " << 0 << " cm\n";
  std::cout << "\ta: " << a.speed << " km/h, " << a.distance_cm << " cm\n";
  
  std::cout << "___2___" << std::endl;
  Vehicle b{120, 450};
  std::cout << "e-> b: " << 120 << " km/h, " << 450 << " cm\n";
  std::cout << "\tb: " << b.speed << " km/h, " << b.distance_cm << " cm\n";

  
  a.speed = 50;
  a.distance_cm = 300;
  std::cout << "e-> a: " << 50 << " km/h, " << 300 << " cm\n";
  std::cout << "\ta: " << a.speed << " km/h, " << a.distance_cm << " cm\n";

  std::cout << "___3___" << std::endl;
  Vehicle c{b};
  c.speed = 10;
  std::cout << "e-> b: " << 120 << " km/h, " << 450 << " cm\n";

  std::cout << "\tb: " << b.speed << " km/h, " << b.distance_cm << " cm\n";
  std::cout << "e-> c: " << 10 << " km/h, " << 450 << " cm\n";
  std::cout << "\tc: " << c.speed << " km/h, " << c.distance_cm << " cm\n";
  std::cout << "___4___" << std::endl;
  Vehicle *p{&a};
  p -> speed = 70;
  std::cout << "e-> a.speed via p: " << 70 << "\n";
  std::cout << "\ta.speed via p: " << a.speed << "\n";
  std::cout << "___5___\n" << std::endl;
  std::cout << "sizeof Vehicle: " << sizeof(Vehicle) << ", sizeof int: " << sizeof(int) << "\n";
  return 0;
}