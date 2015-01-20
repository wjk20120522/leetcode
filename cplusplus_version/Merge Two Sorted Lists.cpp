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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode * head = new ListNode(0);
		ListNode *tmp = head;
		ListNode *first = l1, *second = l2;
		while (first != NULL && second != NULL)
		{
			if (first->val < second->val)
			{
				tmp->next = first;
				first = first->next;
			}
			else
			{
				tmp->next = second;
				second = second->next;
			}
			tmp = tmp->next;
		}
		while (first != NULL)
		{
			tmp->next = first;
			tmp = tmp->next;
			first = first->next;
		}
		while (second != NULL)
		{
			tmp->next = second;
			tmp = tmp->next;
			second = second->next;
		}
		return head->next;
        
    }
};