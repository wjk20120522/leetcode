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
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		
		return merge(begin(lists), end(lists));

	}
	ListNode *merge(vector<ListNode *>::iterator begin, vector<ListNode *>::iterator end) {
		if (begin == end) return nullptr;
		if (next(begin) == end) return *begin;

		auto mid = begin + (end - begin) / 2;
		return mergeList(  merge(begin, mid), merge(mid, end) );

	}
	
	ListNode *mergeList(ListNode *one, ListNode *two) {
		if (one == nullptr) return two;
		if (two == nullptr) return one;

		ListNode *cur = new ListNode(11);
		ListNode *head = cur;

		while (one && two) {
			if (one->val < two->val) {
				cur->next = one;
				one = one->next;
			}
			else {
				cur->next = two;
				two = two->next;

			}
			cur = cur->next;
		}
		if (one) {
			cur->next = one;
		}
		if (two) {
			cur->next = two;
		}
		return head->next;

	}


};
