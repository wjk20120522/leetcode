class Solution {
public:
    int trap(int A[], int n) {
         int beg = 0, end = n - 1;
		 int res = 0;
		 // find the left peak and right peak
		 while (beg < end && A[beg] <= A[beg + 1]) beg++;
		 while (beg < end && A[end] <= A[end - 1]) end--;

		 while (beg < end) {
			 int left = A[beg];
			 int right = A[end];
			 if (A[beg] <= A[end]) {
				 while (beg < end && left >= A[++beg]) {
					 res += left - A[beg];
				 }
			 }
			 else {
				 while (beg < end && right >= A[--end]) {
					 res += right - A[end];
				 }
			 }
		 }
		 return res;
    }
};