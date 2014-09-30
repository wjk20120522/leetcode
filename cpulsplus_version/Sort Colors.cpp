class Solution {
public:
    void sortColors(int A[], int n) {
        int red=0, white=0, blue=0;
        for(int i=0; i<n; i++)
        {
            if(A[i] == 0) red++;
            if(A[i] == 1) white++;
            if(A[i] == 2) blue++;
        }
        int pos = 0;
        while(red-- >0)
        {
            A[pos++] = 0;
        }
        while(white-- >0)
        {
            A[pos++] = 1;
        }
        while(blue-- >0)
        {
            A[pos++] = 2;
        }
        
        
    }
};