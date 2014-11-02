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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector< vector<int> > res;
		if (root == NULL) return res;
		stack<TreeNode *> one, two;
		bool first = true;
		one.push(root);
		vector<int> tmp;
		TreeNode *cur;
		while (1)
		{
			tmp.clear();
			if (first)
			{
				if (one.empty()) return res;
				while (!one.empty())
				{
					cur = one.top();
					tmp.push_back(cur->val);
					if (cur->left) two.push(cur->left);
					if (cur->right) two.push(cur->right);
					one.pop();
				}
				
				first = false;
			}
			else
			{
				if (two.empty()) return res;
				while (!two.empty())
				{
					cur = two.top();
					tmp.push_back(cur->val);
					if (cur->right) one.push(cur->right);
					if (cur->left) one.push(cur->left);
					two.pop();
				}
				first = true;
			}
			res.push_back(tmp);
		}
		// should not be here
		return res;

    }
};