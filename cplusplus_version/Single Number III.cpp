class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res ;
        if(nums.size() == 0) return res;
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum ^= nums[i];
        }

        int one = 0, two = 0,  i;
        for( i=0; i<32; i++) {
            if( (1<<i)&sum ) {


                for(int j=0; j<nums.size(); j++) {
                    if( (1<<i) & nums[j]) {
                        one ^= nums[j];
                    } else {
                        two ^= nums[j];
                    }
                }
                break;
            }
        }
        res.push_back(one);
        res.push_back(two);
        return res;

    }
};