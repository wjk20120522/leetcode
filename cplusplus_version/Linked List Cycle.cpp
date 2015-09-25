class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode *fast = head->next->next;
        ListNode *slow = head;
        while(fast != slow) {
            if(fast == NULL || fast->next == NULL) return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
    }
};