#include <iostream>
#include <string>
using std::string;
class Account{ //The program must represent bank accounts. An account has an owner’s name and a balance (it can have cents). If an account is never given a balance, it must show 0, not junk.
private:
    double m_balance; // (it can have cents) -> double or float 
    string m_owner;
public: 
  Account(double balance, string owner) : m_balance{balance}, m_owner{owner}{};
  Account() : Account{0, "None"}{};
  Account(double balance) : Account{balance, "None"}{};
  Account(string owner) : Account{0, owner}{};
  const string& owner() const { return m_owner; }
  double balance() const { return m_balance; }
  ~Account(){
    std::cout << "Called Destructor" << std::endl;
    
  }
};

int main(){
  Account alice{500, "Alice"}; Account bob{"Bob"}; //Create two separate accounts, one for Alice and one for Bob.
  std::cout << alice.owner() << ": " << alice.balance() << "\n";
  std::cout << bob.owner() << ": " << bob.balance() << "\n";
  
}
