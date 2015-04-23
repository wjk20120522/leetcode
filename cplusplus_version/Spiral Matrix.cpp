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


/* another method similar with "jianzhi offer" */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        rows = (int)matrix.size();
        if(rows == 0) return res;
        cols = (int)matrix[0].size();
        printMatrixClockwisely(matrix, res);
        return res;
    }

    void printMatrixClockwisely(vector<vector<int> >&matrix, vector<int>&res) {
        if(rows <=0 || cols <=0) return;
        // print rounds
        int rounds = min((rows+1)/2, (cols+1)/2);
        for(int i=0; i<rounds; i++) {
            printRound(matrix, i, res);
        }
    }

    void printRound(vector<vector<int> >&m, int round, vector<int>&res) {
        int endX = cols-1-round, endY = rows-1-round;
        //from top left to top right
        for(int i=round; i<=endX; i++) {
            res.push_back(m[round][i]);
        }
        //from top right to bottom right
        for(int i=round+1; i<=endY; i++) {
            res.push_back(m[i][endX]);
        }
        //from bottom right to bottom left
        for(int i=endX-1;  round < endX && round < endY && i>= round; i--) {
            res.push_back(m[endY][i]);
        }
        //from bottom left to top left
        for(int i=endY-1; round < endX && round < endY-1 && i>round; i--) {
            res.push_back(m[i][round]);
        }
    }

private:
    int rows;
    int cols;
};