class Solution {
public:
	int minDepth(TreeNode *root) {
		if (root == NULL) return 0;
		int leftDepth = minDepth(root->left);
		int rightDepth = minDepth(root->right);
		//note: one of its child is NULL
		if (leftDepth*rightDepth == 0) return 1 + max(leftDepth, rightDepth);
		return 1 + min(leftDepth, rightDepth);
	}
};