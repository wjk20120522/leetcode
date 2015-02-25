/*
swap the element which is not "elem" to front, one direction
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int cur = 0;
        for(int i=0; i<n; i++) {
            if(A[i] != elem) {
                A[cur++] = A[i];
            }
        }
        return cur;
    }
};


/*
swap the back element which is "elem" with front, two direction
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int begin = 0, end = n - 1;
        int sameItem = 0;
        while (begin <= end) {
            if (A[begin] == elem) {
                swap(A[begin], A[end]);
                end--;
                sameItem++;
            }
            else {
                begin++;
            }
        }
        return n - sameItem;
    }
};