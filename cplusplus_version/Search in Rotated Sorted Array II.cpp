class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0, end = (int)nums.size()-1, mid;
        while(begin <= end) {
            mid = begin + (end-begin)/2;
            if(nums[mid] == target) return true;
            if(nums[begin] < nums[mid]) {
                if(nums[mid] > target && nums[begin] <= target) {   // mid in big part
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }
            } else if(nums[begin] > nums[mid]) {    //mid in small part
                if(nums[mid] < target && nums[end] >= target) {
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                begin ++;
            }
        }
        return false;
    }
};