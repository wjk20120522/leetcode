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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> v;
		stack<TreeNode *> nodes;
		stack<bool>tag;

		TreeNode *tmp;
		if (root != NULL)
		{
			nodes.push(root);
			tag.push(false);
			while (!nodes.empty())
			{
				tmp = nodes.top();

				if (tmp->left != NULL && tag.top() == false)
				{
					nodes.push(tmp->left);
					tag.pop();
					tag.push(true);
				}
				else 
				{
					v.push_back(tmp->val);
					nodes.pop();
					if (tmp->left != NULL)
					{
						tag.pop();
					}
					if (tmp->right != NULL)
					{
						nodes.push(tmp->right);
					}
					
				}
			
			}
		}
		return v;
		
    }
};