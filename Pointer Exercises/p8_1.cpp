#include <iostream>

int main(){
  int x{10};
  int* a{&x};
  int** pp{&a};
  std::cout << "x: " << x << "\t|\t*a: " << *a << "\t|\t**pp: " << **pp << std::endl;
  if(x == *a && *a == **pp){
    std::cout << "x == *a && *a == **pp -> pass" << std::endl;
  }
  
  std::cout << "---------------------" << std::endl;
  
  std::cout << "&x: " << &x << "\t|\t*a: " << a << "\t|\t*pp: " << *pp << std::endl;
  if(&x == a && a == *pp){
    std::cout << "&x == a && a == *pp -> pass" << std::endl;
  }

  std::cout << "---------------------" << std::endl;
   
  std::cout << "&a: " << &a << "\t|\tpp: " << pp << "\t|\t&pp: " << &pp <<std::endl;
  if(&a == pp){
    std::cout << "&a = pp -> pass" << std::endl;
  }
std::cout << "\n\n Change **pp = 50 \n->";
  **pp = 50; 
  std::cout << "x: " << x << "\t|\t*a: " << *a << "\t|\t**pp: " << **pp << std::endl;
  if(x == *a && *a == **pp){
    std::cout << "x == *a && *a == **pp -> pass" << std::endl;
  }else{
    std::cout << "x == *a && *a == **pp -> failed" << std::endl;
  }
  std::cout << "\n\n y = 99 and *pp = &y  \n->";
  int y{99};
  *pp = &y;

  std::cout << "x: " << x << " | a = &y? "<< std::boolalpha << (a==&y) << "\t|\t*a: " << a << "\t|\ty: " << y <<"\t|\t**pp: " <<**pp<<  std::endl;

  
  

  std::cout << "=========================================================\n";
  std::cout << "                POINTER ANALOGY EXPLAINED                \n";
  std::cout << "=========================================================\n\n";

  std::cout << "--- THE HOME (Variable x) ---\n";
  std::cout << "Information inside the home          (x)    : " << x << "\n";
  std::cout << "The actual address of the home       (&x)   : " << &x << "\n\n";

  std::cout << "--- THE FILE (Pointer a) ---\n";
  std::cout << "What is written in the file          (a)    : " << a << "\n";
  std::cout << "Information found by following a     (*a)   : " << *a << "\n";
  std::cout << "Where the file itself is kept        (&a)   : " << &a << "\n\n";

  std::cout << "--- THE SHELF (Double Pointer pp) ---\n";
  std::cout << "What is written on the shelf         (pp)   : " << pp << "\n";
  std::cout << "Information found by following pp    (*pp)  : " << *pp << " (Points to the home)\n";
  std::cout << "Information found by double-checking (**pp) : " << **pp << " (Gets info inside home)\n";
  std::cout << "Where the shelf itself is kept       (&pp)  : " << &pp << "\n";

  std::cout << "\n=========================================================\n";
  return 0;
}