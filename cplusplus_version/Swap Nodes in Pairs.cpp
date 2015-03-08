class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
         ListNode *cur = head, *second, *pre = NULL;
		 while (cur && cur->next) {
			 if (cur == head) {
				 head = cur->next;
			 }
			 //be careful of the sequence
			 second = cur->next;
			 cur->next = second->next;
			 second->next = cur;
			 if (pre) {
				 pre->next = second;				
			 }
			 pre = cur;			
			 cur = cur->next;
		 }
		 return head;
    }
};