class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int begin = 0, end = nums.size()-1, mid;
        while(begin <= end) {
            mid = begin + (end-begin)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) end --;
            else begin++;
        }
        return begin > end ? begin : end;
    }
};