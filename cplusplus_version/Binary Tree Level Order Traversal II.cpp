/*
iterative method
 */
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


/*
recursive method
 */
class Solution {
public:
	vector<vector<int> > levelOrderBottom(TreeNode *root) {
		DFS(root, 0);
		reverse(res.begin(), res.end());
		return res;
	}

	void DFS(TreeNode *root, int level) {
		if (root == NULL) return;
		if (level == res.size()) {
			res.push_back(vector<int>());
		}
		res[level].push_back(root->val);

		DFS(root->left, level + 1);
		DFS(root->right, level + 1);
	}
private:
	vector<vector<int> > res;
};