class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int first = 1, second = 2;
        int res;
        for(int i=3; i<=n; i++)
        {
            res = first + second;
            first = second;
            second = res;
        }
        return res;
    }
};