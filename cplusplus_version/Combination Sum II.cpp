 class Solution {
 public:
	 vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		 sort(num.begin(), num.end());
		 vector< vector<int> > res;
		 vector<int> v;
		 backtrack(num, target, 0, res, v);
		 return res;
	 }

	 void backtrack(vector<int>&num, int target, int index, vector< vector<int> > &res, vector<int>&v) {
		 if (target == 0) {
			 res.push_back(v); return;
		 }
		 if (index == num.size() || target < 0) return;

		 for (int i = index; i < num.size(); i++){
			 v.push_back(num[i]);
			 backtrack(num, target-num[i], i +1,  res, v);
			 v.pop_back();
			 while (i < num.size()-1 && num[i] == num[i + 1]) i++;
		 }
	 }
 };