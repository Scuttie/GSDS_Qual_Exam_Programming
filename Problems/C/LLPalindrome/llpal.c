#include "llpal.h"
#include <stdlib.h>

// linked list reverse 시키는 helper 함수
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL; 
    struct ListNode* curr = head;

    while (curr != NULL) {
        struct ListNode* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    // 리스트 중간기점 찾기 (헌칸씩 움직이는 ptr, 두칸씩 움직이는 ptr 활용)
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 중간 기준으로 뒷부분을 뒤집음
    struct ListNode* secondHalfStart = reverseList(slow);
    struct ListNode* firstHalfStart = head;
    
    // 앞부분과 뒤집은 뒷부분 비교
    bool result = true;
    struct ListNode* p1 = firstHalfStart;
    struct ListNode* p2 = secondHalfStart;

    while (result && p2 != NULL) {
        if (p1->val != p2->val) {
            result = false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    return result;
}