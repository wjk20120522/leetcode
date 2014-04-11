class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	copy( B, B + n, A + m);
		sort(A, A + m + n);
        /*int i,j;
        for(i=0,j=0; i<m,j<n;) {
            if(A[i])
        }*/
    }
};