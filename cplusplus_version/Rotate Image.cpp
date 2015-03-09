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


/*
different method
 */
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
		if (n <= 1) return;
		// exchange half up with half down
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n; j++) {
				swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
		// exchange left down with right up
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				swap(matrix[i][j], matrix[j][i]);
			}
		}
    }
};


/*
similar with above
 */
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = matrix.size();
		if (n <= 1) return;
		// exchange half left with half right
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n/2; j++) {
				swap(matrix[i][j], matrix[i][n-1-j]);
			}
		}
		// exchange left up with right down
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n-1-i; j++) {
				swap(matrix[i][j], matrix[n-1-j][n-1-i]);
			}
		}
    }
};