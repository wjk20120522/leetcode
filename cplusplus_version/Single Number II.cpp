#include <iostream>
using namespace std;

class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        int bits[32] = {0};

     	for(int j=0; j<32;j++) {
     		for(int i=0; i<n; i++) {
     			bits[j] += (A[i] >> j) & 1;
     		}
     		res |= ((bits[j] % 3) << j);
        }
        return res;
    }
};


/*
similar but use less space
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0,tmp;
        for (int i = 0; i < 32; i++) {
            tmp = 0;
            for (int j = 0; j < n; j++) {
                tmp += (A[j] >> i) & 1;
            }
            res |= (tmp % 3) << i;
        }
        return res;
    }
};