#include <iostream>
#include <string>

class Log {
private:
  int *m_data;

public:
  Log(int value) {
    m_data = new int;
    *m_data = value;
  }
  ~Log() {
    delete m_data;
    std::cout << "Freed" << std::endl;
  }
  int get() { return *m_data; }
  void set(int value) { *m_data = value; }
  void *getter() { return m_data; }
  Log &operator = (const Log &source){
    if(&sorce){
      return *this;
    }
    return *this;
}
};

int main() {
  Log a{10}, b{a};
  a = b; 
  std::cout << "a.get(): " << a.get() << " | b.get(): " << b.get() << "\n";
  b.set(99);
  std::cout << "a data at " << &a << " | b data at " << &b << "\n";
  std::cout << "a.getter(): " << a.getter() << " | b.gettter(): " << b.getter()
            << "\n";
  std::cout << "This is with Copy function Log(const Log &source): m_data{new "
               "int{*source.m_data}}{}"
            << std::endl;
}
