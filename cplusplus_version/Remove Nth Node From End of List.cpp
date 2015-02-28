/*
two pass
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return NULL;
        int nums = get_nums(head);
        if(nums == n) {
            return head->next;
        }

        ListNode *pre = head;
        for(int i=0; i<nums-n-1; i++) {
            pre = pre->next;
        }
    
        pre->next = pre->next->next;
        return head;
    }
    
    int get_nums(ListNode *head) {
        int count = 0;
        while(head != NULL) {
            count ++;
            head = head->next;
        }
        return count;
    }
};


/*
one pass
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *first = head, *second = head, *pre = first;
        for (int i = 0; i < n; i++) {
            second = second->next;
        }
        if (second == NULL) {
            return first->next;
        }
        while (second) {            
            pre = first;
            first = first->next;
            second = second->next;
        }
        pre->next = first->next;
        return head;
    }
};