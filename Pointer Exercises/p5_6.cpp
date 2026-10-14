#include <iostream> 



bool read_sensor(int* out_cm);

int main(){
  int distance_cm{0};
  std::cout << "\t\ndistance_cm: " << distance_cm << std::endl;
  if(read_sensor(&distance_cm)){
    std::cout << "\t\nDistance: " << distance_cm << " cm" << std::endl;
  }else{
    std::cout << "\t\nRead Failed! " << std::endl;
  }
  //well here we access to the loaction of the memory which we want to change the value and we change the value the, and we get true and false from our function, like lets say hiring the workers and ask them only report done or not done, (but what we expect if they report done is new building) 

  if(read_sensor(nullptr)){
    std::cout << "\t\nDistance: " << distance_cm << " cm" << std::endl;
  }else{
    std::cout << "\t\nRead Failed! " << std::endl;
  }
}

bool read_sensor(int* out_cm){
  if(out_cm == nullptr){
    std::cout << "Error! "<< std::endl;
    return false;
  }
  *out_cm = 142;
  return true;
}
/*
distance_cm: 0

Distance: 142 cm
Error! 
*/