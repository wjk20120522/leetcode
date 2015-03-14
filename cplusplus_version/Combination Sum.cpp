class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > res;
		vector<int>tmp;
		
		sort(candidates.begin(), candidates.end());
		getcombination(res, tmp, candidates, target, 0);
		return res;
	}

	void getcombination(vector<vector<int> >&res, vector<int>&tmp, vector<int>&candidates, int target, int idx) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		for (int i = idx; i < candidates.size(); i++) {
			tmp.push_back(candidates[i]);
			getcombination(res, tmp, candidates, target - candidates[i], i);
			tmp.pop_back();
		}
	}
};