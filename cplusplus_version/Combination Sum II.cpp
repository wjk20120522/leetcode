class Solution {
public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		vector<vector<int> > res;
		vector<int>tmp;
		sort(num.begin(), num.end());
		getcombination(res, tmp, num, target, 0);
		return res;
	}

	void getcombination(vector<vector<int> >&res, vector<int>&tmp, vector<int>&num, int target, int idx) {
		if (target < 0) return;
		if (target == 0) {
			res.push_back(tmp);
			return;
		}
		for (int i = idx; i < num.size(); i++) {
			tmp.push_back(num[i]);
			getcombination(res, tmp, num, target - num[i], i + 1);
			tmp.pop_back();
			while (i < num.size() - 1 && num[i] == num[i + 1]) i++;
		}
	}
};