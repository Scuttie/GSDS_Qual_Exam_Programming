#include <iostream>

// Node class
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// LinkedList class
template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        clear();
    }

    // Add element to the end of the list
    void append(T data) {
        Node<T>* newNode = new Node<T>(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Clear the list
    void clear() {
        Node<T>* current = head;
        while (current) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    // Print the list
    void print() const {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Overload the + operator to concatenate two lists
    LinkedList<T> operator+(const LinkedList<T>& other) {
        LinkedList<T> result;
        Node<T>* temp = head;
        
        // Append elements from the first list
        while (temp) {
            result.append(temp->data);
            temp = temp->next;
        }
        
        // Append elements from the second list
        temp = other.head;
        while (temp) {
            result.append(temp->data);
            temp = temp->next;
        }

        return result;
    }
};

int main() {
    LinkedList<int> list1;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    
    LinkedList<int> list2;
    list2.append(4);
    list2.append(5);
    
    LinkedList<int> combinedList = list1 + list2;
    
    std::cout << "List 1: ";
    list1.print();
    std::cout << "List 2: ";
    list2.print();
    std::cout << "Combined List: ";
    combinedList.print();
    
    return 0;
}
