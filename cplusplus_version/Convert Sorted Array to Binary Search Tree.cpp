class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0) return NULL;
		return constructBST(num, 0, num.size()-1);
    }

	TreeNode *constructBST(vector<int>&num, int begin, int end) {
		if (begin > end) return NULL;
	
		int mid = (begin + end) / 2;
		TreeNode *res = new TreeNode(num[mid]);
		res->left = constructBST(num, begin, mid - 1);
		res->right = constructBST(num, mid + 1, end);
		return res;
	}
};