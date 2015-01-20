class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
		 ListNode **p = &head;
		 while (*p && (*p)->next) {
			 ListNode *p1 = *p;
			 ListNode *p2 = (*p)->next;

			 while (p2 && p2->val == p1->val) {
				 p2 = p2->next;
			 }
			 if (p1->next == p2) {
				 p = &(p1->next);          // change p point
			 }
			 else {
				 *p = p2;     // change the p's value
			 }
		 }
		 return head;
	 }
};