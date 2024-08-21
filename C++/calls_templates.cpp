#include <iostream>
#include <map>
#include <string>

// Default argument example
int divide(int a, int b = 2) {
    return a / b;
}

// Call by value example
void mySwapByValue(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

// Call by reference using pointers
void mySwapByPointer(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Call by reference
void mySwapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

// Call by reference – Const References (Doesn't actually swap)
void mySwapConstReference(const int& x, const int& y) {
    int temp = x;
    // x = y; // Cannot modify const reference
    // y = temp; // Cannot modify const reference
}

// Reference return example
int& middleElement(std::map<std::string, int>& m) {
    int index = m.size() / 2;
    auto it = m.begin();
    std::advance(it, index);
    return it->second;
}

// Function overloading
void mySwap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}
void mySwap(double& x, double& y) {
    double temp = x;
    x = y;
    y = temp;
}
void mySwap(char& x, char& y) {
    char temp = x;
    x = y;
    y = temp;
}

// Function template
template <typename T>
void mySwapTemplate(T &x, T &y) {
    T temp = x;
    x = y;
    y = temp;
}

// Explicit specification template
template <typename T>
T createInstance() {
    T instance;
    return instance;
}

// Multiple template parameters
template <typename T1, typename T2>
void printPair(T1 a, T2 b) {
    std::cout << "(" << a << ", " << b << ")" << std::endl;
}

// Non-type template arguments
template <std::size_t N>
int* createAndInitializeArray() {
    int* arr = new int[N];
    for (std::size_t i = 0; i < N; ++i) {
        arr[i] = i;
    }
    return arr;
}

int main() {
    // Default argument example
    std::cout << "=== Default Argument ===" << std::endl;
    std::cout << divide(12) << std::endl;        // Output: 6
    std::cout << divide(20, 4) << std::endl;     // Output: 5
    std::cout << std::endl;

    // Call by value example
    std::cout << "=== Call by Value ===" << std::endl;
    int a = 10, b = 20;
    std::cout << "[Before] a: " << a << ", b: " << b << std::endl;
    mySwapByValue(a, b);
    std::cout << "[After] a: " << a << ", b: " << b << std::endl;  // No change
    std::cout << std::endl;

    // Call by reference using pointers
    std::cout << "=== Call by Reference (Pointer) ===" << std::endl;
    std::cout << "[Before] a: " << a << ", b: " << b << std::endl;
    mySwapByPointer(&a, &b);
    std::cout << "[After] a: " << a << ", b: " << b << std::endl;  // Swapped
    std::cout << std::endl;

    // Call by reference
    std::cout << "=== Call by Reference ===" << std::endl;
    mySwapByReference(a, b);  // Swapped back
    std::cout << "[After] a: " << a << ", b: " << b << std::endl;
    std::cout << std::endl;

    // Reference return example
    std::cout << "=== Reference Return ===" << std::endl;
    std::map<std::string, int> m = {{"a", 1}, {"b", 2}, {"c", 3}};
    middleElement(m) = 10;
    for (const auto& p : m) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
    std::cout << std::endl;

    // Function template example
    std::cout << "=== Function Template ===" << std::endl;
    mySwapTemplate(a, b);  // Using function template
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << std::endl;

    // Multiple template parameters
    std::cout << "=== Multiple Template Parameters ===" << std::endl;
    printPair(2.5, "orange");
    std::cout << std::endl;

    // Non-type template arguments
    std::cout << "=== Non-type Template Arguments ===" << std::endl;
    int* array1 = createAndInitializeArray<3>(); // 0 1 2
    int* array2 = createAndInitializeArray<5>(); // 0 1 2 3 4

    std::cout << "array1: ";
    for (std::size_t i = 0; i < 3; ++i) {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "array2: ";
    for (std::size_t i = 0; i < 5; ++i) {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    delete[] array1;
    delete[] array2;

    return 0;
}
