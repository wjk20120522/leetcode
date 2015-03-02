class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		pos = -1;
		while (root) {
			v.push_back(root);
			root = root->left;
			pos++;
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return pos != -1;
	}

	/** @return the next smallest number */
	int next() {
		TreeNode *cur = v.back();
		v.pop_back();
		if (cur->right) {
			TreeNode * child = cur->right;
			v.push_back(child);
			pos++;
			while (child->left) {
				v.push_back(child->left);
				pos++;
				child = child->left;
			}
		}
		pos--;
		return cur->val;

	}
private:
	vector<TreeNode *> v;
	int pos;
};