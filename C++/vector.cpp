#include <iostream>
#include <vector>
#include <algorithm> // for std::find
#include <numeric>   // for std::accumulate

void printVector(const std::vector<int>& vec, const std::string& name) {
    std::cout << name << ": ";
    for (int v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void vectorInitialization() {
    // Direct list initialization
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    printVector(vec1, "vec1 (direct list initialization)");

    // From an array
    int arr[] = {6, 7, 8, 9, 10};
    std::vector<int> vec2(std::begin(arr), std::end(arr));
    printVector(vec2, "vec2 (from an array)");

    // With a specific size and value
    std::vector<int> vec3(5, 100);
    printVector(vec3, "vec3 (with a specific size and value)");
}

void vectorInsertion() {
    std::vector<int> vec;
    // Adding elements using push_back
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    printVector(vec, "vec after insertion");

    // Printing the second element
    std::cout << "Second element after insertion: " << vec.at(1) << std::endl;
}

void vectorDeletion() {
    std::vector<int> vec = {10, 20, 30, 40, 50};
    printVector(vec, "vec before deletion");

    // Delete the last element
    vec.pop_back();
    printVector(vec, "vec after pop_back()");

    // Delete the element at the third position
    vec.erase(vec.begin() + 2);
    printVector(vec, "vec after erase at third position");
}

void vectorIteration() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printVector(vec, "vec before iteration");

    // Iterate using range-based for loop
    std::cout << "Iterating using range-based for loop:" << std::endl;
    for (int val : vec) {
        std::cout << val << std::endl;
    }

    // Iterate using iterator
    std::cout << "Iterating using an iterator:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

void vectorFindExample() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printVector(vec, "vec for find example");

    // Find the first occurrence of 3 in the vector
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "Found 3 at index: " << std::distance(vec.begin(), it) << std::endl;
    } else {
        std::cout << "Element 3 not found." << std::endl;
    }
}

void vectorAccumulateExample() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    printVector(vec, "vec for accumulate example");

    // Sum all elements in the vector
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "Sum of elements: " << sum << std::endl;
}

int main() {
    std::cout << "=== Vector Initialization ===" << std::endl;
    vectorInitialization();
    std::cout << std::endl;

    std::cout << "=== Vector Insertion ===" << std::endl;
    vectorInsertion();
    std::cout << std::endl;

    std::cout << "=== Vector Deletion ===" << std::endl;
    vectorDeletion();
    std::cout << std::endl;

    std::cout << "=== Vector Iteration ===" << std::endl;
    vectorIteration();
    std::cout << std::endl;

    std::cout << "=== Vector Find Example ===" << std::endl;
    vectorFindExample();
    std::cout << std::endl;

    std::cout << "=== Vector Accumulate Example ===" << std::endl;
    vectorAccumulateExample();
    std::cout << std::endl;

    return 0;
}
