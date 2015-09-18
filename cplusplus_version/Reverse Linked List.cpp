/*
recursive method
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode * end = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return end;
    }
};


/*
iterative method
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head, *nex;
        while(cur) {
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};