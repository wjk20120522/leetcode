/*
concrete method
 */
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int index = m + n - 1;
        while (m || n) {
            if (m && n && A[m - 1] >= B[n - 1] || n==0) {
                A[index--] = A[m-1];
                m = m ? m - 1 : 0;
            }
            else {
                A[index--] = B[n-1];
                n = n ? n - 1 : 0;
            }   
        }
    }
};


/*
use STL, sort of cheating
 */
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	// use STL function
    	copy( B, B + n, A + m);
		sort(A, A + m + n);
    }
};