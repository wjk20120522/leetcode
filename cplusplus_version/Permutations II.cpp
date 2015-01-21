 class Solution {
 public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
		 vector<vector<int>> v;
		 if (num.size() == 0) return v;	
		 sort(num.begin(), num.end());
		 v.push_back(num);  int i, j;
		 while (true) {
			 for (i = num.size()-1; i > 0; i--) {
				 if (num[i] > num[i - 1]) {
					 break;
				 }
			 }
			 if (i == 0) {   // big to small
				 break;
			 }
			 for (j = num.size() - 1; j >= i; j--) {
				 if (num[j] > num[i - 1]) {
					 break;
				 }
			 }
			 swap(num[i - 1], num[j]);
			 reverse(num,  i, num.size()-1);
			 v.push_back(num);
		 }
		 return v;
	 }


	 void reverse(vector<int>&num, int begin, int end) {
		 while (begin < end) {
			 swap(num[begin++], num[end--]);
		 }
	 }

 };