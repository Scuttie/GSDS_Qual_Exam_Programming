/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 가상 노드 생성
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        
        // 연결 리스트 순회
        while (current->next != nullptr) {
            if (current->next->val == val) {
                // 노드를 제거
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  // 메모리 해제
            } else {
                current = current->next;
            }
        }
        
        // 실제 헤드 반환
        ListNode* newHead = dummy->next;
        delete dummy;  // 가상 노드 해제
        return newHead;
    }
};
