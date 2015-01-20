/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(head == NULL) return NULL;
        int nums = get_nums(head);
        if(nums == n)   // just need to delete the head
        {
            return head->next;
        }
        ListNode *pre = head;
        for(int i=0; i<nums-n-1; i++)
        {
            pre = pre->next;
        }
    
        pre->next = pre->next->next;
        return head;
    }
    
    int get_nums(ListNode *head)
    {
        int count = 0;
        while(head != NULL)
        {
            count ++;
            head = head->next;
        }
        return count;
    }
};