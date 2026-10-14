#include <iostream>

int main(){
  int readings[5] = {11, 34, 64, 88, 22};
  int* p{readings};
  int* end{readings + 5}; //it is safe to print, but it doesn't show anything we expect, or could know, no it is not safe to derefrence it, we don't know what is stored there
  std::cout <<"\n______0________\n" << std::endl;
  while(p!= end){
    std::cout << "\tp: " << p << "\t|\tend: " << end << std::endl;
    std::cout <<"\t*p: " << *p << std::endl;
    ++p;
    std::cout << "\tp: " << p << "\t|\tend: " << end << std::endl;
  }
  std::cout <<"\n_______________\n" << std::endl;
  std::cout << "\tp: " << p << "\t|\tend: " << end << std::endl; //yes they should be equal otherwise p!=end? what is the use? exit when p == end meands when address of reading = adress of reading + 5*sizeof(int)

  p = readings;
  for(int* it{readings}; it != end; ++it){
    std::cout << "\tp: " << p << "\t|\tit: " << it << std::endl;
    // p = it;
    *it += 100;
    std::cout <<"\t*p: " << *p << std::endl;
  }
  std::cout << "\tp: " << p << "\t|\tend: " << end << std::endl;

  for(int i = 0; i < 5; ++i){
    std::cout << readings[i] << ", " << std::endl;
    
  }
  std::cout << "\b\b\n" << std::endl;
  //what is the difference between p += 1 and *p += 1? p+=1 -> means address of p + sizeof(type of variable), *p += 1 value of what is stored in *p + and equal to 1
  p = readings;
  std::cout << "p+=1: \t"<< p << "|\t*p+1: \t"<< *p << std::endl;
  p+=1;
  std::cout << "p+=1: \t"<< p << "|\t*p+1: \t"<< *p << std::endl;
  p = readings;
  *p+=1;
  std::cout << "p+=1: \t"<< p << "|\t*p+1: \t"<< *p << std::endl;

  return 0;

}


/*______0________

    p: 0x7ffe09890a10   |   end: 0x7ffe09890a24
    *p: 11
    p: 0x7ffe09890a14   |   end: 0x7ffe09890a24
    p: 0x7ffe09890a14   |   end: 0x7ffe09890a24
    *p: 34
    p: 0x7ffe09890a18   |   end: 0x7ffe09890a24
    p: 0x7ffe09890a18   |   end: 0x7ffe09890a24
    *p: 64
    p: 0x7ffe09890a1c   |   end: 0x7ffe09890a24
    p: 0x7ffe09890a1c   |   end: 0x7ffe09890a24
    *p: 88
    p: 0x7ffe09890a20   |   end: 0x7ffe09890a24
    p: 0x7ffe09890a20   |   end: 0x7ffe09890a24
    *p: 22
    p: 0x7ffe09890a24   |   end: 0x7ffe09890a24

_______________

    p: 0x7ffe09890a24   |   end: 0x7ffe09890a24
    p: 0x7ffe09890a10   |   it: 0x7ffe09890a10
    *p: 111
    p: 0x7ffe09890a10   |   it: 0x7ffe09890a14
    *p: 111
    p: 0x7ffe09890a10   |   it: 0x7ffe09890a18
    *p: 111
    p: 0x7ffe09890a10   |   it: 0x7ffe09890a1c
    *p: 111
    p: 0x7ffe09890a10   |   it: 0x7ffe09890a20
    *p: 111
    p: 0x7ffe09890a10   |   end: 0x7ffe09890a24
111, 
134, 
164, 
188, 
122, 


p+=1:   0x7ffe09890a10| *p+1:   111
p+=1:   0x7ffe09890a14| *p+1:   134
p+=1:   0x7ffe09890a10| *p+1:   112 

*/