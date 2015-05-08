/*
recursive method
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode * nex = head->next;
        ListNode *res = reverseList(nex);
        head->next = NULL;
        nex->next = head;
        return res;
    }
};


/*
iterative method
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
};