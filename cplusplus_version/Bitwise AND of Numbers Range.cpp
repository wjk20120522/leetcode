class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
       bool begin = false;
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            int tmp = 1 << i;
            if ((tmp & m) == (tmp & n)) { 
                if (tmp &m)
                    res += tmp;
            }
            else return res;
        }
        return res;
    }
};