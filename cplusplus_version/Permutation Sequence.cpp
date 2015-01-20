class Solution {
public:
    string getPermutation(int n, int k) {
         string res;
		 vector<char>nums;
		 for (int i = 1; i <= 9; i++) {
			 nums.push_back(i + '0');
		 }
		 int base[10] = { 1 };
		 for (int i = 1; i < 10; i++) {
			 base[i] = i*base[i - 1];
		 }
		 while (n) {
			 int num = (k - 1) / base[n - 1];
			 res += nums[num];
			 nums.erase(nums.begin()+ num);

			 k = k - num *base[n - 1];
			 n--;
		 }
		 return res;

    }
};