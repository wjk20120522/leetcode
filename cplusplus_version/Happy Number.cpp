class Solution {
public:
    bool isHappy(int n) {
        int tmp;
        set<int>s;
        while(n) {
            if(n==1) return true;
            if(s.find(n) != s.end()) return false;  //cycle
            s.insert(n);
            tmp = n, n=0;
            while(tmp) {
                n += (tmp%10)*(tmp%10);
                tmp /= 10;
            }
        }
        return false;
    }
};