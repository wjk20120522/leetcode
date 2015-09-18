class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *quick = head, *slow = head;
        for(int i=0; i<n; i++) {
            quick = quick->next;
        }
        if(quick == NULL) return head->next;  //remove the head;
        while(quick->next) {
            quick = quick->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};