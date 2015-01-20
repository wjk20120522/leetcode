class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int m = board.size();
        if(m != 9) return false;
        int n= board[0].size();
        if(n != 9) return false;
        
        int count = 0;
        for(int i=0; i<9; i++)
        {
            count = 0;
            for(int j=0; j<9; j++)
            {
                if(board[i][j] != '.')
                {
                    if( (count >> board[i][j]) & 1)
                    {
                        return false;
                    }
                    count |= (1 << board[i][j]);
                }
            }
        }
        
        for(int j=0; j<9; j++)
        {
            count = 0;
            for(int i=0; i<9; i++)
            {
                if(board[i][j] != '.')
                {
                    if( (count >> board[i][j]) & 1)
                    {
                        return false;
                    }
                    count |= (1 << board[i][j]);
                }
            }
        }
        
        int blockSize = 3;
        for(int i=0; i< blockSize; i++)
        {
            for(int j=0; j<blockSize; j++)
            {
                count = 0;
                for(int first = i*blockSize; first < (i+1)*blockSize; first ++)
                {
                    for(int second = j*blockSize; second < (j+1)*blockSize; second++)
                    {
                        if(board[first][second] != '.')
                        {
                            if( (count >> board[first][second]) & 1)
                            {
                                return false;
                            }
                            count |= (1 << board[first][second]);
                        }
                    }
                }
            }
        }
        
        return true;    
    }
};

/**
 * 思路更为明确点的解法，摘自陈浩
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        const int cnt = 9;
        bool row_mask[cnt][cnt] = {false};
        bool col_mask[cnt][cnt] = {false};
        bool area_mask[cnt][cnt] = {false};
        //check each rows and cols
        for(int r=0; r<board.size(); r++){
            for (int c=0; c<board[r].size(); c++){
                if (!isdigit(board[r][c])) continue;
                int idx =  board[r][c] - '0' - 1;
                
                //check the rows
                if (row_mask[r][idx] == true){
                    return false;
                }
                row_mask[r][idx] = true;
                
                //check the cols
                if (col_mask[c][idx] == true) {
                    return false;
                }
                col_mask[c][idx] = true;
                
                //check the areas
                int area = (r/3) * 3 + (c/3);
                if (area_mask[area][idx] == true) {
                    return false;
                }
                area_mask[area][idx] = true;
            }
        }
        
        return true;
    }
};
