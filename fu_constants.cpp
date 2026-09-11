#include <iostream>
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