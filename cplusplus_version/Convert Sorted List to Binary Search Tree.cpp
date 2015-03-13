class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
		TreeNode * res =  sortedListToBST(head, NULL);
		return res;
	}
	TreeNode * sortedListToBST(ListNode *head, ListNode *tail) {   // tail means exclude, guard
		if (head == tail) return NULL;   // no node
		if (head->next == tail) {        // only one node
			return new TreeNode(head->val);
		}
		ListNode *mid = head, *fast = head;
		while (fast != tail && fast->next != tail) {    // important 
			mid = mid->next;
			fast = fast->next->next;
		}
		TreeNode *root = new TreeNode(mid->val);
		root->left = sortedListToBST(head, mid);
		root->right = sortedListToBST(mid->next, tail);
		return root;
	}
};


/*
broke the original listnode, not use tail guard
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		ListNode *mid = head, *fast = head, *prev = mid;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			prev = mid;
			mid = mid->next;
		}
		TreeNode *node = new TreeNode(mid->val);
		if (prev != mid) {
			prev->next = NULL;
			node->left = sortedListToBST(head);
		}
		node->right = sortedListToBST(mid->next);
		return node;
    }
};


/*
similar like above, if only one child it will be left
 */
class Solution {
public:
	TreeNode *sortedListToBST(ListNode *head) {
		if (head == NULL) return NULL;
		if (head->next == NULL) return new TreeNode(head->val);
		ListNode *mid = head, *fast = head, *prev = mid;
		while (fast && fast->next) {	// different with above method
			fast = fast->next->next;
			prev = mid;
			mid = mid->next;
		}
		TreeNode *node = new TreeNode(mid->val);
		prev->next = NULL;
		node->left = sortedListToBST(head);
		node->right = sortedListToBST(mid->next);
		return node;
	}
};