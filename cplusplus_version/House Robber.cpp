class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        for(int i=0; i<nums.size(); i++) {
            if(i == 2) {
                nums[i] += nums[i-2];
            } else if(i > 2) {
                nums[i] += max(nums[i-2], nums[i-3]);
            }
            if(nums[i] > res) {
                res = nums[i];
            }
        }
        return res;
    }
};