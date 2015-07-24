class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == NULL || node->next == NULL) return;
        node->val = node->next->val;
        node->next = node->next->next;
    }
};