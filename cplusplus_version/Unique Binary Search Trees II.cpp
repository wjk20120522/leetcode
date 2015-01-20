class Solution {
public:
     vector<TreeNode *> generateTrees(int n) {
		 return generateTrees(1, n);
	 }
	 
	 vector<TreeNode *> generateTrees(int begin, int end) {
		 vector<TreeNode *>res;
		 
		 if (begin > end) {
			 res.push_back(nullptr);
			 return res;
		 }
		 for (int i = begin; i <= end; i++)
		 {
			 
			 vector<TreeNode *>left = generateTrees(begin, i - 1);
			 vector<TreeNode *>right = generateTrees(i+1, end);

			 for (auto le : left) { 
				 for (auto ri : right) {
					 TreeNode *root = new TreeNode(i);
					 root->left = le;
					 root->right = ri;
					 res.push_back(root);
				 }
			 }

		 }
		 return res;
	 }
};