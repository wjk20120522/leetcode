 class Solution {
 public:
	 void nextPermutation(vector<int> &num) {
		 int n = num.size(), i, j;
		 for (i = n - 2; i >= 0; i--)
			if (num[i]<num[i + 1]) break;
		 if (i >= 0){
			 for (j = n - 1; j>i; j--)
				if (num[j]>num[i]) break;
			 swap(num[i], num[j]);
		 }
		 reverse(num.begin() + i + 1, num.end());
	 }
 };