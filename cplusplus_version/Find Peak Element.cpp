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