/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // very beautiful code from the forum
        //https://oj.leetcode.com/discuss/7327/a-simple-accepted-solution
        if(root == NULL) return;
        TreeLinkNode *pre=root, *cur;
        while(pre->left)
        {
            cur = pre;
            while(cur)
            {
                cur->left->next = cur->right;
                if(cur->next) { cur->right->next = cur->next->left; }
                cur = cur->next;
            }
            pre = pre->left;
        }
    
    }
};