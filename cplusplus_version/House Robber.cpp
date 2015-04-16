class Solution {
public:
    int rob(vector<int> &num) {
        int houses = (int)num.size();
        if(houses == 0) return 0;
        if(houses == 1) return num[0];
        if(houses == 2) return num[0] > num[1] ? num[0] : num[1];
        if(houses == 3) return num[0]+num[2] > num[1] ? num[0] + num[2] : num[1];

        //don't forget this
        num[2] += num[0];

        for(int i=3; i<houses; i++) {
            num[i] += (num[i-2] > num[i-3] ? num[i-2] : num[i-3]);
        }
        return max(num[houses-1], num[houses-2]);
    }
};