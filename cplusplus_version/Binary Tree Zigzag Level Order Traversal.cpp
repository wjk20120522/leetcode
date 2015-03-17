class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
		if (root == NULL) return res;
		queue<TreeNode *> q,p;
		vector<int>tmp;
		q.push(root);
		while (!q.empty()) {
			tmp.clear();
			while (!q.empty()) {
				TreeNode *cur = q.front(); q.pop();
				tmp.push_back(cur->val);
				if (cur->left) p.push(cur->left);
				if (cur->right) p.push(cur->right);
			}
			res.push_back(tmp);
			q.swap(p);
		}
		for (int i = 1; i < res.size(); i += 2) {
			reverse(res[i].begin(), res[i].end());
		}

		return res;
    }
};