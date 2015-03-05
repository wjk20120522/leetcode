/*
DFS, easy to understand
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
		return DFS(root, 0);
	}

	int DFS(TreeNode*root, int sum) {
		if (root == NULL) return 0;

		//current value of node
		sum = sum * 10 + root->val;

		int leftVal = DFS(root->left, sum);
		int rightVal = DFS(root->right, sum);
		if (leftVal + rightVal == 0) {	// current node is leaf
			return sum;
		}
		return leftVal + rightVal;
	}
};


/*
make the above code shorter
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
		return DFS(root, 0);
	}

	int DFS(TreeNode*root, int sum) {
		if (root == NULL) return 0;
		//current value of node
		sum = sum * 10 + root->val;
		
		int curVal = DFS(root->left, sum) + DFS(root->right, sum);
		return curVal == 0 ? sum : curVal;
	}
};


/*
BFS, change the value of tree
 */
class Solution {
public:
    int sumNumbers(TreeNode *root) {
         queue<TreeNode *>q;
		 TreeNode *tmp;
		 int res = 0;
		 if (root == NULL) return 0;
		 q.push(root);
		 while (!q.empty())
		 {
			 tmp = q.front();
			 q.pop();
			 if (tmp->left)
			 {
				 tmp->left->val += tmp->val * 10;
				 q.push(tmp->left);
			 }
			 if (tmp->right)
			 {
				 tmp->right->val += tmp->val * 10;
				 q.push(tmp->right);
			 }
			 if (tmp->left == NULL && tmp->right == NULL)
			 {
				 res += tmp->val;
			 }
		 }
		 return res;
    }
};