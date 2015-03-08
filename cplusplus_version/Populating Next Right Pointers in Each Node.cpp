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
        TreeLinkNode *cur = root, *child, *tmp;
        bool firstchild;
        while (cur) {
            firstchild = false;
            child = cur->left;
            while (cur) {
                if (cur->left) {
                    if (firstchild) {
                        tmp->next = cur->left;
                        tmp = cur->left;
                    }
                    else {
                        firstchild = true;
                        tmp = child = cur->left;
                    }
                }
                if (cur->right) {
                    if (firstchild) {
                        tmp->next = cur->right;
                        tmp = cur->right;
                    }
                    else {
                        firstchild = true;
                        tmp = child = cur->right;
                    }
                }
                cur = cur->next;
            }
            cur = child;
        }
    }
};