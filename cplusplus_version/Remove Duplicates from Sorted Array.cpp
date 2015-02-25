class Solution {
public:
	int removeDuplicates(int A[], int n) {
		int cur = 0, pre = A[0];
		for (int i = 0; i < n; i++) {
			if (A[i] == pre) continue;
			A[cur++] = A[i];
			pre = A[i];
		}
		return cur;
	}
};