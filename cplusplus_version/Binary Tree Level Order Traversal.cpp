/*
use another queue to save the next level child
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        queue<TreeNode *> q, tmp;
		vector<vector<int> > res;
		vector<int> rol;
		if (root == NULL) return res;
		q.push(root);
		while (!q.empty()) {
			rol.clear();
			while (!q.empty()) {
				TreeNode * cur = q.front();
				q.pop();
				rol.push_back(cur->val);
				if (cur->left) tmp.push(cur->left);
				if (cur->right) tmp.push(cur->right);
			}
			res.push_back(rol);
			q.swap(tmp);
		}
		return res;
    }
};