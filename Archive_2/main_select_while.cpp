#include <cctype>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> list_of_number{};
  char select{};
  while (select != 'q') {
    cout << "P - Print Numbers\n"
         << "A - Add a number\n"
         << "M - Display mean of numbers\n"
         << "S - Display the smallest number\n"
         << "L - Display the largest number\n"
         << "Q - Quit";
    cout << "\nEnter your choice: ";
    cin >> select;
    select = tolower(select);

    if (select == 'q') {
      break;
    } else if (select == 'p') {
      if(list_of_number.size() == 0){
         cout<<"[]\n"; 
      }else{
        cout << "[";
        for (int i = 0 ; i < list_of_number.size(); ++i) {
          cout << list_of_number.at(i) << ",";
        }
        cout << "\b]\n";
      }
    } else if (select == 'a') {
      int new_element{};
      cout << "Input the integer to be add to the list: ";
      cin >> new_element;
      list_of_number.push_back(new_element);
      cout << new_element << " Was add to the list!\n";
    }

    else if (select == 'm') {
      int sum{};
      if (list_of_number.size() > 1) {
        for (int i= 0; i < list_of_number.size(); ++i) {

          sum += list_of_number.at(i);
        }
        cout << "mean = " << sum / list_of_number.size() << "\n";
      } else {
        cout << "Not Enough Data!!!\n";
      }
    }

    else if (select == 's') {
      int smallest{};
      if (list_of_number.size() > 0) {
        smallest = list_of_number.at(0);
        for (int i = 1; i < list_of_number.size(); ++i) {
          if (list_of_number.at(i) < smallest) {
            smallest = list_of_number.at(i);
          } else {
            continue;
          }
        }
        cout << "Smallest = " << smallest << "\n";
      } else {
        cout << "List is empty!!!\n";
      }
    } else if (select == 'l') {
      int largest{};
      if (list_of_number.size() > 0) {
        largest = list_of_number.at(0);
        for (int i = 1; i < list_of_number.size(); ++i) {
          if (list_of_number.at(i) > largest) {
            largest = list_of_number.at(i);
          } else {
            continue;
          }
        }
        cout << "Largest = " << largest;
      } else {
        cout << "List is empty!!!\n";
      }
    } else {
      cout << "Invalid Input" << endl;
    }
  }

  return 0;
}