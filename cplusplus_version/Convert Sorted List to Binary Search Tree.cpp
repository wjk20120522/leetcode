/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     TreeNode *sortedListToBST(ListNode *head) {
		 TreeNode * res =  sortedListToBST(head, NULL);
		 return res;
	 }
	 TreeNode * sortedListToBST(ListNode *head, ListNode *tail) {   // tail means exclude, guard
		 if (head == tail) return NULL;   // no node

		 if (head->next == tail) {        // only one node
			 TreeNode *node = new TreeNode(head->val);
			 return node;
		 }
		 ListNode *mid = head, *tmp = head;
		 while (tmp != tail && tmp->next != tail) {    // important 
			 mid = mid->next;
			 tmp = tmp->next->next;
		 }
		 TreeNode *root = new TreeNode(mid->val);
		 root->left = sortedListToBST(head, mid);
		 root->right = sortedListToBST(mid->next, tail);
		 return root;

	 }
};