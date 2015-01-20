class Solution {
public:
     vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		 vector<int>num;
		 vector< vector<int> > res;
		 sort(candidates.begin(), candidates.end());
		 calculate(candidates, num, res, target,  0);

		 return res;

	 }

	 void calculate(vector<int> &candidates, vector<int>& num, vector< vector<int> >&res, int target, int index) {
		 
		 if (target == 0) {
			 res.push_back(num); return;
		 }
		 if (index == candidates.size() || target - candidates[index] < 0) {    // end of candidates or sums are too big
			 return;
		 }

		 num.push_back(candidates[index]);
		 calculate(candidates, num, res, target - candidates[index], index);
		 num.pop_back();
		 calculate(candidates, num, res, target, index+1);
	 }
};