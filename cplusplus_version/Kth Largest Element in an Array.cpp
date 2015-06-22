class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(0, nums.size()-1, k, nums);
    }

    int findKthLargest(int begin, int end, int k, vector<int>& nums) {
        int pivot = partition(nums, begin, end);
        if(pivot + k == nums.size()) return nums[pivot];
        else if(pivot + k < nums.size()) {
            return findKthLargest(pivot+1, end, k, nums);
        } else {
            return findKthLargest(begin, pivot-1, k, nums);
        }

    }

    int partition(vector<int>& nums, int begin, int end) {
        int key = nums[begin];
        int j = begin;
        for(int i=begin+1; i<=end; i++) {
            if(nums[i] <= key) {
                j++;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[j], nums[begin]);
        return j;
    }
};