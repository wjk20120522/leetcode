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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        if(n <=0) return NULL;
        
        TreeNode *root = getChildren(preorder, 0, n-1, inorder, 0, n-1);
        return root;
    }
    
    TreeNode *getChildren( vector<int>&preorder, int pre_begin, int pre_end, vector<int>&inorder, int in_begin, int in_end)
    {
        int val = preorder[pre_begin];
        TreeNode *root = new TreeNode(val);
        int left_num =0, right_num=0;
        
        for(int i= in_begin; i<=in_end; i++)
        {
            if(inorder[i] == val)
            {
                left_num = i-in_begin;
                right_num = in_end -i;
            }
        }
        
        if(left_num > 0)
        {
            root->left = getChildren(preorder, pre_begin+1, pre_begin+left_num, inorder, in_begin, in_begin+left_num-1);
        }
        if(right_num > 0)
        {
            root->right = getChildren(preorder, pre_end-right_num+1, pre_end, inorder, in_end-right_num+1, in_end);
        }
        return root;
        
    }
    
};