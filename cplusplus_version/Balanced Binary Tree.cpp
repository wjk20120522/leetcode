class Solution {
public:
    bool isBalanced(TreeNode *root) {
		 if (root == NULL) return true;
		 int len_left = getLength(root->left);
		 int len_right = getLength(root->right);
		 return (abs(len_left - len_right) <= 1 &&isBalanced(root->left) && isBalanced(root->right) );
	 }

	 int getLength(TreeNode *root) {
		 if (root == NULL) return 0;
		 return 1 + max(getLength(root->left), getLength(root->right));
	 }
};