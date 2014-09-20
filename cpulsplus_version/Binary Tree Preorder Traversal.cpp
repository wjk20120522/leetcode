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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> v;
		stack<TreeNode *> nodes;
	
		TreeNode *tmp;
		if (root != NULL)
		{
			nodes.push(root);
			while (!nodes.empty())
			{
				tmp = nodes.top();
				nodes.pop();
				v.push_back(tmp->val);
				if (tmp->right != NULL)
				{
					nodes.push(tmp->right);
				}
				if (tmp->left != NULL)
				{
					nodes.push(tmp->left);
				}
			}
		}
		return v;
    }
};