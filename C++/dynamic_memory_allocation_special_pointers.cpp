#include <iostream>
#include <vector>
#include <memory>
#include <new> // For std::bad_alloc

//Only capable std=c++17 (++)

void dynamicMemoryAllocation() {
    int *array;
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;
    
    try {
        array = new int[n];
        std::cout << "Memory allocated using new" << std::endl;
        delete[] array;
        std::cout << "Memory deallocated using delete[]" << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        return;
    }

    array = new (std::nothrow) int[n];
    if (array == nullptr) {
        std::cerr << "Memory allocation failed using nothrow" << std::endl;
        return;
    }
    std::cout << "Memory allocated using new (nothrow)" << std::endl;
    delete[] array;
    std::cout << "Memory deallocated using delete[]" << std::endl;
}

void vectorPointerExample() {
    std::vector<int>* myVector = new std::vector<int>();
    myVector->push_back(10);
    myVector->push_back(20);
    
    std::cout << "First element: " << (*myVector)[0] << std::endl;
    std::cout << "Elements (range-based for loop): ";
    for (int elem : *myVector) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "Elements (using iterators): ";
    for (std::vector<int>::iterator it = myVector->begin(); it != myVector->end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    delete myVector;
}

void smartPointerExample() {
    // unique_ptr example
    std::unique_ptr<std::vector<int>> vecPtr(new std::vector<int>());
    vecPtr->push_back(10);
    vecPtr->push_back(20);
    (*vecPtr)[0] = 30;
    
    std::cout << "Elements in unique_ptr vector: ";
    for (auto item : *vecPtr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // shared_ptr example
    std::shared_ptr<std::vector<int>> vecPtr1(new std::vector<int>());
    std::shared_ptr<std::vector<int>> vecPtr2 = vecPtr1;
    vecPtr1->push_back(1);
    vecPtr2->push_back(2);
    
    std::cout << "Elements in shared_ptr vector: ";
    for (auto item : *vecPtr1) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

    // make_unique and make_shared example
    auto uniquePtr = std::make_unique<std::vector<int>>();
    auto sharedPtr = std::make_shared<std::vector<int>>();
    uniquePtr->push_back(100);
    sharedPtr->push_back(200);
    
    std::cout << "Element in uniquePtr vector: " << (*uniquePtr)[0] << std::endl;
    std::cout << "Element in sharedPtr vector: " << (*sharedPtr)[0] << std::endl;
}

void arrayPointerExample() {
    int *arr = new int[3]{1, 2, 3};
    std::cout << "Array elements: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array element addresses: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << "&arr[" << i << "]: " << &arr[i] << " ";
    }
    std::cout << std::endl;
    
    int nRows = 2, nCols = 3;
    int** arr2 = new int*[nRows];
    for (int i = 0; i < nRows; ++i) {
        arr2[i] = new int[nCols];
    }
    
    // Initialize 2D array and display
    int counter = 1;
    for (int i = 0; i < nRows; ++i) {
        for (int j = 0; j < nCols; ++j) {
            arr2[i][j] = counter++;
            std::cout << "arr2[" << i << "][" << j << "] = " << arr2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for (int i = 0; i < nRows; ++i) {
        delete[] arr2[i];
    }
    delete[] arr2;
    delete[] arr;
}

void memoryExample() {
    int arr[2][2] = {1, 2, 3, 4};
    std::cout << "Array elements and their addresses:" << std::endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << "arr[" << i << "][" << j << "]: " << arr[i][j]
                      << ", &arr[" << i << "][" << j << "]: " << &arr[i][j] << std::endl;
        }
    }
}

int main() {
    std::cout << "=== Dynamic Memory Allocation ===" << std::endl;
    dynamicMemoryAllocation();
    std::cout << std::endl;

    std::cout << "=== Vector Pointer Example ===" << std::endl;
    vectorPointerExample();
    std::cout << std::endl;

    std::cout << "=== Smart Pointer Example ===" << std::endl;
    smartPointerExample();
    std::cout << std::endl;

    std::cout << "=== Array Pointer Example ===" << std::endl;
    arrayPointerExample();
    std::cout << std::endl;

    std::cout << "=== Memory Example ===" << std::endl;
    memoryExample();
    std::cout << std::endl;

    return 0;
}
