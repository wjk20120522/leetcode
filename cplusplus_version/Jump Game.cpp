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


/*
short code
 */
class Solution {
public:
    bool canJump(int A[], int n) {
        int maxlength = 0;
		for (int i = 0; i < n; i++) {
			if (i>maxlength) return false;
			maxlength = max(maxlength, i + A[i]);
		}
		return true;
    }
};