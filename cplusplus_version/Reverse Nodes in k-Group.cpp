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
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head == NULL || head->next == NULL || k==1) return head;

		ListNode *cur = head;       
		ListNode *pre = head;

		while (true) {
			ListNode* kHead = getKHead(k, cur);
			if (kHead == NULL) {   // concatenate to the cur and return 
				if (cur == pre) return head;    //First time 
				while (cur) {
					pre->next = cur;
					pre = pre->next;
					cur = cur->next;
				}
				return head;
			}
			ListNode *nextnode = kHead->next;
			reverse_list(cur, kHead);
			if (cur == head) {
				head = kHead;
			}
			else  {
				pre->next = kHead;
			}
			pre = cur;
			cur = nextnode;
		}

	}

	void reverse_list(ListNode *cur, ListNode *end) {
		ListNode *next = cur->next;
		ListNode *tmp;
		cur->next = NULL;

		while (next && next != end) {
			tmp = next->next;
			next->next = cur;
			cur = next;
			next = tmp;
		}
		next->next = cur;
		
	}

	ListNode *getKHead(int k, ListNode*cur) {
		int  i;
		for ( i = 0; i < k - 1 && cur; i++) {
			cur = cur->next;
		}
		if (i == k - 1) return cur;
		return NULL;
	}

};