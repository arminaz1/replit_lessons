#include <iostream>
#include <string>

class Account {
private:
  double m_balance;
  std::string m_owner;
  static inline int s_count{0}; 

  // The rule "amount must be positive" lives here, once.
  bool permission(double amount) const {
    if (amount <= 0) {
      std::cout << "refused: amount must be positive\n";
      return false;
    }
    return true;
  }

public:
  
  Account(double balance, const std::string& owner)
      : m_balance{balance >= 0 ? balance : 0}, m_owner{owner} {
        ++s_count;
    if (balance < 0) {
      std::cout << "refused: negative opening balance\n";
    }
  }

  bool deposit(double amount) {
    if (!permission(amount)) {
      return false;
    }
    m_balance += amount;
    return true;
  }

  bool withdraw(double amount) {
    if (!permission(amount)) {
      return false;
    }
    if (amount > m_balance) {
      std::cout << "refused: balance would go below 0\n";
      return false;
    }
    m_balance -= amount;
    return true;
  }
  Account (const Account &source): m_balance{source.m_balance}, m_owner{source.m_owner}{++s_count;}
  static int get_count(){return s_count;}

  const Account *print_address(){return this;}

  Account &deposit_chain( double amount){
        this->m_balance += amount;
        return *this;
  }

  bool is_richer_than(const Account &other) const{

    if(this->m_balance > other.m_balance){
      return true;}
    else{
      return false;
    }
  }
  ~Account(){
    --s_count;
    std::cout << "Closing " << m_owner << " with " << m_balance << "\n";
  }
  double get_balance() const { return m_balance; }
  const std::string& get_owner() const { return m_owner; }
};

int main() {
  Account alice{100, "Alice "}, bob{50, "Bob"};
  std::cout << "this: " << alice.print_address() << " | &alice: " << &alice << "\n";
  
  
  std::cout << "this: " << bob.print_address() << " | &bob: " << &bob << "\n";

  
  alice.deposit_chain(10).deposit_chain(20).deposit_chain(30);
  std::cout << "Alice " << alice.get_balance() << "\n";
  std::cout << "alice richer than bob? " << std::boolalpha << alice.is_richer_than(bob) << "\n";
  std::cout << "bob richer than bob? " << std::boolalpha << bob.is_richer_than(alice) << "\n";
  return 0;
}