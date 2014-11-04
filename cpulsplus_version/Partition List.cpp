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
    ListNode *partition(ListNode *head, int x) {
        if (head == NULL) return NULL;
		ListNode *help = new ListNode(x - 2);
		help->next = head;

		ListNode *cur = help;
		ListNode *newlist = help;

		while (cur != NULL && cur->next != NULL)
		{
			if (cur->next->val < x)
			{
				if (cur == newlist)
				{
					cur = cur->next;
				}
				else
				{
					ListNode *tmp = cur->next;
					cur->next = cur->next->next;
					tmp->next = newlist->next;
					newlist->next = tmp;
				}
				
				newlist = newlist->next;
			}
			else
			{
				cur = cur->next;
			}

		}

		head = help->next;
		delete help;
		return head;
        
    }
};