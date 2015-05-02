class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *res = new ListNode(111);
        res->next = head;
        ListNode * pre = res, *cur = res->next;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
                delete cur;
                cur = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        
        return res->next;
    }
};