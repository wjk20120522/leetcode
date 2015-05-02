class Solution {
public:
    int countPrimes(int n) {
        if(n <=2) return 0;
        bool *prime = new bool[n];
        memset(prime, 1, sizeof(bool)*n);

        for(int i=2; i<n; i++) {
            for(int j=2*i; j<n; j+=i) {
                prime[j] = false;
            }
        }

        int res = 0;
        for(int i=2; i<n; i++) {
            if(prime[i]) res++;
        }
        return res;
    }
};