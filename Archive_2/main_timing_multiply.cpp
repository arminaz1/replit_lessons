#include <iostream>
#include <chrono> // Required for high-resolution timing

// Standard version
int* apply_all_standard(const int* arr1, const int* arr2, size_t len1, size_t len2) {
    size_t size_max = len1 * len2;
    int* output = new int[size_max]; 

    size_t index = 0;
    for(size_t i = 0; i < len1; ++i) {
        for(size_t j = 0; j < len2; ++j) {
            output[index] = arr1[i] * arr2[j];
            index++;
        }
    }
    return output;
}

// Optimized version
int* apply_all_optimized(const int* arr1, const int* arr2, size_t len1, size_t len2) {
    size_t size_max = len1 * len2;
    int* output = new int[size_max]; 
    int* out_ptr = output; 

    for(size_t i = 0; i < len1; ++i) {
        int current_val = arr1[i]; 
        for(size_t j = 0; j < len2; ++j) {
            *out_ptr = current_val * arr2[j]; 
            out_ptr++;                        
        }
    }
    return output;
}

int main() {
    // 1. Setup massive arrays to make the timing noticeable
    const size_t size1 = 5;
    const size_t size2 = 4;

    // Dynamically allocate to avoid stack overflow with large arrays
    int* array1 = new int[size1];
    int* array2 = new int[size2];

    // Fill with dummy data
    for (size_t i = 0; i < size1; ++i) array1[i] = i + 1;
    for (size_t i = 0; i < size2; ++i) array2[i] = i + 2;

    std::cout << "Calculating " << (size1 * size2) << " combinations...\n\n";

    // ---------------------------------------------------------
    // 2. Measure Standard Version
    // ---------------------------------------------------------
    auto start_standard = std::chrono::high_resolution_clock::now();

    int* result_standard = apply_all_standard(array1, array2, size1, size2);

    auto end_standard = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_standard = end_standard - start_standard;

    std::cout << "Standard version took:  " << duration_standard.count() << " ms\n";

    // ---------------------------------------------------------
    // 3. Measure Optimized Version
    // ---------------------------------------------------------
    auto start_optimized = std::chrono::high_resolution_clock::now();

    int* result_optimized = apply_all_optimized(array1, array2, size1, size2);

    auto end_optimized = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_optimized = end_optimized - start_optimized;

    std::cout << "Optimized version took: " << duration_optimized.count() << " ms\n";

    // ---------------------------------------------------------
    // 4. Clean up memory
    // ---------------------------------------------------------
    delete[] array1;
    delete[] array2;
    delete[] result_standard;
    delete[] result_optimized;

    return 0;
}