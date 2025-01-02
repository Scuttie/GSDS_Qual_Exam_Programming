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
    ListNode* middleNode(ListNode* head) {
        // 빠른 포인터와 느린 포인터를 사용하여 중간 노드 찾기
        ListNode* slow = head;
        ListNode* fast = head;
        
        // 빠른 포인터는 두 칸씩, 느린 포인터는 한 칸씩 이동
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // 느린 포인터가 중간 노드를 가리키게 됨
        return slow;
    }
};
