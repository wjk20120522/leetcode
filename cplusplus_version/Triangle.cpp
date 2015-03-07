/*
bottom up, do not change original triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> res = triangle[triangle.size()-1];
		for (int row = triangle.size() - 2; row >= 0; row--) {
			for (int col = 0; col <= row; col++) {
				res[col] = min(res[col], res[col + 1]) + triangle[row][col];
				
			}
		}
		return res[0];
    }
};

/*
bottom up, change original triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        for (int row = triangle.size() - 2; row >= 0; row--) {
			for (int col = 0; col <= row; col++) {
				triangle[row][col] += min(triangle[row + 1][col], triangle[row + 1][col + 1]);
			}
		}
		return triangle[0][0];
    }
};


/*
top-down, change original triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if (triangle.size() == 0) return 0;
		int left, right, up, minval;
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				left = up = INT_MAX;
				if (j - 1 >= 0) left = triangle[i - 1][j - 1];
				if (j < triangle[i - 1].size()) up = triangle[i - 1][j];
				minval = min(left, up);
				triangle[i][j] += minval;
			}
		}
		int minTotal = INT_MAX;
		for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
			minTotal = min(minTotal, triangle[triangle.size() - 1][i]);
		}
		return minTotal;
    }

};