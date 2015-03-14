class Solution {
public:
	vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > res(n, vector<int>(n, 0));
		int rows = n, cols = n;
		int r = 0, c = -1;
		int idx = 0;
		while (idx < n*n) {
			for (int i = 0; idx < n*n && i < cols; i++) {
				res[r][++c] = ++idx;
			}
			rows--; cols--;
			for (int i = 0; idx < n*n && i < rows; i++) {
				res[++r][c] = ++idx;
			}
			for (int i = 0; idx < n*n && i < cols; i++) {
				res[r][--c] = ++idx;
			}
			rows--; cols--;
			for (int i = 0; idx < n*n && i < rows; i++) {
				res[--r][c] = ++idx;
			}
		}
		return res;
	}
};