class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return ;
		 ListNode *p = head, *q = head;
		//split the linklist into two halves
		 while (q && q->next && q->next->next) {
			 p = p->next; 
			 q = q->next->next;
		 }
		 // reverse the second half
		 ListNode *mid = p->next;
		 p->next = NULL;  // p = head;
		 ListNode *next = mid;
		 if (mid->next) {
			 next = mid->next;
			 mid->next = NULL;
			 while (next) {
			     ListNode * nexttmp = next->next;   // for next point of 'next'
				 next->next = mid;
				 mid = next;
				 next = nexttmp;
			 }
		 }
		
		 // merge the two lists
		 ListNode *cur = head;
		 while (mid) {
			 ListNode *tmp = mid; 
			 mid = mid->next;
			 tmp->next = cur->next;
			 cur->next = tmp;
			 cur = cur->next->next;
		 }
		// return head;
    }
};