#include <iostream>

void bad_swap(int* a, int* b);
int main(){
  int front{30}, rear{80};
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;
    bad_swap(&front, &rear);
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;
    bad_swap(&front, nullptr);
  std::cout << "\n\tfront: " << front << "|\trear: " << rear << std::endl;
}

void bad_swap(int* a, int* b){
  std::cout << "\n↓↓↓↓↓↓↓↓*bad_swap*↓↓↓↓↓↓↓↓\n" << std::endl;
  int* temp{nullptr};
  temp = a;
  a = b;
  b = temp;
  std::cout<< "\n\ta: "<< *a <<"\tb: "<< *b << std::endl;
  std::cout << "\n↑↑↑↑↑↑↑*bad_swap*↑↑↑↑↑↑↑↑\n" << std::endl;
  // well here we are working only with the addresses, as always think of pointer like the office with shelfs that has the shelves filled with the cases that hold the addresses, so now there are two things you could do goin to the address where the case exists, or going to the address that is present in that case. what we are doing here is getting the address of 2 cases, creating a temp to hold adress of 1 of them, and re assign the second address to the other words, in other words we are swaping the case shelf for that two address instead of changing the valu stored on that address. 
}

/**↓↓↓↓↓↓↓↓*bad_swap*↓↓↓↓↓↓↓↓


    a: 80   b: 30

↑↑↑↑↑↑↑*bad_swap*↑↑↑↑↑↑↑↑


    front: 30|  rear: 80

↓↓↓↓↓↓↓↓*bad_swap*↓↓↓↓↓↓↓↓


Segmentation fault*/