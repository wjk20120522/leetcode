class Solution {
public:
	bool canJump(int A[], int n) {
		int idx = 0, maxfar, maxidx;
		while (true) {
			maxfar = 0, maxidx = idx;
			for (int i = idx; i<n && i <= idx + A[idx]; i++) {
				if (i + A[i] > maxfar) {
					maxidx = i;
					maxfar = i + A[i];
				}
			}
			if (maxfar >= n - 1) return true;
			if (maxidx == idx) return false;
			idx = maxidx;
		}
	}
};