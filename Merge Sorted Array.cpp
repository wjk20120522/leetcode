class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
    	copy( B, B + n, A + m);
		sort(A, A + m + n);
		/** another concrete method
		 *********
        //put the num from the tail of array A
        int index = m+n-1;
        for(; index>=0; index--) {
        	if(n<=0) {
        		return ;
        	} else if(m<=0) {
        		A[index] = B[--n];
        	} else if(A[m-1] < B[n-1]) {
        		A[index] = B[--n];
        	} else {
        		A[index] = A[--m];
        	}

        }
        ***********
        **/
    }
};