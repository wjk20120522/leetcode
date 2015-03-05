  struct Pos {
	  int x;
	  int y;
	  Pos(int i, int j) {
		  x = i; y = j;
	  }
	  void set(int r, int c) {
		  x = r; y = c;
	  }

  };

  class Solution {
  public:

	  void solve(vector<vector<char>> &board) {
		  if (board.size() == 0) return;
		  row = board.size(); col = board[0].size();

		  Pos p(0, 0);
		  queue<Pos>q;
		  // 从外面找不符合的O, 标记为N, 然后将N往里面扩散
		  for (int i = 0; i < col; i++) {
			  if (board[0][i] == 'O') {
				  setPointToN(0, i, p, q, board);
			  }
		  }
		  for (int i = 0; i < col; i++) {
			  if (board[row - 1][i] == 'O') {
				  setPointToN(row-1, i, p, q, board);
			  }
		  }
		  for (int i = 0; i < row; i++) {
			  if (board[i][0] == 'O') {
				  setPointToN(i, 0, p, q, board);
			  }
		  }
		  for (int i = 0; i < row; i++) {
			  if (board[i][col-1] == 'O') {
				  setPointToN(i, col-1, p, q, board);  
			  }
		  }
		  //从外面开始进入里面
		  while (!q.empty()) {
			  p = q.front();  q.pop();
			  int posx = p.x, posy = p.y;
			  // 观察上下左右是否有O,如有标记为N并压入队列
			  if (posx>0 && board[posx - 1][posy] == 'O') {
				  setPointToN(posx - 1, posy, p, q, board);
			  } 
			  if (posx < row - 1 && board[posx + 1][posy] == 'O') {
				  setPointToN(posx + 1, posy, p, q, board);
			  } 
			  if (posy > 0 && board[posx][posy - 1] == 'O') {
				  setPointToN(posx, posy - 1, p, q, board);
			  }
			  if (posy < col - 1 && board[posx][posy + 1] == 'O') {
				  setPointToN(posx, posy + 1, p, q, board);
			  }  
		  }
		  // set N to O ,  O to X
		  for (int i = 0; i < row; i++) {
			  for (int j = 0; j < col; j++) {
				  if (board[i][j] == 'N')
					  board[i][j] = 'O';
				  else if (board[i][j] == 'O')
					  board[i][j] = 'X';
			  }
		  }
			   
	  }

	  void setPointToN(int x, int y, Pos p, queue<Pos> &q, vector<vector<char>> &board) {
		  p.set(x, y); q.push(p); board[x][y] = 'N';
	  }

  private:
	  int row;
	  int col;
  };


/*
same idea, not use Point, use queue to avoid stackoverflow
 */
class Solution {
public:

	void solve(vector<vector<char>> &board) {
		rows = board.size();
		if (rows == 0) return;
		cols = board[0].size();
		//set the four edge 'O' to 'M', so 'M' can't change
		
		// first row and last row
		for (int i = 0; i < cols; i++) {
			if (board[0][i] == 'O') {
				changeToM(board, 0, i);
			}
			if (board[rows - 1][i] == 'O') {
				changeToM(board, rows - 1, i);
			}
		}
		//first column and last column
		for (int i = 0; i < rows; i++) {
			if (board[i][0] == 'O') {
				changeToM(board, i, 0);
			}
			if (board[i][cols - 1] == 'O') {
				changeToM(board, i, cols - 1);
			}
		}

		lastChange(board);

	}

	void lastChange(vector<vector<char>> &board) {
		for (int i = 0; i<rows; i++) {
			for (int j = 0; j<cols; j++) {
				if (board[i][j] == 'M') {
					board[i][j] = 'O';
				}
				else if (board[i][j] == 'O') {
					board[i][j] = 'X';
				}
			}
		}
	}
	void changeToM(vector<vector<char>> &board, int r, int c) {
		queue<pair<int, int>>q;
		q.emplace(r, c);
		board[r][c] = 'M';
		while (!q.empty()) {
			r = q.front().first, c = q.front().second;
			q.pop();
			if (c > 0 && board[r][c - 1] == 'O') {   // left
				q.emplace(r, c - 1);
				board[r][c-1] = 'M';
			}
			if (c < cols - 1 && board[r][c + 1] == 'O') {  // right
				q.emplace(r, c + 1);
				board[r][c+1] = 'M';
			}
			if (r >0 && board[r - 1][c] == 'O') {   //up
				q.emplace(r - 1, c);
				board[r-1][c] = 'M';
			}
			if (r < rows - 1 && board[r + 1][c] == 'O') {   //down
				q.emplace(r + 1, c);
				board[r+1][c] = 'M';
			}
		}
	}
private:
	int rows, cols;
};