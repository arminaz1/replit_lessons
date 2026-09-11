#include "areaofroom.h"
#include <iostream>
using std::cin;
using std::cout;
void areaRectangle() {
  int height = 0;
  int width = 0;
  int area = 0;
  cout << "Enter Height: ";
  cin >> height;
  cout << "Enter width: ";
  cin >> width;
  cout << "\n";
  area = height * width;
  cout << area << std::endl;
}