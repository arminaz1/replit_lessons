#include <iostream>

// Catch L-values (Permanent boxes)
void identify(int &value) {
    std::cout << "Caught an L-value (Box): " << value << "\n";
}

// Catch R-values (Temporary ghosts)
void identify(int &&value) {
    std::cout << "Caught an R-value (Ghost): " << value << "\n";
}

int main() {
    int score = 100;

    identify(score);
    identify(score+50);
    identify(999);



    return 0;
}

/*Output : 
Caught an L-value (Box): 100
Caught an R-value (Ghost): 150
Caught an R-value (Ghost): 999
  */