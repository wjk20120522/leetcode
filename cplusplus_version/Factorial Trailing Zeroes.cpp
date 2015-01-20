class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        int64_t fives = 5;
        while(n >= fives) {
            count += n/fives;
            fives *= 5;
        }
        return count;
    }
};