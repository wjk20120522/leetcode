class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return INT_MAX;
        else if(dividend == 0) return 0;
        bool neg = false;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ) neg = true;

        long long dend = dividend;
        long long sor = divisor;
        dend = abs(dend);
        sor = abs(sor);
        long long res = 0;
        long long int bits = 31;
        long long curSum = 0;
        while(true) {
            if( (sor << bits) + curSum  <= dend ) {
                res |= ((long long)1 << bits);
                if((sor << bits) + curSum  == dend) {
                    break;
                }
                curSum += (sor << bits);
            }
            bits --;
            if(bits < 0) break;
        }
        if(!neg && res-INT_MAX-1 == 0) return INT_MAX;
        if(neg) return -res;
        return res;
    }
};  