#include <iostream>

struct Vehicle{
int speed{0};
int distance_cm{0};
void accelerate(int amount){
  speed += amount;
}
void brake(int amount){
  speed -= amount;
}
bool is_too_close(){
  if(distance_cm < 200)  
    return true;
  else
    return false;
}
};

int main(){
  Vehicle a{50, 300};
  std::cout << "Vehicle a{50, 300};" << std::endl;
  std::cout << "Expected -> a: " << 50 << " km/h, " << 300 << " cm\n";
  std::cout << "\t\t\ta: " << a.speed << " km/h, " << a.distance_cm << " cm\n";

  
  Vehicle b{80, 150};
  std::cout << "Vehicle b{80, 150};" << std::endl;
  std::cout << "Expected -> b: " << 80 << " km/h, " << 150 << " cm\n";
  std::cout << "\t\t\tb: " << b.speed << " km/h, " << b.distance_cm << " cm\n";


  a.accelerate(20);
  std::cout << "a.accelerate(20);" << std::endl;
  std::cout << "Expected -> a: " << 70 << " km/h, " << 300 << " cm\n";
  std::cout << "\t\t\ta: " << a.speed << " km/h, " << a.distance_cm << " cm\n";
  b.brake(100);

  std::cout << "b.brake(100);" << std::endl;
  std::cout << "Expected -> b: " << -20 << " km/h, " << 150 << " cm\n";
  std::cout << "\t\t\tb: " << b.speed << " km/h, " << b.distance_cm << " cm\n";

  
  
  
  
  std::cout << std::boolalpha;
  std::cout << "a too close? " << a.is_too_close() << "\n";
  std::cout << "b too close? " << b.is_too_close() << "\n";
  Vehicle *p{&a};
  p -> brake(30);
   std::cout << "p -> brake(30);" << std::endl;
  std::cout << "Expected -> a after p->brake: " << 40<< " km/h\n";

  std::cout << "\t\t\ta after p->brake: " << a.speed << " km/h\n";
  
}