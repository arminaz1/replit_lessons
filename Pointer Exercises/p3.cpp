#include <iostream>


int main(){
  int speed{50}, limit{90};
  int* p{&speed};
  std::cout << "speed : " << speed << " limit : " << limit << " *p : " << *p << std::endl;
  std::cout << "\nspeed = "<< *p << std::endl;
  std::cout << "(Predict-> \nspeed = "<< "50)" << std::endl;
  std::cout << "\nspeed + 5 = "<< *p + 5 << std::endl;
  std::cout << "(Predict-> \nspeed + 5 = "<< "55)" << std::endl;
  p = &limit; 
  std::cout << "\nlimit = "<< *p << std::endl;
  std::cout << "(Predict-> \nlimit = "<< "90)" << std::endl;
  *p = 100;
  std::cout << "\nspeed : " << speed << " limit : " << limit << " *p : " << *p;
  std::cout << "(Predict -> \nspeed : " << "55" << " limit : " << "100" <<std::endl;

  int* q{p};
  std::cout << "q: " << q << "p: " << p << std::endl;
  std::cout << "Predict-> \n q: " << "&limit it is an adress" << "p: " << "yes they should be equal" << std::endl;

  *q = 120; 
  std::cout << "*q: " << *q << "*p: " << *p << "limit: "<< limit << std::endl;
  std::cout << "Predict-> \n *q: " << "120" << "*p: " << "120 = limit" << std::endl;

  p = &speed;  

  std::cout << "speed: " << speed << " limit : " <<  limit << " adress P: "<< p << std::endl;
  *p = limit;
  std::cout << "speed: " << speed << " limit : " <<  limit << " adress P: "<< p << std::endl;
  p = &limit;
  std::cout << "speed: " << speed << " limit : " <<  limit << " adress P: "<< p << std::endl;

  // well p = &speed -> we give the adress of the speed to p -> *P changes the speed value 
  // *p = limit -> we change the value of what pointer points att -> so in other words we are writing the speed = limit, means assigning the value of limit to the variable of speed or *p
}