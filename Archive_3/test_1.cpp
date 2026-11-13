#include <iostream>
#include <string>

// --- THE PARENT ---
class Node {
protected: 
    std::string m_name;
    int m_ram;

public:
    Node(std::string name, int ram) : m_name{name}, m_ram{ram} {
        std::cout << "1. Parent Node foundation built.\n";
    }
};

// --- THE CHILD ---
class DatabaseNode : public Node {
private:
    int m_storage; // Only the Database has this

public:
    DatabaseNode(std::string name,int ram, int storage) : Node(name, ram), m_storage{storage}{std::cout << "2. Child Database built.\n";}
    // YOUR TURN: Write the Constructor!
    // Catch 'name', 'ram', and 'storage'. 
    // Pass 'name' and 'ram' to Node. Set m_storage.
    // Inside the { }, add: std::cout << "2. Child Database built.\n";


    void print_db() {
        // Look! The child is using m_name and m_ram from the parent!
        std::cout << "DB Name: " << m_name << " | RAM: " << m_ram << "GB | Storage: " << m_storage << "TB\n";
    }
};

int main() {
    // We pass all 3 arguments to the Child
    DatabaseNode my_db("Main_DB", 64, 100);

    my_db.print_db();

    return 0;
}

/*1. Parent Node foundation built.
2. Child Database built.
DB Name: Main_DB | RAM: 64GB | Storage: 100TB*/