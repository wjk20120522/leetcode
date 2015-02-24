/*
short code
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool rows[10][10], cols[10][10], blocks[10][10];
        // use memset use less time than use vector !!!
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(rows));
        memset(blocks, 0, sizeof(rows));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    if (rows[i][num] || cols[j][num] || blocks[i / 3 * 3 + j / 3][num]) return false;
                    rows[i][num] = cols[j][num] = blocks[i / 3 * 3 + j / 3][num] = true;
                }
            }
        }
        return true;
    }
};


/**
 * clear code
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
