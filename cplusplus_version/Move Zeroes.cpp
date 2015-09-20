class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cur = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                nums[cur++] = nums[i];
            }
        }
        for(; cur<nums.size(); cur++) {
            nums[cur] = 0;
        }
    }
};