class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows <=0 ) return;
        int cols = board[0].size();
        queue<pair<int,int>> q,p;
        // up, down
        for(int i=0; i<cols; i++) {
            if(board[0][i] == 'O') q.push(make_pair(0,i));
            if(board[rows-1][i] == 'O') q.push(make_pair(rows-1,i));
        }
        // left, right
        for(int i=0; i<rows; i++) {
            if(board[i][0] == 'O') q.push(make_pair(i, 0));
            if(board[i][cols-1] == 'O') q.push(make_pair(i,cols-1));
        }
        spread(q,p, board);
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if(board[i][j] == 'S') {
                    board[i][j] = 'O';
                }
            }
        }

    }

private:

    void spread(queue<pair<int,int>> &q, queue<pair<int,int>>& p, vector<vector<char>>& board) {
        while (!q.empty()) {
            pair<int,int> mp;
            while(!q.empty()) {
                mp = q.front(); q.pop();
                int row = mp.first, col = mp.second;
                board[row][col] = 'S';
                if(row > 0 && board[row-1][col] == 'O') p.push(make_pair(row-1, col));  
                if(row < board.size()-1 && board[row+1][col] == 'O') p.push(make_pair(row+1, col));
                if(col > 0 && board[row][col-1] == 'O') p.push(make_pair(row, col-1));
                if(col < board[0].size()-1 && board[row][col+1] == 'O') p.push(make_pair(row, col+1));
            }
            q.swap(p);
        }
    }
};