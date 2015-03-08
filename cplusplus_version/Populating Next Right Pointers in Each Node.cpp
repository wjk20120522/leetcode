class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *child;
        while (cur && cur->left) {
            // set the next child node
            child = cur->left;
            while (cur) {
                // set the left child's next to right child
                cur->left->next = cur->right;
                // set the right child's next
                if (cur->next) {
                    cur->right->next = cur->next->left;
                }
                cur = cur->next;
            }
            // set the current to next level's first node
            cur = child;
        }
    }
};


/*
II's code can be used here,two
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *cur = root, *child, *pre;
        while (cur) {
            child = pre = NULL;
            while (cur) {
                if (cur->left) {
                    if (pre) pre = pre->next = cur->left;
                    else pre = child = cur->left;
                }
                if (cur->right) {
                    if (pre) pre = pre->next = cur->right;
                    else pre = child = cur->right;
                }
                cur = cur->next;
            }
            cur = child;
        }
    }
};