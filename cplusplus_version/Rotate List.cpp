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
    ListNode *rotateRight(ListNode *head, int k) {
		 int len = getLength(head);   if(len == 0) return head;
		 k = k%len;
		 if ( len == 1 || k==0) return head;   // special case
		 int dis = len - k;
		 ListNode *prev = head, *cur = head->next;
		 // find the point where to split the linklist
		 for (int i = 1; i < dis; i++) {
			 prev = cur;
			 cur = cur->next;
		 }
		 prev->next = NULL;
          // the first linklist append to the second  
		 ListNode *newHead = cur;
		 while (cur->next) {
			 cur = cur->next;
		 }
		 while (head) {
			 cur->next = head;
			 cur = cur->next; 
			 head = head->next;
		 }
		 return newHead;

	 }
    
	 int getLength(ListNode *head) {
		 int res = 0;
		 while (head) {
			 head = head->next;
			 res++;
		 }
		 return res;
	 }
};