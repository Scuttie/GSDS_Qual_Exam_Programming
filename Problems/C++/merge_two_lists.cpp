#include <iostream>

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Create a dummy node to start the merged list
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    // Traverse both lists and merge them
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes in list1 or list2
    if (list1) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the merged list starting from the next of dummy node
    ListNode* mergedHead = dummy->next;
    delete dummy; // Free the dummy node
    return mergedHead;
}

// Helper function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example 1: list1 = [1, 2, 4], list2 = [1, 3, 4]
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* mergedList = mergeTwoLists(list1, list2);
    std::cout << "Merged List: ";
    printList(mergedList);

    // Clean up memory
    while (mergedList) {
        ListNode* temp = mergedList;
        mergedList = mergedList->next;
        delete temp;
    }

    return 0;
}
