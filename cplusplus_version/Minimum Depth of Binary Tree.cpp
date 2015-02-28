class Solution {
public:
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		//if one of its child is NULL, we should not return min of two
		if (leftDepth*rightDepth == 0) return 1 + max(leftDepth, rightDepth);
		return 1 + min(leftDepth, rightDepth);
	}
};