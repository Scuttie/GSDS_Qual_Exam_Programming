#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>

using namespace std;

// Function to demonstrate list operations
void listExample() {
    // Initialization
    list<string> list1; // Default initialization (empty list)
    list<string> list2 = {"app", "bee", "cat"}; // Direct initialization
    list<string> list3(5, "dog"); // Initialize with specific size and value
    
    cout << "list2: ";
    for (const auto& item : list2) {
        cout << item << " ";
    }
    cout << endl;

    cout << "list3: ";
    for (const auto& item : list3) {
        cout << item << " ";
    }
    cout << endl;

    // Insertion and deletion
    list<int> lst = {1, 2, 3, 4, 5};
    lst.push_back(6);
    lst.push_front(7);
    auto it = lst.begin();
    advance(it, 4);
    lst.insert(it, 8);
    advance(it, -4);
    lst.erase(it);
    lst.pop_back();
    lst.pop_front();

    // Iteration
    cout << "Forward iteration: ";
    for (list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    cout << "Reverse iteration: ";
    for (list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
}

// Function to demonstrate map operations
void mapExample() {
    // Initialization
    map<string, int> map1; // Initialize an empty map
    map<string, int> map2 = {{"Alice", 30}, {"Bob", 25}, {"Charlie", 22}}; // Using initializer list
    
    // Insertion
    map1.insert({"Alice", 30});
    map1["Bob"] = 25;
    map1.insert(make_pair("Charlie", 40));
    map1.insert({"Alice", 35}); // Ignored
    map1["Alice"] = 35; // Update the value
    
    cout << "Map contents after insertion:" << endl;
    for (const auto& pair : map1) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }

    // Search and find
    string name = "Bob";
    if (map1.find(name) != map1.end()) {
        int age = map1[name];
        cout << name << ": " << age << endl;
    }

    auto it = map1.find("Charlie");
    if (it != map1.end()) {
        cout << it->first << ": " << it->second << endl;
    }

    // Deletion
    map1.erase("Bob");
    map1.erase("Frank"); // No error thrown for non-existing key
    
    // Iteration
    cout << "Map contents after deletion:" << endl;
    for (const auto& pair : map1) {
        cout << pair.first << " is " << pair.second << " years old." << endl;
    }
}

// Function to demonstrate set operations
void setExample() {
    // Initialization
    set<int> mySet1; // Initialize an empty set
    set<int> mySet2 = {2, 4, 1, 5, 3}; // Initialize with a list
    
    // Insertion, search, and deletion
    mySet2.insert(6);
    mySet2.erase(4); // By value
    auto it = mySet2.find(2);
    if (it != mySet2.end()) {
        mySet2.erase(it); // By iterator
    }

    // Iteration
    cout << "Set contents: ";
    for (const auto& elem : mySet2) {
        cout << elem << " ";
    }
    cout << endl;

    cout << "Set contents (using iterator): ";
    for (set<int>::iterator it = mySet2.begin(); it != mySet2.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== List Example ===" << endl;
    listExample();
    cout << endl;

    cout << "=== Map Example ===" << endl;
    mapExample();
    cout << endl;

    cout << "=== Set Example ===" << endl;
    setExample();
    cout << endl;

    return 0;
}
