/*
iterative
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        while ( root ) {
            if ( root->left ) {
                TreeNode *ptr = root->left;
                while ( ptr->right ) ptr = ptr->right;
                ptr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};


/*
another method, dfs
 */
class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        TreeNode *leftmost = NULL;
        if (root->left) {
            flatten(root->left);
            leftmost = root->left;
            while (leftmost->right)  {
                leftmost = leftmost->right;
            }
        }
        if (root->right) {
            flatten(root->right);
        }
        if (leftmost) {
            leftmost->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};