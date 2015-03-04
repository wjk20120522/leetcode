class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		vector<int>tmp;
		int begin,end, size  = num.size();
		for (int i = 0; i < size - 2; i++) {
			tmp.clear();
			// for each first i, find begin and end
			begin = i + 1, end = size - 1;
			while (begin < end) {
				if (num[begin] + num[end] + num[i] == 0) {
					tmp.push_back(num[i]); tmp.push_back(num[begin]);
					tmp.push_back(num[end]);
					res.push_back(tmp);
					tmp.clear();
					while (begin <end && num[begin] == num[begin + 1]) begin++;
					while (begin <end && num[end] == num[end - 1]) end--;
					begin++; end--;

				}
				else if (num[begin] + num[end] + num[i] > 0) {
					end--;
				}
				else {
					begin++;
				}
			}
			// remove the same first one
			while (i < size - 2 && num[i] == num[i + 1]) i++;
		}
		return res;

	}
};