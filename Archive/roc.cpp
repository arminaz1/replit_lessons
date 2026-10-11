#include <iostream> 
#include "rational_opt_conversion.h"
using namespace std;

void rational_opt_conversion(){
  const int QUARTER{25};
  const int DIME{10};
  const int NICKEL{5};
  const int PENNY{1};
  const int DOLLAR{100};
  
  int amount{0};
  cout << "Enter amount in CENTS: "; cin >> amount;
  
  int dollar{0};
  // static_cast<float>(quarter);
  dollar = amount/DOLLAR;
  cout << "dollar: " << dollar << endl; 
  amount -= dollar*DOLLAR; 
  // cout << "rest: " << amount << endl; 
  int quarter{0};
  // static_cast<float>(quarter);
  quarter = amount/QUARTER;
  cout << "quarter: " << quarter << endl;
  amount -= quarter*QUARTER; 
  // cout << "rest: " << amount << endl; 

  
  int dime{0};
  // static_cast<float>(quarter);
  dime = amount/DIME;
  cout << "dime: " << dime << endl;
  amount -= dime*DIME; 
  // cout << "rest: " << amount << endl; 
  
  float nickel{0};
  // nickel = static_cast<float>(nickel);
  nickel = amount/NICKEL;
  cout << "nickel: " << nickel << endl;
  amount -= nickel*NICKEL; 
  // cout << "rest: " << amount << endl; 
  
  float pennies{0};
  // static_cast<float>(quarter);
  pennies = amount/PENNY;
  cout << "pennies: " << pennies << endl;
}