class Solution {
public:
    int addDigits(int num) {
        while(num >= 10) {
            int tmp = num;
            num = 0;
            while(tmp) {
                num += tmp%10;
                tmp /= 10;
            }
        }
        return num;
    }
};