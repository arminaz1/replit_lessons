#include <iostream>
#include <utility> // For std::move

class Resource {
public:
    int* data;

    // Normal Constructor
    Resource(int val) {
        data = new int(val);
        std::cout << "Constructed data.\n";
    }

    // Destructor
    ~Resource() {
        if (data != nullptr) {
            std::cout << "Destructor freeing memory.\n";
            delete data;
        } else {
            std::cout << "Destructor saw nullptr. Ghost died peacefully.\n";
        }
    }

    // Copy Constructor (SLOW: Deep Copy)
    Resource(const Resource& source) {
        data = new int(*source.data); 
        std::cout << "COPY Constructor used (Deep copy).\n";
    }
    Resource(Resource&& source){this -> data = source.data; source.data = nullptr;std::cout << "MOVE Constructor used (Memory stolen!).\n";}
    // YOUR TURN: Write the Move Constructor
    // 1. Signature takes 'Resource&& source'
    // 2. Steal the memory: assign this->data to source.data
    // 3. Nullify source: set source.data to nullptr
    // 4. Print: std::cout << "MOVE Constructor used (Memory stolen!).\n";


};

int main() {
    std::cout << "1. Creating A:\n";
    Resource a(100); 

    std::cout << "\n2. Copying A to B:\n";
    Resource b(a); // 'a' is an L-value. Triggers COPY.

    std::cout << "\n3. Moving A to C:\n";
    // std::move() forces 'a' to look like a temporary R-value ghost.
    Resource c(std::move(a)); // Triggers MOVE!

    std::cout << "\n4. Program ending. Destructors will run:\n";
    return 0;
}

/*1. Creating A:
Constructed data.

2. Copying A to B:
COPY Constructor used (Deep copy).

3. Moving A to C:
MOVE Constructor used (Memory stolen!).

4. Program ending. Destructors will run:
Destructor freeing memory.
Destructor freeing memory.
Destructor saw nullptr. Ghost died peacefully.*/