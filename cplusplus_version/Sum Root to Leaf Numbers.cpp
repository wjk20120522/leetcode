class Solution {
public:
    int sumNumbers(TreeNode *root) {
         queue<TreeNode *>q;
		 TreeNode *tmp;
		 int res = 0;
		 if (root == NULL) return 0;
		 q.push(root);
		 while (!q.empty())
		 {
			 tmp = q.front();
			 q.pop();
			 if (tmp->left)
			 {
				 tmp->left->val += tmp->val * 10;
				 q.push(tmp->left);
			 }
			 if (tmp->right)
			 {
				 tmp->right->val += tmp->val * 10;
				 q.push(tmp->right);
			 }
			 if (tmp->left == NULL && tmp->right == NULL)
			 {
				 res += tmp->val;
			 }
		 }
		 return res;
    }
};