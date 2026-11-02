#include <iostream>

class Vehicle {
private:
  int m_speed{0};
  int m_distance_cm{0};

public:
  int get_speed() const { return m_speed; }
  int get_distance_cm() const { return m_distance_cm; }
  void set_speed(int speed) {
    if(speed < 0){
      std::cout << "rejected: negative value\n";
    }
    else{
      m_speed = speed;
    }
  }
  void set_distance(int distance_cm){
    if(distance_cm < 0){
      std::cout << "rejected: negative value\n";
    }
    else{
      m_distance_cm = distance_cm;
    }
  }
  void accelerate(int amount){
    set_speed(m_speed+amount);
  }
};

int main(){
  Vehicle a;
  std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance_cm() << " cm\n";
  a.set_speed(60);
  a.set_distance(400);
  std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance_cm() << " cm\n";
  a.set_speed(-5);
  a.set_distance(-100);
  std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance_cm() << " cm\n";
  a.accelerate(15);
  std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance_cm() << " cm\n";

  a.accelerate(-100);
  std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance_cm() << " cm\n";
  // a.m_speed = 5;
  return 0;
}