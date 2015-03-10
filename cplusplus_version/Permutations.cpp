class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		  vector<vector<int>> v;
		  get_permutation(v, num, 0);
		  return v;
	  }

	void get_permutation(vector<vector<int>> &v, vector<int>&num, int level) {
		if (level == num.size() - 1) {
			v.push_back(num);
			return;
		}
		for (int i = level; i<num.size(); i++) {
			swap(num[i], num[level]);
			get_permutation(v, num, level + 1);
			swap(num[i], num[level]);
		}
	}
};