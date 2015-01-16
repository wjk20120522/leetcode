/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		// convert BST to linear array use inorder traversal
		while (!stack.empty() || root != NULL) {
			if (root) {
				stack.push_back(root);
				root = root->left;
			}
			else {
				root = stack.back();
				res.push_back(root->val);
				stack.pop_back();
				
				root = root->right;
			
			}	
		}

		pos = 0;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		return pos < res.size();
	//	return !s.empty();
	}

	/** @return the next smallest number */
	int next() {
		return res[pos++];
	}
private:
	vector<int> res;
	vector<TreeNode *> stack;
	int pos;
};