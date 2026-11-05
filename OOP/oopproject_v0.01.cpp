#include <iostream>
#include <string>
#include <cmath>


const int MAX_CREDIT_FOR_ANY_ACCOUNT{1000};
using std::string;
class Account { // The program must represent bank accounts. An account has an
                // owner’s name and a balance (it can have cents). If an account
                // is never given a balance, it must show 0, not junk.
private:
  double m_balance; // (it can have cents) -> double or float
  string m_owner;
  double m_credit{};
  bool m_withdrawn_lock = true;

public:
  // Account(double balance, string owner) : m_balance{balance}, m_owner{owner} {};
  // Account(double balance) : Account{balance, "None"} {};
  // Account(string owner) : Account{0, owner} {};
  // Account() : Account{0, "None"} {};
Account(double balance = 0, string owner = "None");
// Account(double balance);
// Account(double credit);
// Account(string owner, double credit);
Account(string owner);
// Account(){std::cout << "No__Args" << std::endl;};


//Copy Constructor
Account(const Account &source);

  
  // ~Account() { m_balance = 0; std::cout << "Called Destructor: " << m_owner << " Balance: " << m_balance << "." << std::endl; }
~Account() {std::cout << m_owner << " Balance: " << m_balance << "." << std::endl; }

  double deposit_money(double new_money){
    std::cout << "Depositing: " << new_money << std::endl;
    m_balance += new_money;    
    return m_balance;
  }
  
  double withdraw_money(double new_money){
    std::cout << "Withdrawing: " << new_money << std::endl;

    // 1. Check the projected balance beforehand
    double projected_balance = m_balance - new_money;

    // 2. If it goes negative and exceeds the max credit limit, deny the withdrawal
    if (projected_balance < 0 && std::abs(projected_balance) > MAX_CREDIT_FOR_ANY_ACCOUNT) {
      std::cout << "Denied: Exceeds maximum credit limit of " << MAX_CREDIT_FOR_ANY_ACCOUNT << "\n\n";
      return m_balance; // Return current balance without modifying it
    }

    // 3. Otherwise, perform the withdrawal
    m_balance = projected_balance;

    if(m_balance < 0){
      std::cout << "Negative Balance -> Yellow Flag\n";
      m_credit = m_balance;
      assign_credit();
    }

    return m_balance;
  }

  
  string get_owner() const {
    // std::cout << m_owner << std::endl;
    return m_owner;
  }
  double get_balance() const {
    // std::cout << m_balance << std::endl;
    return m_balance;
  }

  void assign_credit(){
    if(std::abs(m_credit) > MAX_CREDIT_FOR_ANY_ACCOUNT){
      m_withdrawn_lock = false;
      std::cout << "Negative Balance Above -> Red Flag" << "\t\t\t";
      std::cout << m_owner << "'s Account is Freezed" << "\n" << std::endl;
    }
          
  }
  
  void unlock_withdrawn_lock(){
      m_withdrawn_lock = true;
      std::cout << m_owner << "'s Account is Unfreezed" << "\n" << std::endl;
  }

  void set_balance(double new_balance){
    m_balance = new_balance;
    // std::cout << "You are about to change the Balance directly are you sure (Y/N)? : ";
    // char answer{};
    // std::cin >> answer;
    //   switch(answer){
    //       case('Y'):
    //            m_balance = new_balance;
    //            break;
    //        case('N'):
    //            break;
    //        default:
    //             break;
    //   }
  }

    
};

Account::Account(double balance, string owner): m_balance{balance}, m_owner{owner}{};
// Account::Account(double balance) : Account{balance, "None"} {}
// Account::Account(double credit) : Account{0, "None", 0} {};
// Account::Account(string owner, double credit) : Account{0, "None", 0} {}
Account::Account(string owner) : Account{0, owner} {};
// Account::Account() : Account{0, "None"} {}
Account::Account(const Account &source) : m_balance{source.m_balance}, m_owner{source.m_owner}, m_credit{source.m_credit}, m_withdrawn_lock{source.m_withdrawn_lock}{};

int main() {
  Account tom{10, "Tom"};
  Account frank{0, "Frank"};
  Account alice{500, "Alice"};
  Account bob{
      "Bob"}; // Create two separate accounts, one for Alice and one for Bob.
  std::cout << alice.get_owner() << ": " << alice.get_balance() << "\n";
  std::cout << bob.get_owner() << ": " << bob.get_balance() << "\n";
  alice.deposit_money(-50);
  std::cout << alice.get_owner() << ": " << alice.get_balance() << "\n";
  Account *pointer_bob_account{&bob};
  pointer_bob_account -> deposit_money(75.5); 
  std::cout << bob.get_owner() << ": " << bob.get_balance() << "\n";
  alice.set_balance(100);
  std::cout << alice.get_owner() << ": " << alice.get_balance() << "\n";

  Account alice_copy{alice};
  Account bob_copy{bob}; // Create two separate accounts, one for Alice and one for Bob.
  std::cout << alice_copy.get_owner() << ": " << alice_copy.get_balance() << "\n";
  std::cout << bob_copy.get_owner() << ": " << bob_copy.get_balance() << "\n";
  tom.withdraw_money(500);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.withdraw_money(500);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.withdraw_money(100);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.unlock_withdrawn_lock();
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.withdraw_money(500);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.withdraw_money(500);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  tom.withdraw_money(500);
  std::cout << tom.get_owner() << ": " << tom.get_balance() << "\n";
  return 0;

}
