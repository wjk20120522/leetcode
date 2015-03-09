class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		if (n <= 1) return;
		int tmp;
		for (int i = 0; i < n / 2; i++) {   	// row, be careful about the last
			for (int j = i; j < n -1- i; j++) {		//col, be careful about the last
				tmp = matrix[i][j];
				matrix[i][j] = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = tmp;
			}
		}
    }
};