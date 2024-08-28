#include <stdio.h>
#include <stdlib.h>
#include "llpal.h"

int main() {
    struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    n1->val = 1; n1->next = n2;
    n2->val = 2; n2->next = n3;
    n3->val = 2; n3->next = n4;
    n4->val = 1; n4->next = NULL;
    printf("Test case 1: %s\n", isPalindrome(n1) ? "true" : "false");

    struct ListNode* m1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* m3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    m1->val = 1; m1->next = m2;
    m2->val = 2; m2->next = m3;
    m3->val = 3; m3->next = NULL;
    printf("Test case 2: %s\n", isPalindrome(m1) ? "true" : "false");

    struct ListNode* o1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    o1->val = 1; o1->next = NULL;
    printf("Test case 3: %s\n", isPalindrome(o1) ? "true" : "false");

    printf("Test case 4: %s\n", isPalindrome(NULL) ? "true" : "false");

    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(m1);
    free(m2);
    free(m3);
    free(o1);

    return 0;
}