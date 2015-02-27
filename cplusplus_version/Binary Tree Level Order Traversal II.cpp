class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        queue<TreeNode *> q, tmp; 
		TreeNode * cur;
		vector<vector<int> > res;
		vector<int> rol;
		if (root == NULL) return res;
		q.push(root);
		while (!q.empty()) {
			rol.clear();
			while (!q.empty()) {
				cur = q.front();
				q.pop();
				rol.push_back(cur->val);
				if (cur->left) tmp.push(cur->left);
				if (cur->right) tmp.push(cur->right);
			}
			res.push_back(rol);
			q.swap(tmp);
		}
		reverse(res.begin(), res.end());
		return res;
    }
};