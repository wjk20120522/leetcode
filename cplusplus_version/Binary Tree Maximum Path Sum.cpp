 class Solution {
 public:
	 int maxPathSum(TreeNode *root) {
		 if (root == NULL) return 0;

		 int res = INT_MIN;
		 getMax(root, res);
		 return res;

	 }

	 int getMax(TreeNode *root, int& res) {
		 if (root == NULL) return 0;

		 int leftMax = getMax(root->left, res);

		 int rightMax = getMax(root->right, res);

		 //culcate the max sum with this node
		 int curMax = leftMax + rightMax > leftMax ? leftMax + rightMax : leftMax;
		 curMax = curMax > rightMax ? curMax : rightMax;
		 curMax = curMax > 0 ? curMax : 0;

		 if (curMax + root->val > res) {
			 res = curMax + root->val;
		 }

		 //return max sum with this node and one side child
		 int childMax = leftMax > rightMax ? leftMax : rightMax;
		 int max = root->val;
		 if (childMax > 0) {
			 max += childMax;
		 }
		 return max;

	 }
 };