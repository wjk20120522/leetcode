class Solution {
 public:
	 void rotate(int nums[], int n, int k) {
	     k = k%n;
	     if(k==0) return;
		 swapArea(nums, 0, n - 1);
		 swapArea(nums, 0, k - 1);
		 swapArea(nums, k, n - 1);
	 }

 private:
	 void swapArea(int nums[], int begin, int end) {
		 while (begin < end) {
			 swap(nums[begin], nums[end]);
			 begin++, end--;
		 }
	 }
 };