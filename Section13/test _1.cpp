#include <iostream>
#include <string>

// --- THE PARENT ---
class Node {
protected: 
    std::string m_name;

public:
    Node(std::string name) : m_name{name} {}

    // The 'virtual' keyword tells C++: 
    // "If a child has a better version of this function, use the child's version instead!"
    virtual void boot_up() {
        std::cout << "[Node] Booting generic server: " << m_name << "\n";
    }

    // A virtual destructor is MANDATORY if you use virtual functions, 
    // to ensure the child's memory is deleted properly.
    virtual ~Node() {} 
};

// --- THE CHILD ---
class DatabaseNode : public Node {
public:
    DatabaseNode(std::string name) : Node(name) {}

    // The 'override' keyword is a safety check. 
    // It tells the compiler to double-check that we are actually replacing a parent function.
    void boot_up() override {
        std::cout << "[DatabaseNode] Spinning up hard drives for DB: " << m_name << "\n";
    }
};

int main() {
    // 1. Create a Child object normally
    DatabaseNode my_db("DB_Primary");

    // 2. Create a Parent Pointer, but point it at the Child object!
    // This is legal because a DatabaseNode "IS A" Node.
    Node* cluster_pointer = &my_db;

    std::cout << "--- Execution Start ---\n";

    // 3. We call boot_up() using the PARENT pointer. Which one runs?
    cluster_pointer->boot_up();

    std::cout << "--- Execution End ---\n";
    return 0;
}