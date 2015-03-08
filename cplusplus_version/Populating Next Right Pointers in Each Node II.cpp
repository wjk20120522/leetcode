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