class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
      vector<int>res;
		int rows = matrix.size();
		if (rows == 0) return res;
		int cols = matrix[0].size();
		
		int r = 0, c = -1, idx = 0, size = rows*cols;
		res.resize(size);
		while (idx <size) {
			for (int t = 0; idx <size && t < cols; t++) {
				res[idx++] = matrix[r][++c];
			}
			cols--; rows--;
			for (int t = 0; idx <size && t < rows; t++) {
				res[idx++] = matrix[++r][c];
			}
			for (int t = 0; idx <size && t < cols; t++) {
				res[idx++] = (matrix[r][--c]);
			}
			cols--; rows--;
			for (int t = 0; idx <size && t < rows; t++) {
				res[idx++] = matrix[--r][c];
			}
		}
		return res;
    }
};