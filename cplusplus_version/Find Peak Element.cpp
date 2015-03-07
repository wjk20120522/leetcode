class Solution {
public:
    int findPeakElement(const vector<int> &num) {
		 return findPeak(num, 0, num.size() - 1);
	 }

	 int findPeak(const vector<int> &num, int begin, int end) {
		 if (begin == end) { // only one left
			 return begin;
		 }
		 else if (end - begin == 1) {
			 return num[begin] > num[end] ? begin : end;
		 }
		 else {
			 int m = (begin + end) / 2;
			 if (num[m - 1] < num[m] && num[m] < num[m + 1]) {
				 return findPeak(num, m + 1, end);
			 }
			 else if (num[m - 1] > num[m] && num[m] > num[m + 1])
				 return findPeak(num, begin, m - 1);
			 else if (num[m - 1] <num[m] && num[m] > num[m + 1]) {
				 return m;                              // find the ans
			 }
			 else {
				 return findPeak(num, m + 1, end);    // alternative
			 }
		 }
	 }
	 
};


/*
iterative method
 */
class Solution {
public:
	int findPeakElement(const vector<int> &num) {
		int len = num.size();
		int start = 0, end = len - 1, mid = (start + end) / 2;
		if (len == 1) return 0;
		if (len == 2) return num[0] > num[1] ? 0 : 1;
		while (true)
		{
			if (mid == 0) {
				return num[0] > num[1] ? 0 : 1;
			}
			if (mid == len - 1) {
				return num[len - 1] > num[len - 2] ? len - 1 : len - 2;
			}
			if (num[mid] > num[mid - 1] && num[mid] > num[mid + 1]) return mid;
			else if (num[mid] < num[mid - 1] && num[mid + 1] < num[mid]) {
				end = mid - 1;
			}
			else {
				start = mid + 1;
			}
			mid = (start + end) / 2;
		}
	}
};