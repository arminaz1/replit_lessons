#include <iostream>
#include <string>
#include <vector>
const unsigned int MAX_SUPPORTED_RAM{
    128}; // if you are using the global variable use the const to prevent from
          // accidentall change

void sys_greeter();
void print_array(std::string array[], size_t size_of_array);



int main() {
  std::vector<unsigned int> cluster_ram{};
  int choice{};
  int time_out{};
  
  do{
    time_out++;
    std::cout << "\n=== Cluster Management Menu ===" << std::endl;
    std::cout << "1. Add a Node (RAM)\n2. View Cluster Specs\n3. Exit\nSelection: \t";
    std::cin >> choice;
    unsigned int temp{};
    switch(choice){
      case (1):
        std::cout << "Enter RAM for new node (GB): " << std::endl;
        // unsigned int temp{};
        std::cin >> temp;
        cluster_ram.push_back(temp);
        break;
      
      case(2):
        if(cluster_ram.size() == 0){
          std::cout << "Cluster is empty." << std::endl;
        }
        else{
          for(auto ram : cluster_ram){
            std::cout << "RAM NODE: " << ram;
        
          }
        }
        break;
      case(3):
        std::cout << "Shutting down system ... Goodbye!" << std::endl;
        break;
      default:
        std::cout << "Unknown Command" << std::endl;
    }
    
  }while(choice!=3 && time_out < 100);
  // sys_greeter();
  return 0;
}




void print_array(std::string array[], size_t size_of_array) {
  std::cout << "Supported OS: ";
  for (size_t i = 0; i < size_of_array; ++i) {
    std::cout << array[i] << ", ";
  }
  std::cout << "\b\b" << std::endl;
}

void sys_greeter() {
  std::string allowed_os[3] = {"Windows", "Replit", "Linux"};
  std::string greet_text;
  std::cout << "--- System Initialization ---" << std::endl;
  std::cout << "Enter your primary OS: ";

  std::cin >> greet_text;

  std::cout << "Congiguration Saved for OS: " << greet_text << std::endl;
  std::vector<unsigned int> cluster_ram{};
  double cpu_speed{};
  bool Laptop_or_Desktop{1};
  print_array(allowed_os, 3);
  unsigned int Node1{}, Node2{}, Node3{};

  std::cout << "Enter First RAM (in GB): " << std::endl;
  std::cin >> Node1;

  std::cout << "Enter Second RAM (in GB): " << std::endl;
  std::cin >> Node2;

  std::cout << "Enter Third RAM (in GB): " << std::endl;
  std::cin >> Node3;
  cluster_ram.push_back(Node1);
  cluster_ram.push_back(Node2);
  cluster_ram.push_back(Node3);

  std::cout << "Enter CPU speed(in GHz): " << std::endl;
  std::cin >> cpu_speed;
  std::cout << "Is this Laptop? (1 for yes, 0 for No): " << std::endl;
  std::cin >> Laptop_or_Desktop;

  std::cout << "Number of RAMs: " << cluster_ram.size()
            << "(Max Supported:" << MAX_SUPPORTED_RAM << ")" << std::endl;
  std::cout << "CPU: " << cpu_speed << "GHz" << std::endl;
  std::cout << "Portable: " << Laptop_or_Desktop << std::endl;

  std::cout << "Memory used to store CPU vairable: " << sizeof(cpu_speed)
            << std::endl;
  unsigned int total_ram{0};
  for(int i = 0; i < cluster_ram.size(); ++i){
     total_ram += cluster_ram.at(i);
  }
  double average_ram{0};
  average_ram = static_cast<double>(total_ram)/cluster_ram.size();

  bool is_deployable;
  is_deployable = (total_ram <= MAX_SUPPORTED_RAM) && (cpu_speed > 2.0);
  int nodes_deployed = cluster_ram.size();
  nodes_deployed ++;

  std::cout << "Total RAM: " << total_ram 
            << "| Average RAMs Capacity: " << average_ram << "| Is deployable: " << is_deployable << "| Nodes Deployed: " << nodes_deployed-- << std::endl;
    
}