#include <iostream> 
#include <string>
class Node{
private:
  std::string m_name;
  unsigned int m_capacity;

public:
  std::string get_name() const{
      return m_name;
  }
  
  unsigned int get_capacity() const{
    return m_capacity;
  }
Node(std::string name_in, unsigned int cap_in) {
  name_in = m_name;
  cap_in = m_capacity;
  }
};

// void Node::print_name(){
  
// }

int main(){
  Node ram1{"RAM1", 16};
  // Node ram2{"RAM2", 32};
  ram1.get_name();
  // ram2.get_name();
  ram1.get_capacity();
  // ram2.get_capacity();
  std::cout << "Node: " << ram1.get_name() << " | RAM: " << ram1.get_capacity() << "GB\n";
  return 0;
}