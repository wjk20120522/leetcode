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
    ListNode *insertionSortList(ListNode *head) {
    	// if there is only one node or null, return immediately
        if(head==NULL || head->next == NULL) return head;
		// insert each node from second node to the front part
		ListNode * current = head->next;
		head->next = NULL;
		while(current) {
			ListNode * temp = head;
			ListNode * prev = NULL;
			// to keep the next node of current node to be inserted, important!!!
			ListNode * next = current->next;
			while(temp){
				if(current->val > temp->val) {
					// do not find the right place to insert
					prev = temp;
					temp = temp->next;
				} else {
					// find the right place to insert
					if(prev == NULL){
						// if it is the head node
						current->next = head;
						head = current;
					} else {
						current->next = temp;
						prev->next = current;
					}
					break;
				}
			}
			// if it is the end node
			if(!temp) {
				prev->next = current;
				current->next = NULL;
			}
			current = next;
		}
		return head;
    }
};