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
    bool hasPathSum(TreeNode *root, int sum) {
    	// no node to reach
        if (root == NULL) return false;
        // if it is the root node, judge it
		if (root->left == NULL && root->right == NULL) return root->val == sum;
		// see if left child and right child can sum up to "sum"
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};

/*  iterative method, postorder traversal
	bool hasPathSum(TreeNode *root, int sum) {
        stack<TreeNode *> s;
        TreeNode *pre = NULL, *cur = root;
        int SUM = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.push(cur);
                SUM += cur->val;
                cur = cur->left;
            }
            cur = s.top();
            if (cur->left == NULL && cur->right == NULL && SUM == sum) {
                return true;
            }
            if (cur->right && pre != cur->right) {
                cur = cur->right;
            } else {
                pre = cur;
                s.pop();
                SUM -= cur->val;
                cur = NULL;
            }
        }
        return false;
    }
 */

/*  iterative method, preorder traversal
	bool hasPathSum(TreeNode *root, int sum) {
        stack<TreeNode*> st; stack<int> stval;
        TreeNode *node{root};
        int val = 0;
        while (!st.empty() || node != NULL) {
            if (node != NULL) {
                val += node->val;
                st.push(node);
                stval.push(val);
                node = node->left;
            } else {
                node = st.top(); st.pop();
                val = stval.top(); stval.pop();
                if (val == sum && node->left == NULL && node->right == NULL)
                    return true;
                node = node->right;
            }
        }
        return false;
	}
 */