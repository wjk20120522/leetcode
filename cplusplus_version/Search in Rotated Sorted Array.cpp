class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0, end = (int)nums.size()-1, mid;
        while(begin <= end) {
            mid = begin + (end-begin)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) {
                if(nums[mid] < nums[begin] && nums[end] < target ) {    // mid is in small part
                    end = mid - 1;
                } else {
                    begin = mid + 1;
                }

            } else {
                if(nums[mid] > nums[end] && nums[begin] > target) { // in big part
                    begin = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};