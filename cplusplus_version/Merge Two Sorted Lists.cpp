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


/*
compare tow listnode together to make code shorter
 */
class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode *res = new ListNode(-1);
		ListNode *tmp = res;
		while (l1 || l2) {
			if (l1 && l2 && l1->val <= l2->val || l2 == NULL) {
				tmp->next = l1;
				l1 = l1->next;
			}
			else if (l1 && l2 && l1->val > l2->val || l1 == NULL) {
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		return res->next;
	}
};