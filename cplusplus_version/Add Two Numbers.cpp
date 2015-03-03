class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if (l1 == NULL || l2 == NULL) return l1 == NULL ? l2 : l1;
		 ListNode *res = new ListNode(-1), *cur = res;
		 int carry = 0, num1, num2;
		 while (l1 || l2 || carry) {
			 num1 = num2 = 0;
			 if (l1) num1 = l1->val;
			 if (l2) num2 = l2->val;
			 cur->next = new ListNode((num1 + num2 + carry) % 10);
			 cur = cur->next;
			 carry = (num1 + num2 + carry) / 10;
			 l1 = l1 ? l1->next : NULL;
			 l2 = l2 ? l2->next : NULL;
		 }
		 return res->next;
    }
};