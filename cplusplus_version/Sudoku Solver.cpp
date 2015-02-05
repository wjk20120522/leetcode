class Solution {
public:
	void solveSudoku(vector<vector<char> > &board) {
		solve(board, 0);
	}

	bool solve(vector<vector<char>>& board, int num) {
		if (num >= 81) return true;
		int row = num / 9;
		int col = num % 9;

		if (board[row][col] != '.') {
			return solve(board, num + 1);
		}
		else {
			for (char i = '1'; i <= '9'; i++) {
				if (isRowValid(board, row, i) && isColValid(board, col, i) && isBoardValid(board, row, col, i)) {
					board[row][col] = i;
					if (solve(board, num + 1) == true)
						return true;
				}
			}
			board[row][col] = '.';
		}
		return false;
	}
	
	bool isRowValid(vector<vector<char> >&board, int row, char num) {
		for (int i = 0; i < 9; i++) {
			if (board[row][i] == num) return false;
		}
		return true;
	}

	bool isColValid(vector<vector<char> >&board, int col, char num) {
		for (int i = 0; i < 9; i++) {
			if (board[i][col] == num) return false;
		}
		return true;
	}

	bool isBoardValid(vector<vector<char> >&board, int row, int col, char num) {
		int blockRow = row / 3;
		int blockCol = col / 3;
		for (int i = blockRow * 3; i < blockRow * 3 + 3; i++) {
			for (int j = blockCol * 3; j < blockCol * 3 + 3; j++) {
				if (board[i][j] == num) return false;
			}
		}
		return true;


	}


};