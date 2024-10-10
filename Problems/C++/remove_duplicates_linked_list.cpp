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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;  // 빈 리스트 처리
        
        ListNode* current = head;
        
        // 리스트 순회
        while (current->next != nullptr) {
            if (current->val == current->next->val) {
                // 중복된 노드 제거
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;  // 메모리 해제
            } else {
                current = current->next;
            }
        }
        
        return head;  // 수정된 리스트의 헤드 반환
    }
};
