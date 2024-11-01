/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if (!root) return 0; // 루트가 null이면 깊이는 0

        int max_depth = 0;
        for (Node* child : root->children) {  // 자식 노드 각각에 대해
            max_depth = max(max_depth, maxDepth(child)); // 자식 노드의 최대 깊이 갱신
        }
        
        return max_depth + 1;  // 현재 깊이 + 1 (루트 노드 포함)
    }
};
