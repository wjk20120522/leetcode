/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        stack<TreeNode *> stack1;

        FILO(res, stack1, root);

        return res;
    }

    void FILO(vector<string>& res, stack<TreeNode *> & stack1, TreeNode * root) {
        if(root == NULL) return ;

        stack1.push(root);

        if(root->left == NULL && root->right == NULL) {
            stack<TreeNode *> tmp;
            while (!stack1.empty()) {
                tmp.push(stack1.top());
                stack1.pop();
            }
            string line = "";
            while(!tmp.empty()) {
                line += to_string(tmp.top()->val);
                if(tmp.size() != 1) {
                    line += "->";
                }
                stack1.push(tmp.top());
                tmp.pop();
            }
            res.push_back(line);

            stack1.pop();   // 弹出当前点
        } else if(root->left != NULL) {
            FILO(res, stack1, root->left);
            if(root->right != NULL) {
                FILO(res, stack1, root->right);
            }
            stack1.pop();
        } else {
            FILO(res, stack1, root->right);
            stack1.pop();
        }
    }

};