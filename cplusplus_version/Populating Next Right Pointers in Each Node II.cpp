class Solution {
public:
	void connect(TreeLinkNode *root) {
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
	}
};