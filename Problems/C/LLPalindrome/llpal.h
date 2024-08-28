#ifndef LLPAL_H
#define LLPAL_H

#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head);
bool isPalindrome(struct ListNode* head);

#endif 