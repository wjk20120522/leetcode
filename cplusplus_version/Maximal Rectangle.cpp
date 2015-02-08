class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		int maxArea = 0;

		int row = matrix.size();
		if (row == 0) return 0;
		int col = matrix[0].size();

		//vector<int>preLeft(col), preRight(col), preHeight(col);
		vector<int>curLeft(col), curRight(col,col), curHeight(col);

		for (int i = 0; i < row; i++) {

			int cur_left = 0, cur_right = col;
			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1') {
					curHeight[j] ++;
				}
				else {
					curHeight[j] = 0;
				}
			}

			for (int j = 0; j < col; j++) {
				if (matrix[i][j] == '1') {
					curLeft[j] = max(curLeft[j], cur_left);	
				}
				else {
					curLeft[j] = 0; cur_left = j + 1;
				}
			}

			for (int j = col - 1; j >= 0; j--) {
				if (matrix[i][j] == '1') {
					curRight[j] = min(curRight[j], cur_right);
				}
				else {
					curRight[j] = col; cur_right = j;
				}
			}

			for (int i = 0; i < col; i++) {
				int curArea = (curRight[i] - curLeft[i])*curHeight[i];
				maxArea = maxArea > curArea ? maxArea : curArea;
			}

		}
				
		return maxArea;


	}
};