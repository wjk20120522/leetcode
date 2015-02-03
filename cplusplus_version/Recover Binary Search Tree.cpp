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
	void recoverTree(TreeNode *root) {
		first = second = NULL;
		prev = new TreeNode(INT_MIN);

		inOrderTravel(root);
        int tmp = first->val;
		first->val = second->val;
		second->val = tmp;
	}

	void inOrderTravel(TreeNode *root) {
		if (root == NULL) return;

		inOrderTravel(root->left);
		if (first == NULL && prev->val >= root->val) {
			first = prev;
		} 
		if(first != NULL && prev->val >= root->val) {
			second = root;
			
		}
		prev = root;

		inOrderTravel(root->right);



	}
private:
	TreeNode *first, *second, *prev;
};