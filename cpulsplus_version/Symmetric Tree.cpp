/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
typedef pair<TreeNode*, TreeNode*>  nodepair;
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if(root == NULL) return true;
        /*      the iterator method
                              
        queue<nodepair>q;
        q.push(make_pair(root->left, root->right));
        
        while(q.size())
        {
            nodepair np = q.front(); q.pop();
            
            if(np.first && np.second)
            {
                if(np.first->val == np.second->val)
                {
                    q.push(make_pair(np.first->left, np.second->right) );
                    q.push(make_pair(np.first->right, np.second->left) );
                }
                else
                {
                    return false;
                }
            }
            else if(np.first || np.second)
            {
                return false;
            }
        }
        return true;
        
        */
        if(theSame(root->left, root->right)) return true;
        return false;
        
    }
    
    bool theSame(TreeNode *left, TreeNode *right)
    {
        if(left == NULL && right == NULL) return true;
        else if(left == NULL || right == NULL) return false;
        
        if(left->val != right->val ) return false;
        return theSame(left->left, right->right) && theSame(left->right, right->left);
    }
    
   
};