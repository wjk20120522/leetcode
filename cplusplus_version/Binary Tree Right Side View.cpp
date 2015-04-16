class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if(root == NULL) return res;
        queue<TreeNode *> q,p;
        TreeNode *tmp;
        q.push(root);
        while(true) {
            // indicate whether this level is the leaf level
            bool same_level = true;
            res.push_back(q.back()->val);
            while (!q.empty()) {
                if (q.front()->left) {
                    p.push(q.front()->left);
                    same_level = false;
                }
                if (q.front()->right) {
                    p.push(q.front()->right);
                    same_level = false;
                }
                q.pop();
            }
            q.swap(p);
            if (same_level) return res;
        }
    }
};