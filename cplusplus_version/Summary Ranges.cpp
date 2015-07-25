class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0) return res;
        int first = nums[0];
        int second = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == nums[i-1] + 1) {
                second = nums[i];
                continue;
            }
            if(first == second) {
                res.push_back(to_string(first));
            } else {
                res.push_back(to_string(first) + "->" + to_string(second));
            }
            first = second = nums[i];
        }
        if(first == second) {
            res.push_back(to_string(first));
        } else {
            res.push_back(to_string(first) + "->" + to_string(second));
        }
        return res;
    }
};