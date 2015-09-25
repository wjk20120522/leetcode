class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *tmp = q.top();  q.pop();
            res.push_back(tmp->val);
            if(tmp->right) q.push(tmp->right);
            if(tmp->left) q.push(tmp->left);
        }
        return res;
    }
};


/**
Recursive solution, trival
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        preorderTraversal(root, res);
        return res;
    }
    
private:
    void preorderTraversal(TreeNode* root, vector<int>&res) {
        res.push_back(root->val);
        if(root->left) preorderTraversal(root->left, res);
        if(root->right) preorderTraversal(root->right, res);
    }   
};

