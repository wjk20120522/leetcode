#include <iostream>
using namespace std;

class Solution 
{
public:
    int singleNumber(int A[], int n) 
    {
        n--;
		for(; n>=1; n--)
        {
        	A[n-1] ^= A[n];
        }
        return A[0];
    }
};


/*
also pretty ok, without using extra memory means O(1)
 */
class Solution {
public:
    int singleNumber(int A[], int n) {
        int res = 0;
        for(int i=0; i<n; i++)
        {
            res ^= A[i];
        }
        return res;
    }
};


/*
hard to understand but smart
 */
public int singleNumber(int[] A, int n) {
    int ones = 0, twos = 0;
    for(int i = 0; i < n; i++){
        ones = (ones ^ A[i]) & ~twos;
        twos = (twos ^ A[i]) & ~ones;
    }
    return ones;
}