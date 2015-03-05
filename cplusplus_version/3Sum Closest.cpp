class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
		int dis = INT_MAX, begin, end, size = num.size(), res, tmp;
		for (int i = 0; i < size - 2; i++) {
			begin = i + 1, end = size - 1;
			while (begin < end) {
				tmp = num[i] + num[begin] + num[end];
				if (abs(tmp- target) < dis) {
					res = tmp;
					dis = abs(tmp - target);
				}
				if (tmp - target < 0) {
					begin++;
				}
				else {
					end--;
				}
			}
			while (i < size - 1 && num[i] == num[i + 1]) i++;
		}
		return res;
    }
};