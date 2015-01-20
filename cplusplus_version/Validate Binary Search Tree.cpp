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
    bool isValidBST(TreeNode *root) {
		 int64_t min = INT64_MIN, max = INT64_MAX;
		 return isValidBST(root, min, max);

	 }

	 bool  isValidBST(TreeNode *root, int64_t min, int64_t max) {
		 if (root == NULL) return true;
		 if (root->val <= min || root->val >= max) return false;
		 return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
	 }
};