#include <iostream>

// This function accepts two POINTERS (memory addresses)
void swap_components(int* ptr_a, int* ptr_b) {
    // Step 1: Create a normal integer named 'temp'.
  int temp{};
  
    // Step 2: Put the VALUE AT ptr_a into 'temp'. (Hint: use *ptr_a)
  temp = *ptr_a; 
    // Step 3: Put the VALUE AT ptr_b into the location ptr_a is pointing to.
    *ptr_a = *ptr_b; 
    // Step 4: Put the 'temp' value into the location ptr_b is pointing to.
    *ptr_b = temp; 
}

void swap_components_2(int* ptr_a, int* ptr_b) {
  *ptr_a = *ptr_a + *ptr_b; 
  *ptr_b = *ptr_a - *ptr_b;
  *ptr_a = *ptr_a - *ptr_b;
}
int main() {
    int cpu_temp = 85;
    int gpu_temp = 92;

    std::cout << "Before: CPU=" << cpu_temp << ", GPU=" << gpu_temp << "\n";

    // Step 5: Call swap_components. 
    // You cannot just pass 'cpu_temp' (that's a value). 
    // You must pass the ADDRESS OF cpu_temp and gpu_temp. (Hint: use &)
    // swap_components( ... , ... );
    swap_components(&cpu_temp, &gpu_temp);

    std::cout << "After: CPU=" << cpu_temp << ", GPU=" << gpu_temp << "\n";

  std::cout << "Before: CPU=" << cpu_temp << ", GPU=" << gpu_temp << "\n";

  // Step 5: Call swap_components. 
  // You cannot just pass 'cpu_temp' (that's a value). 
  // You must pass the ADDRESS OF cpu_temp and gpu_temp. (Hint: use &)
  // swap_components( ... , ... );
  swap_components_2(&cpu_temp, &gpu_temp);

  std::cout << "After: CPU=" << cpu_temp << ", GPU=" << gpu_temp << "\n";
  
    return 0;
}