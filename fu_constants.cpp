#include <iostream>
#include <chrono>
#include <thread>
#include "constants_.h"
using namespace std;

void fu_constants(){
  const uint validity{30};
  const double price_per_room{30};
  const float tax{0.06};
  int room{1};
  cout << "Enter the number of rooms to be cleaned: ";
  cin >> room;
  cout << "\n" << "Number of rooms: " << room; 
  
  cout << "\n" << "Price per room: " << price_per_room << "$";

  cout << "\n" << "tax: " << tax << "$" ;
  cout << "\ncost: " << (room * price_per_room) ; 
  double total_estimate{0};
  // int validity{30};
  
  total_estimate = (room * price_per_room) + (room * price_per_room*tax);
 cout << "\n" << "Cleaning Cost Estimate: " << total_estimate << "\n" << "The estimate is valid for " << validity << " DAYS" << endl;
  
}

void carpet_cleaning_cost(){
  const float charge_of_large_carpet{25};
  const float charge_of_small_carpet{35};
  const float tax_rate{0.06};
  const float days_valid_cost_estimate{30};

  cout << "\tCarpet Cleaning Service Cost Estimate";
  cout << "\n\tSmall Carpet: "; 
  unsigned int small_carpet_number{0};
  cin >> small_carpet_number;
  cout << "\n\t Large Carpet: ";
  unsigned int large_carpet_number{0};
  cin >> large_carpet_number;
  cout << "\n\ttax rate is: " << tax_rate;
  std::this_thread::sleep_for(std::chrono::seconds(10));
  
}