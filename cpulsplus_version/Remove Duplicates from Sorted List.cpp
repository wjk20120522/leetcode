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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
		ListNode *cur = head;
		ListNode *nex = head->next;

		while (cur != NULL && cur->next != NULL)
		{
			nex = cur->next;
			if (nex->val == cur->val )
			{
				//需要注意末尾重复的情况
				while ( nex != NULL && nex->val == cur->val)
				{
					nex = nex->next;
				}
				cur->next = nex;
				cur = nex;
			}
			else
			{
				cur = cur->next;				
			}
		}
		return head;
    }
};