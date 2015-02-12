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

/*
can be used here and II
 */

/*
if (root == NULL) return;
        TreeLinkNode *pre = root, *cur, *curChild = NULL, *nextChilid = NULL;
        while (pre)
        {
            cur = pre;
            bool first = true;
            curChild = nextChilid = NULL;
            while (cur)
            {
                if (cur->left) {
                    if (first) {
                        first = false;
                        pre = cur->left;
                    }
                    if (curChild == NULL) {
                        curChild = cur->left;
                    }
                    else {
                        nextChilid = cur->left;
                    }
                }
                if (curChild && nextChilid) {
                    curChild->next = nextChilid;
                    curChild = nextChilid;
                    nextChilid = NULL;
                }

                if (cur->right) {
                    if (first) {
                        first = false;
                        pre = cur->right;
                    }
                    if (curChild == NULL) {
                        curChild = cur->right;
                    }
                    else {
                        nextChilid = cur->right;
                    }
                }
                if (curChild && nextChilid) {
                    curChild->next = nextChilid;
                    curChild = nextChilid;
                    nextChilid = NULL;
                }
                cur = cur->next;
            }
            if (first) {
                return;
            }
        }
 */