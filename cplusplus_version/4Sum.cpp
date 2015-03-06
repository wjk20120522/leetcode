class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        sort(num.begin(), num.end());
		 vector<vector<int> >res;
		 vector<int>tmp;
		 int len = num.size(), begin, end, sum;
		 for (int i = 0; i < len - 3; i++) {
			 for (int j = i + 1; j < len - 2; j++) {
				 begin = j + 1; end = len - 1;
				 while (begin < end) {
					 sum = num[i] + num[j] + num[begin] + num[end];
					 if (sum == target) {
						 tmp.clear();
						 tmp.push_back(num[i]); tmp.push_back(num[j]);
						 tmp.push_back(num[begin]); tmp.push_back(num[end]);
						 res.push_back(tmp);
						 while (begin < end && num[begin] == num[begin + 1]) begin++;
						 while (begin < end && num[end] == num[end - 1]) end--;
						 begin++; end--;
					 }
					 else if (sum < target) {
						 begin++;
					 }
					 else {
						 end--;
					 }
				 }	//end while
				 while (j < len - 3 && num[j] == num[j + 1]) j++;
			 }
			 while (i < len - 4 && num[i] == num[i + 1]) i++;
		 }
		 return res;
    }
};