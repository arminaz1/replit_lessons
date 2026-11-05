// #include <iostream>

// class Vehicle {
// private:
//   int m_speed{0};
//   int m_distance_cm{0};


// public:
//   Vehicle(int a, int b);
//   Vehicle(int a);
//   Vehicle();

//   int get_speed() const { return m_speed; }
//   int get_distance() const { return m_distance_cm; }
//   void set_speed(int speed) {
//     if(speed < 0){
//       std::cout << "rejected: negative value\n";
//     }
//     else{
//       m_speed = speed;
//     }
//   }
//   void set_distance(int distance_cm){
//     if(distance_cm < 0){
//       std::cout << "rejected: negative value\n";
//     }
//     else{
//       m_distance_cm = distance_cm;
//     }
//   }
//   void accelerate(int amount){
//     set_speed(m_speed+amount);
//   }
// };

// Vehicle::Vehicle(int a, int b){
//   m_speed = 0;
//   m_distance_cm = 0;
//   if(a>= 0 && b >= 0){
//     m_speed = a;
//     m_distance_cm = b; 
//   }else if(b >= 0){
//     m_distance_cm = b;
//     std::cout << "speed constructor: default\n";        // inside Vehicle()
//   }else if(a>= 0){
//     m_speed = a;
//     std::cout << "distance constructor: default\n";        // inside Vehicle()
//   }else{
//     std::cout << "rejected: negative value\n";
//     std::cout << "constructor: default\n";
     
//   }
// }

// Vehicle::Vehicle(int a){
//   if(a < 0){
//     m_speed = 0;
//     std::cout << "constructor: default\n";        // inside Vehicle()
//   }else{
//     m_speed = a;
//   }
// }
// Vehicle::Vehicle(){ std::cout << "constructor: default\n"; }

// int main(){
//   Vehicle a;
//   std::cout << "a: " << a.get_speed() << " km/h, " << a.get_distance() << " cm\n";
//   Vehicle b{120, 450};
//   std::cout << "b: " << b.get_speed() << " km/h, " << b.get_distance() << " cm\n";
//   Vehicle c{80};
//   std::cout << "c: " << c.get_speed() << " km/h, " << c.get_distance() << " cm\n";
//   Vehicle d{-10, 200};
//   std::cout << "d: " << d.get_speed() << " km/h, " << d.get_distance() << " cm\n";
//   // Vehicle d{10, -200};
//   // std::cout << "d: " << d.get_speed() << " km/h, " << d.get_distance() << " cm\n";
//   // Vehicle d{-10, -200};
//   // std::cout << "d: " << d.get_speed() << " km/h, " << d.get_distance() << " cm\n";
//   Vehicle e = b;

//   std::cout << "e: " << e.get_speed() << " km/h, " << e.get_distance() << " cm\n";
  
//   return 0;
// }


#include <iostream>

class Vehicle {
public:
  Vehicle() = default;

  explicit Vehicle(int speed) {
    set_speed(speed);
  }

  Vehicle(int speed, int distance_cm) {
    set_speed(speed);
    set_distance(distance_cm);
  }

  int get_speed() const { return m_speed; }
  int get_distance() const { return m_distance_cm; }

  void set_speed(int speed) {
    if (speed < 0) {
      std::cout << "rejected: negative speed\n";
      return;
    }
    m_speed = speed;
  }

  void set_distance(int distance_cm) {
    if (distance_cm < 0) {
      std::cout << "rejected: negative distance\n";
      return;
    }
    m_distance_cm = distance_cm;
  }

  void accelerate(int amount) {
    set_speed(m_speed + amount);
  }

private:
  int m_speed{0};
  int m_distance_cm{0};
};

void print_vehicle(const char* name, const Vehicle& v) {
  std::cout << name << ": " << v.get_speed() << " km/h, "
            << v.get_distance() << " cm\n";
}

int main() {
  Vehicle a;
  Vehicle b{120, 450};
  Vehicle c{80};
  Vehicle d{-10, 200};

  print_vehicle("a", a);
  print_vehicle("b", b);
  print_vehicle("c", c);
  print_vehicle("d", d);

  Vehicle e{b};
  e.set_speed(10);
  print_vehicle("b", b);
  print_vehicle("e", e);

  return 0;
}