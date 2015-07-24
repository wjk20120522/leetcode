class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;

        ListNode *fast = head, *slow = head;
        while(fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;

        slow->next = NULL;  // 前面一半链表

        fast = inverse(fast);   // 后面一半链表反转

        slow = head;

        while(fast != NULL && slow != NULL) {
            if(fast->val != slow->val) return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

    ListNode* inverse(ListNode *head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *pre = head;
        ListNode *cur = head->next;
        pre->next = NULL;
        ListNode *next;

        while(cur != NULL) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};