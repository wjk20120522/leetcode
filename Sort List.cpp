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
    ListNode *sortList(ListNode *head) {
    	ListNode *header =new ListNode();
    	header->next = head;
    	Qsort(header,NULL);
    	
    	return header->next;

    }

    void Qsort(ListNode **head, ListNode **tail) {
    	if(NULL == *head->next || NULL == *head->next->next) {
    		return ;
    	}
    	
    	ListNode * mid = head->next;
    	ListNode * p = head;
    	ListNode * q = mid;
    	ListNode * t = mid->next;
    	int pivot = mid->val;
    	while(NULL != t) {
    		if(t->val < pivot) {
    			p = p->next = t;
    		} else {
    			q = q->next = t;
    		}
    		t = t->next;
    	}
    	p->next = mid; 
    	q->next = NULL;
    	Qsort(head,mid);
    	Qsort(mid,NULL);
    }

};