#include <iostream>
#include "constants_.h"
#include <iomanip>
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
  const float charge_of_large_carpet{45};
  const float charge_of_small_carpet{35};
  const float tax_rate{0.06};
  const float days_valid_cost_estimate{30};

  cout << "\tCarpet Cleaning Service Cost Estimate\n";
  cout << "\t\t# of Small Carpet" << "{" << charge_of_small_carpet << "$}: "; 
  unsigned int small_carpet_number{0};
  cin >> small_carpet_number;
  cout << "\t\t# of Large Carpet" << "{" << charge_of_large_carpet << "$}: ";;
  unsigned int large_carpet_number{0};
  cin >> large_carpet_number;
  cout << "\t\ttax rate is: " << tax_rate;
  double fixed_cost{0};
  fixed_cost = (large_carpet_number * charge_of_large_carpet) + (small_carpet_number * charge_of_small_carpet);
  cout << "\n\t\t\t Cost: " << fixed_cost;
  float tax{1};
  tax = fixed_cost * tax_rate;
  cout << "\n\t\t\t Tax: " << tax;
  cout << "\n\t\t\t Estimate: " << tax + fixed_cost << "\n\t\t\t valid for " << days_valid_cost_estimate << " Days. " << endl;
}

