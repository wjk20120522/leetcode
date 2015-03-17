class Solution {
public:
	int findMin(vector<int> &num) {
		int begin = 0, end = num.size() - 1, mid;
		while (begin < end) {
			mid = (begin + end) / 2;
			if (num[mid] < num[end]) {
				end = mid;
			}
			else {
				begin = mid + 1;
			}
		}
		return num[begin];
	}
};