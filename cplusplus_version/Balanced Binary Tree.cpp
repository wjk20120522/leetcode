/*
top down solution, O(NlgN)
 */
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


/*
bottom up solution, O(N)
 */
class Solution {
public:
    bool isBalanced(TreeNode *root) {
		return dfs(root) != -1;
	}

	int dfs(TreeNode *root) {
		if (root == NULL) return 0;
		int left_len = dfs(root->left);
		if (left_len == -1) return -1;
		int right_len = dfs(root->right);
		if (right_len == -1) return -1;

		if (abs(left_len - right_len) > 1) return -1;
		return 1 + max(left_len, right_len);
	}
};