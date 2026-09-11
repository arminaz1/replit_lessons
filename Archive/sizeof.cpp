#include <iostream>
#include "sizeof.h"
#include <climits>
#include <cfloat>
using namespace std;

void fu_sizeof(){
  cout << "char: " << sizeof(char) << "\n";
  cout << "int: " << sizeof(int) << "\n";
  cout << "long: " << sizeof(long) << endl;
  /************************************/
  //////////////////////////////////////
  cout << "Minimum Values: " << endl;
  cout << "char: " << CHAR_MIN << endl;
  cout << "int: " << INT_MIN << endl;
  cout << "short: " << SHRT_MIN << endl;
  cout << "long: " << LONG_MIN << endl;
  cout << "long long: " << LLONG_MIN << endl;

  int age{21};
  cout << "age variable size: " << sizeof(age) << endl; 

  cout << "Loading ... ";
  cout << "Done!     \n";
} 