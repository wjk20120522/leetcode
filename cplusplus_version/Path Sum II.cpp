/*
dfs
 */
class Solution {
public:
	vector<vector<int> > pathSum(TreeNode *root, int sum) {
		vector<vector<int> > res;
		vector<int>tmp;
		if (root == NULL) return res;
		int count = 0;
		getpathSum(root, res, tmp, count, sum);
		return res;
	}

	void getpathSum(TreeNode *root, vector<vector<int> >&res, vector<int>&tmp, int& count, int sum) {
		if (root == NULL) return;
		tmp.push_back(root->val);
		count += root->val;
		if (root->left == NULL && root->right == NULL) {
			if (count == sum)
				res.push_back(tmp);
		}
		getpathSum(root->left, res, tmp, count, sum);
		getpathSum(root->right, res, tmp, count, sum);
		tmp.pop_back();
		count -= root->val;
	}
};


/*
iterative method
 */
struct Visit {
	  bool left, right;
	  Visit() :left(false), right(false) {}
	  void set(bool l, bool r) {
		  left = l; right = r;
	  }
 };

 class Solution {
 public:
	 vector<vector<int> > pathSum(TreeNode *root, int sum) {
		 
		 vector< vector<int> > res;
		 vector<int> tmp;
		 Visit v;
		 if (root == NULL) return res;
		 stack<TreeNode *> s;  //store the root to current node
		 stack<Visit> visit;   //if the top node is visited both side

		 s.push(root);
		 visit.push(v);

		 tmp.push_back(root->val);
		 while (!s.empty()) {
			 TreeNode * cur = s.top();
			 v = visit.top();   visit.pop();
			 
			 if (cur->left == NULL && cur->right == NULL) {
				 s.pop();
				 
				 int all = accumulate(tmp.begin(), tmp.end(), 0);
				 if (all == sum) {
					 res.push_back(tmp);
				 }
				 tmp.pop_back();
				 
			 } else if (cur->left && !v.left) {
				 
				s.push(cur->left);
				tmp.push_back(cur->left->val);
				//push current node visit
				v.left = true;
				visit.push(v);
				//push left child node visit
				v.set(false, false);
				visit.push(v);
				
			 } else if (cur->right && !v.right) {
				
				s.push(cur->right);
				tmp.push_back(cur->right->val);

				v.right = true;
				visit.push(v);

				v.set(false, false);
				visit.push(v);	 
				
			 }
			 else {
				 s.pop();
				 tmp.pop_back();
			 }
		 }
		 return res;

	 }
 };