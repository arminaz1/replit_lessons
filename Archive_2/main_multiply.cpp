#include <iostream>

int* apply_all(const int* arr1, const int* arr2, size_t len1, size_t len2);
void print_array(int array[], size_t size_of_array);

int main() {
    int array1[]{1, 2, 3, 4, 5};
    int array2[]{10, 20, 30};

    print_array(array1, 5);
    print_array(array2, 3);

    int* result = apply_all(array1, array2, 5, 3);
    print_array(result, 15);

    // Free the dynamically allocated memory once you are done with it
    delete[] result; 

    return 0;
}

int* apply_all(const int* arr1, const int* arr2, size_t len1, size_t len2) {
    size_t size_max = len1 * len2;
    int* output = new int[size_max]; 
    int* out_ptr = output; // Use a separate pointer to traverse so we don't lose the original address

    for(size_t i = 0; i < len1; ++i) {
        int current_val = arr1[i]; // Cache this value so we don't fetch it len2 times
        for(size_t j = 0; j < len2; ++j) {
            *out_ptr = current_val * arr2[j]; // Assign the multiplication
            out_ptr++;                        // Increment the traversal pointer
        }
    }

    return output; // Return the original starting address
}

// int* apply_all(int* arr1, int* arr2, size_t len1, size_t len2) {
//     // 1. Allocate an array large enough for all combinations
//     size_t size_max = len1 * len2;
//     int* output = new int[size_max]; 

//     size_t index = 0;

//     // 2. Use braces to ensure both assignment and increment happen inside the inner loop
//     for(size_t i = 0; i < len1; ++i) {
//         for(size_t j = 0; j < len2; ++j) {
//             output[index] = arr1[i] * arr2[j];
//             index++;
//         }
//     }

//     // 3. Return the pointer so main() can use it (do not delete it here)
//     return output;
// }

void print_array(int array[], size_t size_of_array) {
    std::cout << "[ ";
    for (size_t i = 0; i < size_of_array; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << "]" << std::endl;
}



/*#include <iostream>

int* apply_all(int* arr1, int* arr2, size_t len1, size_t len2);
void print_array(int array[], size_t size_of_array);
int main(){
  int array1[]{1,2,3,4,5};
  int array2[]{10,20,30};
  print_array(array1, 5);
  print_array(array2, 3);
  int* reslut = apply_all(array1, array2, 5, 3);
  print_array(reslut, 15);

}

int* apply_all(int* arr1, int* arr2, size_t len1, size_t len2){
  int* output = new int;
  size_t size_max = len1*len2;
  size_t index{};
  for(size_t i = 0; i < len1; ++i){
    for(size_t j = 0; j < len2; ++j){
      *output = arr1[i] * arr2[j];
      output++;  
    }
  }

  delete output;
  output = nullptr;
  return output;
}

void print_array(int array[], size_t size_of_array) {
  std::cout << "Supported OS: ";
  for (size_t i = 0; i < size_of_array; ++i) {
    std::cout << array[i] << ", ";
  }
  std::cout << "\b\b" << std::endl;
}*/