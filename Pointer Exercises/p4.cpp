#include <iostream> 

int main(){
  int distance_cm{150};
  int* sensor{&distance_cm};
  int* disconnected{nullptr};

  std::cout << "Actual: sesonr: " << sensor << "disconnected : " << disconnected << std::endl;
  std::cout << "Expected: sesonr: " << "0x7 ... " << " | disconnected : " << "0" << std::endl;

  if(sensor != nullptr){
    std::cout<< "Distance: " <<  distance_cm << "cm (E: this will be executed)" << std::endl;
  }
  else{
    std::cout << "Sensor not connected" << std::endl;
  }
  if(disconnected != nullptr){
    std::cout<< "Distance: " <<  distance_cm << "cm" << std::endl;
  }
  else{
    std::cout << "Sensor not connected (E: this will be executed)" << std::endl;
  } 
  sensor = nullptr;
  if(sensor != nullptr){
    std::cout<< "Distance: " <<  distance_cm << "cm" << std::endl;
  }
  else{
    std::cout << "Sensor not connected (E: this will be executed)" << std::endl;
  }
  std::cout<< "Distance: " <<  distance_cm << "cm" << std::endl;
  std::cout<< "Distance: did not change, nothing change it"  << std::endl;
  if(sensor == disconnected){
    std::cout << "are equal"<< std::endl;
  }
  std::cout << *disconnected << std::endl;

  /*
  int* p{nullptr}; safer than int* p;
  Random Memory Access, not initializing means randomly picking a memory adddress, that might have important information inside o if 
  */
  
  return 0;
}