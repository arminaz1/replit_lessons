#include "favnum.h"
#include <iostream>
using namespace std;
void favNum() {
  int favorite_number;
  cout << endl << "Enter Your Favorite Number between 1 to 100: ";
  cin >> favorite_number;
  if (0 < favorite_number && favorite_number < 101) {
    cout << "Amazin! That's my favoirte number too!"
         << "\n";
    cout << "No really !!, " << favorite_number << " is my favoirte number"
         << endl;
  } else {
    cout << "Is not between 1 and 100" << endl;
  }
}
