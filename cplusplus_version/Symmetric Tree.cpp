/*
recursive method
 */
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) return true;
        return twoSameTree(root->left, root->right);
    }

    bool twoSameTree(TreeNode *leftTree, TreeNode *rightTree) {
        if (leftTree == NULL || rightTree == NULL) return leftTree == rightTree;
        if (leftTree->val != rightTree->val) return false;
        return twoSameTree(leftTree->left, rightTree->right) && twoSameTree(leftTree->right, rightTree->left);
    }
};

/*
the iterator method
 */
typedef pair<TreeNode*, TreeNode*>  nodepair;
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        queue<nodepair>q;
        q.push(make_pair(root->left, root->right));

        while (!q.empty()) {
            nodepair np = q.front(); q.pop();

            if (np.first && np.second) {
                if (np.first->val == np.second->val) {
                    q.push(make_pair(np.first->left, np.second->right));
                    q.push(make_pair(np.first->right, np.second->left));
                }
                else {
                    return false;
                }
             } 
             else if (np.first || np.second) {
                return false;
            }
        }
        return true;
    }
};